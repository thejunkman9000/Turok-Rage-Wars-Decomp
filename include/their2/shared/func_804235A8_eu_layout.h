#ifndef RW_FUNC_804235A8_EU_LAYOUT_H
#define RW_FUNC_804235A8_EU_LAYOUT_H

#include "common/types_1dc8418c21db.h"
#include "types.h"
#include "types.h"
#include "common/types_1dc8418c21db.h"
typedef struct Shared_OptionsScreen Shared_OptionsScreen;
struct Shared_OptionsScreen {
    u32 unknown00[7];
    s32 cursor;
    MenuWidget *leftTab;
    s32 leftStep;
    MenuWidget *rightTab;
    s32 rightStep;
    s32 page;
    s32 pages;
    s32 title;
    MenuWidget *marker;
    MenuWidget *header;
    MenuWidget *footer;
    MenuWidget *pakIcon;
    MenuWidget *rumbleIcon;
    s32 slider;
    s32 firstList;
    s32 secondList;
    s32 state;
    s32 selection;
    s32 sound;
    MenuWidget *prompt;
};
typedef struct Shared_MenuReply Shared_MenuReply;
struct Shared_MenuReply {
    s32 value;
    s32 ready;
};
typedef struct Shared_MenuObject Shared_MenuObject;
struct Shared_MenuObject {
    u8 unknown00[0x17C1];
    u8 language;
    u8 unknown17C2[0x2E];
};
typedef struct Shared_MenuData Shared_MenuData;
struct Shared_MenuData {
    u32 unknown00[18];
    Shared_MenuObject object;
    s32 stage;
    u32 unknown183C[6];
    s32 pause;
};

#include "types.h"
#include "common/types_8a8189af7b05.h"
typedef void (*Shared_ContextCallback)(void *);
typedef void (*Shared_MenuVoidCallback)(void);
struct SharedTrackObject;
typedef struct Shared_MenuContext Shared_MenuContext;
struct Shared_MenuContext {
    void *owner;
    s32 resource;
    u32 unknown08;
    Shared_MenuVoidCallback onClose;
    Shared_MenuVoidCallback callback10;
    u32 unknown14;
    struct SharedTrackObject *target;
    f32 time;
    u32 unknown20[4];
    f32 start;
    f32 end;
    s32 active;
    s32 state3C;
    u32 unknown40;
    s32 initialized44;
    s32 closed;
    u32 unknown4C[5];
    u32 unknown60;
    u32 unknown64[4];
    u32 flags;
    u32 unknown78[26];
    s32 requestE0;
    Shared_ContextCallback callbackE4;
    Shared_MenuVoidCallback callbackE8;
    u32 unknownEC;
    Vec3 position;
    f32 yaw;
    u32 unknown100[6];
    char messages[5][0x28];
    s32 messageCount;
};


#endif
