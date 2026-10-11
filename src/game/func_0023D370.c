#include "r03_types.h"

extern f32 D_800D0640[];
void func_002720EC(R3V3 *v);
void func_00272038(R3V3 *out, f32 t, R3V3 *a, R3V3 *b);
void func_0027200C(R3V3 *out, R3V3 *in, f32 s);
void func_002721F0(R3V3 *out, R3V3 *in, R3V3 *n, f32 x);
void func_00272284(R3V3 *out, R3V3 *a, R3V3 *b);
void func_0027246C(R3V3 *out, R3V3 *a, R3V3 *b);
void func_00271FA4(R3V3 *out, R3V3 *a, R3V3 *b);
void func_0023EC44(R3Mv *m, s32 *st);

s32 func_0023D370(R3Mv *m0) {
    R3Mv *m = m0;
    R3V3 v10;
    R3V3 v20;
    R3V3 v30;
    R3V3 v40;
    R3V3 v50;
    R3V3 v60;
    R3V3 v70;
    R3Def *d;
    f32 mx, dy, one, zero;
    register f32 fv0 asm("$f0");
    s32 i, s5, n;
    R3V3 *pa0, *pa1;
    register R3V3 * pv asm("$16");
    register R3V3 * pva asm("$17");
    register R3V3 * pn asm("$18");
    R3V3 *pz;
    register R3V3 * ra0 asm("$4");
    register R3V3 * ra1 asm("$5");
    register R3V3 * q2 asm("$18");
    register R3V3 * q1 asm("$19");
    register R3V3 * q2b asm("$17");

    d = m->def;
    if (m->st != 0) {
    func_002720EC(&m->nrm);
    fv0 = D_800D0640[1] * 10.24f;
    m->va = m->v50;
    m->vb = m->v74;
    if (fv0 <= m->f80) {
        if (m->phase != 7) {
            m->t = m->t - fv0 / m->f80;
            func_00272038(&m->hit, m->t, &m->v44, &m->v50);
        }
    }
    if (m->w24 != 0 && m->st == 3) {
        mx = m->vv[0].y;
        for (i = 1; i < m->cnt; i++) {
            fv0 = m->vv[i].y;
            if (!(mx <= fv0)) {
                fv0 = mx;
            }
            mx = fv0;
        }
        dy = mx - m->v44.y;
        if (0.0f < dy && dy <= 30.72f) {
            m->hit = m->v44;
            m->va = m->v50;
            m->vb = m->v74;
            dy += 0.2048f;
            m->t = 0.0f;
            m->hit.y += dy;
            m->va.y += dy;
            return 1;
        }
    }
    if (m->phase == 6) {
        if (m->w24 == 0) {
            m->phase = 3;
        } else {
            m->phase = 2;
        }
    }
    if (m->phase == 3) {
        if (d->fC < 1.0f && m->f80 < 4.096f) {
            fv0 = m->v5C.x * m->v5C.x;
            fv0 = fv0 + m->v5C.z * m->v5C.z;
            m->phase = (fv0 < 1.0485761f) ? 1 : 2;
        }
    }
    if (m->st >= 3) goto el;
    if (m->st <= 0) goto el;
    if (m->w34 != 0) {
        m->w34 = m->w34 - 1;
        goto cont;
    }
    goto clr;
el:
    if (m->w30 != 0) {
        m->w30 = m->w30 - 1;
    }
cont:
    if (m->w34 == 0) {
clr:
        *(s32 *)&m->v5C.y = 0;
    }
    s5 = 0;
    if (m->w30 == 0) {
        zero = 0.0f;
        pz = &m->v5C;
        pz->z = zero;
        pz->x = zero;
        __asm__ ("" : : : "memory");
        if (m->w30 != 0) {
            s5 = 1;
        } else if (m->w34 != 0) {
            s5 = 1;
        }
    } else {
        s5 = 1;
    }
    switch (m->phase) {
    case 7:
        if (m->w2C != 0) {
            m->vb = m->v74;
        }
        if (s5 != 0) {
            m->va = m->v50;
        }
        if (m->w38 != 0) {
            if (m->st == 5) {
                m->flags3C ^= 0x1000;
                func_0023EC44(m, &m->st);
            }
            if (m->st != 6) {
                return 1;
            }
            m->flags3C ^= 0x4000;
            func_0023EC44(m, &m->st);
        }
        return 1;
    case 1:
    case 8:
        if (m->w2C != 0) {
            m->vb.x = 0;
            m->vb.y = 0;
            m->vb.z = 0;
        }
        if (s5 != 0) {
            m->va = m->hit;
        }
        return 0;
    case 3:
        if (m->w2C != 0) {
            func_002721F0(&v70, &m->v74, &m->nrm, d->fC);
            m->vb = v70;
            func_0027200C(&m->vb, &m->vb, 1.0f - m->fB4);
        }
        if (s5 == 0) {
            return 1;
        }
        fv0 = m->t;
        one = 1.0f;
        func_0027200C(&v10, &m->v5C, one - fv0);
        pv = &v20;
        func_002721F0(pv, &v10, &m->nrm, d->fC);
        func_0027200C(pv, pv, one - m->fB4);
        pa0 = &m->va;
        pa1 = &m->hit;
        goto call54;
    case 2:
        if (m->w2C != 0) {
            func_00272284(&v70, &m->v74, &m->nrm);
            m->vb = v70;
            func_0027200C(&m->vb, &m->vb, 1.0f - m->fB4);
        }
        if (s5 == 0) {
            return 1;
        }
        fv0 = m->t;
        one = 1.0f;
        func_0027200C(&v10, &m->v5C, one - fv0);
        pv = &v30;
        ra0 = pv;
        ra1 = &v10;
        __asm__ volatile ("" : : "r"(ra0), "r"(ra1));
        pn = &m->nrm;
        func_00272284(ra0, ra1, pn);
        goto tail1;
    case 4:
        if (m->w2C != 0) {
            func_0027246C(&v70, &m->v74, &m->nrm);
            m->vb = v70;
        }
        if (s5 == 0) {
            return 1;
        }
        func_0027200C(&v10, &m->v5C, 1.0f - m->t);
        pv = &v30;
        ra0 = pv;
        ra1 = &v10;
        __asm__ volatile ("" : : "r"(ra0), "r"(ra1));
        pn = &m->nrm;
        func_0027246C(ra0, ra1, pn);
        pva = &m->va;
        goto tail2;
    case 5:
        if (m->w2C != 0) {
            q1 = &v40;
            func_00272284(q1, &m->v74, &m->nrm);
            q2 = &v50;
            func_0027246C(q2, &m->v74, &m->nrm);
            func_00272038(&m->vb, 0.25f, q1, q2);
            func_0027200C(&m->vb, &m->vb, 1.0f - m->fB4);
        }
        if (s5 == 0) {
            return 1;
        }
        fv0 = m->t;
        one = 1.0f;
        func_0027200C(&v10, &m->v5C, one - fv0);
        q1 = &v40;
        ra0 = q1;
        ra1 = &v10;
        __asm__ volatile ("" : : "r"(ra0), "r"(ra1));
        pn = &m->nrm;
        func_00272284(ra0, ra1, pn);
        q2b = &v50;
        func_0027246C(q2b, &v10, pn);
        pv = &v30;
        func_00272038(pv, 0.25f, q1, q2b);
        goto tail1;
    default:
        return 0;
    }
tail1:
    func_0027200C(pv, pv, one - m->fB4);
    pva = &m->va;
tail2:
    func_00271FA4(pva, &m->hit, pv);
    pv = &v60;
    func_0027200C(pv, pn, D_800D0640[0] * 10.24f);
    pa0 = pva;
    pa1 = pva;
call54:
    func_00271FA4(pa0, pa1, pv);
    return 1;
    }
    return 0;
}
