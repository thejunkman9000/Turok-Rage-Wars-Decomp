#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80203F04.h"
#include "types.h"
/* Tests whether a viewer can see a target: raises both positions by their heights scaled by one half and casts
   a ray between them through func_802444A4_de into D_80103FD0, returning 1 when nothing or the target itself
   blocks it. */







extern Player **D_80103FCC;
extern char D_80103FD0[];
extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
extern f32 func_8024D284_de(Player *);
extern s32 func_802444A4_de(Player *, Vec3, Vec3, char *);

s32 func_80203F04_de(Player *player, Rider_func_80203F04_de *rider, Player *other) {
    Vec3 from;
    Vec3 to;
    f32 lift;
    s32 blocked;

    func_80271F68_de(&to, &other->pos, &player->pos);
    lift = 0.5f;
    from.x = rider->aim.x;
    from.y = rider->aim.y;
    from.z = rider->aim.z;
    from = player->pos;
    from.y += func_8024D284_de(player) * lift;
    to = other->pos;
    to.y += func_8024D284_de(other) * lift;
    blocked = func_802444A4_de(player, from, to, D_80103FD0);
    if (blocked != 0 && *D_80103FCC != other) {
        return 0;
    }
    return 1;
}
