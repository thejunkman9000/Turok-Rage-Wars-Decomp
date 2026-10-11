/* their2 */
#include "types.h"
#include "s1006_types.h"

/* Builds the in-memory surface mesh of a loaded resource: copies its four chunks into one fresh buffer
   (24-byte section header, vertices, faces widened from 0x14 to 0x20 bytes, trailing data), initialises
   the vertices, decodes every face through func_00275B14, lowers world->minY to the lowest vertex,
   sets the face attribute word from D_800D2B40 (also for faces that touch a 0x2000 neighbour) and
   marks the faces whose bit is set in the current group's bitmap with 0x400. */

extern s32 func_00285150(void ***handle, s32 arg1);
extern void *func_0028FD94(void *node, s32 index);
extern void *func_0028FDA8(void *node, s32 index, s32 *size);
extern void func_0028FDD8(void *node, s32 arg1);
extern void func_0028FEEC(void *src, void *dst, s32 flag);
extern void **func_00254420(s32 arg0, void ***handle, s32 size);
extern void func_00253CB0(s32 arg0, void ***handle, void **node);
extern void func_00275AC8(S6Vtx *v);
extern void func_00275B14(S6Face *dst, S6Packed *src, char *base, s32 nverts, char *extra, s32 nfaces);
extern s32 func_00245788(void);
extern s32 D_800D2B40;

static inline s32 sectionHas(S6World *world, s32 n) {
    s32 index;
    void *g;
    u8 *bits;
    s32 mask;

    index = world->group;
    g = func_0028FD94(func_0028FD94(func_0028FD94(world->tree, 0), index), 0);
    func_0028FD94(g, 0);
    func_0028FDD8(g, 1);
    bits = func_0028FD94(g, 1);
    mask = 1 << (n & 7);
    return bits[n / 8] & mask;
}

void func_0044D024(S6World *world, void ***handle) {
    s32 size0;
    s32 size1;
    s32 size3;
    void *node;
    void *chunk0;
    void *chunk1;
    void *chunk2;
    void *chunk3;
    s32 size2;
    s32 nfaces;
    s32 nverts;
    S6MeshHdr *hdr;
    u8 *buf;
    s32 off;
    u8 *dst1;
    u8 *dst2;
    S6Vtx *verts;
    S6Face *faces;
    void **blk;
    S6Face *face;
    S6Packed *src;
    s32 i;
    s32 j;
    f32 y;
    s32 tot;
    s32 k;

    if (func_00285150(handle, 1) != 0) {
        node = **handle;
        chunk0 = func_0028FDA8(node, 0, &size0);
        chunk1 = func_0028FDA8(node, 1, &size1);
        chunk2 = func_0028FD94(node, 2);
        nfaces = ((s32 *)chunk2)[1];
        chunk3 = func_0028FDA8(node, 3, &size3);
        size2 = (nfaces << 5) | 8;
        tot = size1 + 0x18;
        blk = func_00254420(0, handle, size0 + tot + size2 + size3);
        if (blk != 0) {
            buf = (u8 *)*blk;
            hdr = (S6MeshHdr *)buf;
            hdr->cur = 0;
            off = 0x18;
            hdr->off[0] = off;
            func_0028FEEC(chunk0, buf + off, 0);
            hdr->cur = 1;
            off = size0 + off;
            dst1 = buf + off;
            hdr->off[1] = off;
            func_0028FEEC(chunk1, dst1, 0);
            hdr->cur = 2;
            off = off + size1;
            dst2 = buf + off;
            hdr->off[2] = off;
            func_0028FEEC(chunk2, dst2, 1);
            src = (S6Packed *)((u8 *)chunk2 + 8);
            ((s32 *)dst2)[0] = 0x20;
            ((s32 *)dst2)[1] = nfaces;
            faces = (S6Face *)(dst2 + 8);
            nverts = ((s32 *)chunk1)[1];
            verts = (S6Vtx *)(dst1 + 8);
            for (j = 0; j < nverts; j++) {
                func_00275AC8(&verts[j]);
            }
            for (i = 0; i < nfaces; i++) {
                face = &faces[i];
                func_00275B14(face, &src[i], (char *)verts, nverts, (char *)faces, nfaces);
                for (j = 0; j < 3; j++) {
                    y = face->vtx[j]->y;
                    if (!(y <= world->minY)) {
                        y = world->minY;
                    }
                    world->minY = y;
                }
                if (sectionHas(world, i)) {
                    face->flags |= 0x400;
                }
                if (!(face->attr & D_800D2B40)) {
                    face->attr = D_800D2B40;
                }
                if (func_00245788() != 0) {
                    face->attr = D_800D2B40;
                }
                if (face->flags & 0x2000) {
                    face->attr = D_800D2B40;
                }
            }
            for (i = 0; i < nfaces; i++) {
                face = &faces[i];
                for (k = 0; k < 3; k++) {
                    if (face->adj[k] != 0 && (face->adj[k]->flags & 0x2000)) {
                        /* store through a plain word pointer (not a struct member): loop.c then keeps the
                           D_800D2B40 load inside the branch instead of hoisting it out of the loop */
                        s32 *attr = &face->attr;

                        *attr = D_800D2B40;
                    }
                }
            }
            off = off + size2;
            hdr->cur = 3;
            hdr->off[3] = off;
            func_0028FEEC(chunk3, buf + off, 0);
            hdr->cur = 4;
            off = off + size3;
            hdr->off[4] = off;
        }
        func_00253CB0(0, handle, blk);
    }
}
