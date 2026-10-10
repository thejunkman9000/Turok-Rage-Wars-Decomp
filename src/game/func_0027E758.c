#include "span_1000/code_8027A0F4.h"
#include "abi.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8027A0F4.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "math_helpers.h"

/* Draws an actor's ground shadow: probes the ground under the actor through func_80243A90_de into D_801041F0, and when ground is found tilts the shadow model from D_8011FFB0 to the ground normal, scales it by the actor's size shrinking with height above the ground, fades it with height (and with lost health for actors flagged 1), places it on the ground and draws it through func_8026992C_de between render-mode commands. */
extern char D_8011FFB0;
extern char D_80100030;
extern Ground D_801041F0;
extern f32 D_80115DEC;
extern Gfx *D_80110634;
extern void *func_802799C0_de(void *, s32);
extern s32 func_80243A90_de(Instance_func_8027E784_de *, Vec3, void *);
extern void func_80271818_de(Vector4f *, Vec3 *);


extern void func_80274098_de(Vector4f *out, Vector4f *a, Vector4f *b);
extern s32 func_8027254C_de(Vec3 *, f32);
extern void func_80274244_de(Vector4f *, f32 *);
extern void func_8027347C_de(f32 *, f32, f32, f32);
extern void func_80273448_de(f32 *, f32, f32, f32);
extern void func_8027027C_de(f32 *, void *);
extern void func_8026992C_de(void *model, s32 pass, u8 alpha);

void func_8027E784_de(Actor_func_8027E784_de *actor) {
    f32 matrix[16];
    Vec3 point;
    Vector4f rotation;
    Vector4f tilt;
    Vector4f roll;
    Instance_func_8027E784_de probe;
    void *model;
    Ground *ground;
    f32 angle;
    f32 height;
    f32 alpha;
    f32 size;
    f32 health;
    f32 floor;
    f32 shrink;

    model = func_802799C0_de(&D_8011FFB0, 1);
    if (model == 0) {
        return;
    }
    probe = actor->instance;
    probe.velocity.x = 0.0f;
    probe.velocity.y = 0.0f;
    probe.velocity.z = 0.0f;
    probe.position.y += 10.24f;
    point.x = probe.position.x;
    point.y = probe.position.y - 102400.0f;
    point.z = probe.position.z;
    func_80243A90_de(&probe, point, &D_80100030);
    ground = &D_801041F0;
    if (ground->found == 0) {
        return;
    }
    angle = 0.78539824f;
    func_80271818_de(&tilt, &ground->normal);
    roll.x = D_80115DEC = func_802B7130_de(angle);
    roll.y = 0.0f;
    roll.z = 0.0f;
    roll.w = func_802B6560_de(angle);
    func_80274098_de(&rotation, &roll, &tilt);
    floor = ground->height;
    height = actor->instance.position.y - floor;
    alpha = ((RW_MIN(200.0f - height * 0.30517578f, 255.0f)) < (0.0f) ? (0.0f) : (RW_MIN(200.0f - height * 0.30517578f, 255.0f)));
    size = actor->radius * 7.68f;
    if (actor->def->large != 0) {
        size *= 8.0f;
    }
    size *= actor->def->size->unk18;
    shrink = height * 0.1f;
    size = ((({ f32 _m = (size - shrink); if (!(_m <= (size))) _m = (size); _m; })) < (0.0f) ? (0.0f) : (({ f32 _m = (size - shrink); if (!(_m <= (size))) _m = (size); _m; })));
    if (actor->def->flags & 1) {
        health = actor->health;
        if (0.0f < health) {
            alpha *= (health - actor->damage) / health;
        }
    }
    point.x = actor->instance.position.x;
    point.z = actor->instance.position.z;
    point.y = floor;
    func_8027254C_de(&point, 20000.0f);
    func_80274244_de(&rotation, matrix);
    func_8027347C_de(matrix, size, 1.0f, size);
    func_80273448_de(matrix, point.x, point.y, point.z);
    func_8027027C_de(matrix, model);
    {
        Gfx *cmd = D_80110634++;
        gDPPipeSync(cmd);
        cmd = D_80110634++;
        gDPSetCycleType(cmd, G_CYC_2CYCLE);
    }
    func_8026992C_de(model, 1, (u32)alpha);
    {
        Gfx *cmd = D_80110634++;
        gDPPipeSync(cmd);
        cmd = D_80110634++;
        gDPSetCycleType(cmd, G_CYC_1CYCLE);
    }
}
