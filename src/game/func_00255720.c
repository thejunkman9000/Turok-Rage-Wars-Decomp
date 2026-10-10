#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80254CE4.h"
#include "types.h"

/* Coalesces every block that physically follows a pool's anchor block at 0x10 into its physical
   predecessor: first puts an empty predecessor on the free list (after the next non-empty block, or
   at the head), then grows it by the block's header and size, unlinks the block from the physical
   chain and, when it was free, from the free list. Written like func_80255B2C_de, which absorbs one block. */







void func_80255780_de(Pool80255720 *arg0)
{
    Block80255720 *block;
    Block80255720 *header;
    Block80255720 *other;
    Block80255720 *scan;
    Block80255720 *next;

    while (arg0->anchor->next_phys != 0) {
        header = arg0->anchor->next_phys;
        block = header->prev_phys;
        if (block->size == 0) {
            other = header->prev;
            if (other != 0) {
                block->prev = other;
            } else {
                scan = block;
                while (scan != 0) {
                    if (scan->size != 0) {
                        break;
                    }
                    scan = scan->prev_phys;
                }
                if (scan != 0) {
                    block->prev = scan;
                } else {
                    goto insert_head;
                }
                other = scan;
            }
            next = other->next;
            block->next = next;
            if (other->next != 0) {
                next->prev = block;
            }
            other->next = block;
            if (arg0->tail == other) {
                arg0->tail = block;
            }
            goto merge;
insert_head:
            block->next = arg0->head;
            if (arg0->head != 0) {
                arg0->head->prev = block;
            } else {
                arg0->tail = block;
            }
            arg0->head = block;
        }

merge:
        block->size += header->offset + header->size;
        if (header->next_phys != 0) {
            header->next_phys->prev_phys = header->prev_phys;
        }
        header->prev_phys->next_phys = header->next_phys;

        if (header->size != 0) {
            if (header->prev != 0) {
                header->prev->next = header->next;
            }
            if (header->next != 0) {
                header->next->prev = header->prev;
            }
            if (arg0->tail == header) {
                arg0->tail = header->prev;
            }
        }
    }
}

/* Initialises a heap over a memory range: records its start and unrounded end, places one free block at the
   first 16-byte boundary covering the rest rounded down to 16 bytes, less a 0x20-byte header, and
   points the free list at that block when it has room. */




void func_802558B4_de(struct Heap *heap, char *start, s32 size) {
    struct Block_func_802558B4_de *block;

    heap->start = start;
    heap->end = start + size;
    block = (struct Block_func_802558B4_de *) (((u32) start + 15) & ~15);
    size -= (char *) block - start;
    size &= ~15;
    block->previous = 0;
    block->next = 0;
    block->b = 0;
    block->a = 0;
    block->header = 0x20;
    block->size = size - 0x20;
    heap->first = block;
    if (block->size != 0) {
        heap->last = block;
        heap->free = block;
    } else {
        heap->last = 0;
        heap->free = 0;
    }
}

/* Allocates from a heap with a first-fit search of its free list: the request plus the 0x20-byte header is
 * rounded up to 16 bytes, a block after the found block's used part takes that size and inherits the
 * remaining free space in the free list (replacing the found block), the found block leaves the free list,
 * the new block is linked after it in address order, and its data pointer is returned (0 when nothing
 * fits). */








void *func_80255920_de(Heap_func_80255920_de *heap, s32 request) {
    Block_func_80255920_de *block;
    Block_func_80255920_de *split;
    u32 size;

    size = (request + 0x2F) & ~0xF;
    for (block = heap->head; block != 0; block = block->nextFree) {
        if (block->free >= size) {
            { u8 *cursor = (u8 *)block; cursor += block->size; split = (Block_func_80255920_de *)cursor; }
            split->size = size;
            split->free = block->free - size;
            if (split->free != 0) {
                split->prevFree = block;
                split->nextFree = block->nextFree;
                if (block->nextFree != 0) {
                    split->nextFree->prevFree = split;
                }
                block->nextFree = split;
                if (heap->tail == block) {
                    heap->tail = split;
                }
            } else {
                split->prevFree = 0;
                split->nextFree = 0;
            }
            block->free = 0;
            if (block->prevFree != 0) {
                block->prevFree->nextFree = block->nextFree;
            }
            if (block->nextFree != 0) {
                block->nextFree->prevFree = block->prevFree;
            }
            if (heap->head == block) {
                heap->head = block->nextFree;
            }
            if (heap->tail == block) {
                heap->tail = block->nextFree != 0 ? block->nextFree : block->prevFree;
            }
            block->prevFree = 0;
            block->nextFree = 0;
            split->prev = block;
            split->next = block->next;
            if (block->next != 0) {
                split->next->prev = split;
            }
            block->next = split;
            return &((func_802558C0_S1 *)(split))->unk20;
        }
    }
    return 0;
}

/* Allocates from the top of a heap's free space with a first-fit search of its free list: the request plus the 0x20-byte header is rounded up to 16 bytes and carved from the end of the found block's free space; the found block leaves the free list once its free space is used up, the new block is linked after it in address order, and its data pointer is returned (0 when nothing fits). */








void *func_80255A34_de(Heap_func_80255920_de *heap, s32 request)
{
    Block_func_80255920_de *block;
    Block_func_80255920_de *split;
    u32 size;

    size = (request + 0x2F) & ~0xF;
    for (block = heap->tail; block != 0; block = block->prevFree) {
        if (block->free >= size) {
            { u8 *cursor = (u8 *)block; cursor += block->size; cursor += block->free; cursor -= size; split = (Block_func_80255920_de *)cursor; }
            split->size = size;
            split->free = 0;
            block->free -= size;
            split->nextFree = 0;
            split->prevFree = 0;
            if (block->free == 0) {
                if (block->prevFree != 0) {
                    block->prevFree->nextFree = block->nextFree;
                }
                if (block->nextFree != 0) {
                    block->nextFree->prevFree = block->prevFree;
                }
                if (heap->head == block) {
                    heap->head = block->nextFree;
                }
                if (heap->tail == block) {
                    heap->tail = block->nextFree != 0 ? block->nextFree : block->prevFree;
                }
                block->prevFree = 0;
                block->nextFree = 0;
            }
            split->prev = block;
            split->next = block->next;
            if (block->next != 0) {
                split->next->prev = split;
            }
            block->next = split;
            return &((func_802558C0_S1 *)(split))->unk20;
        }
    }
    return 0;
}

s32 func_80255B2C_de(Pool80255ACC *arg0, char *arg1) {
    Block80255720 *block;
    Block80255720 *header;
    Block80255720 *other;
    Block80255720 *scan;
    u32 next;

    header = (Block80255720 *)(arg1 - 0x20);
    block = header->prev_phys;
    if (block->size == 0) {
        other = header->prev;
        if (other != 0) {
            block->prev = other;
        } else {
            scan = block;
            while (scan != 0) {
                if (scan->size != 0) {
                    break;
                }
                scan = scan->prev_phys;
            }
            if (scan != 0) {
                block->prev = scan;
            } else {
                goto insert_head;
            }
            other = scan;
        }
        next = (u32)other->next;
        block->next = (Block80255720 *)next;
        if (other->next != 0) {
            *(Block80255720 **)next = block;
        }
        other->next = block;
        if (arg0->tail == other) {
            arg0->tail = block;
        }
        goto merge;
insert_head:
        block->next = arg0->head;
        if (arg0->head != 0) {
            arg0->head->prev = block;
        } else {
            arg0->tail = block;
        }
        arg0->head = block;
    }

merge:
    block->size += header->offset + header->size;
    if (header->next_phys != 0) {
        header->next_phys->prev_phys = header->prev_phys;
    }
    header->prev_phys->next_phys = header->next_phys;

    if (header->size != 0) {
        if (header->prev != 0) {
            header->prev->next = header->next;
        }
        if (header->next != 0) {
            header->next->prev = header->prev;
        }
        if (arg0->tail == header) {
            arg0->tail = header->prev;
        }
    }
    return block->size - 0x20;
}
