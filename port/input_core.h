/* input_core.h - platform independent part of the port's input system (no windows.h in here).
 *
 *   - the N64 controller model, the binding "sources" (keyboard key, mouse button / wheel / axis, gamepad button / axis / hat) and their text names
 *   - the controls.ini parser and writer, the built-in profiles and the defaults
 *   - the mapping engine: raw device state of one player -> N64 buttons + analog stick (a pure function, unit tested in port\config\input_test.c)
 *
 * Shared by the game (port\input.c, port\input_dev.c) and the mapping tool (port\config\).  Plain C so that both the C and the C++ translation
 * units of the port can use it.  Documentation of the file format: docs\PORT_STATUS.md ("Input") and the header the writer puts into controls.ini. */
#ifndef INPUT_CORE_H
#define INPUT_CORE_H
#ifdef __cplusplus
extern "C" {
#endif

/* ---- the N64 controller ---- */
#define N64_BTN_A      0x8000
#define N64_BTN_B      0x4000
#define N64_BTN_Z      0x2000
#define N64_BTN_START  0x1000
#define N64_BTN_DUP    0x0800
#define N64_BTN_DDOWN  0x0400
#define N64_BTN_DLEFT  0x0200
#define N64_BTN_DRIGHT 0x0100
#define N64_BTN_L      0x0020
#define N64_BTN_R      0x0010
#define N64_BTN_CUP    0x0008
#define N64_BTN_CDOWN  0x0004
#define N64_BTN_CLEFT  0x0002
#define N64_BTN_CRIGHT 0x0001
#define N64_STICK_MAX  80          /* a real stick reports about +-80 at the gate; the game clamps to it */
#define GAME_STICK_DEADZONE 3      /* the game's own dead zone (func_00263E1C): |v| <= 3 reads as 0, otherwise 3 is subtracted */

/* binding targets: the 14 buttons and the four directions of the analog stick */
enum { IN_A, IN_B, IN_Z, IN_START, IN_DUP, IN_DDOWN, IN_DLEFT, IN_DRIGHT, IN_L, IN_R, IN_CUP, IN_CDOWN, IN_CLEFT, IN_CRIGHT,
       IN_STICK_LEFT, IN_STICK_RIGHT, IN_STICK_UP, IN_STICK_DOWN, IN_COUNT };
#define IN_BUTTONS 14
const char *in_name(int in);                       /* "A", "B", "Z", "Start", "DUp", ..., "StickLeft" */
int in_from_name(const char *name);                /* case-insensitive, -1 when unknown */
unsigned in_button_mask(int in);                   /* IN_A..IN_CRIGHT -> N64_BTN_*, 0 for the stick directions */

typedef struct N64Pad { unsigned short buttons; signed char x, y; } N64Pad;

/* ---- gamepad model (the device layer translates XInput / DirectInput devices into this) ---- */
enum { PB_A, PB_B, PB_X, PB_Y, PB_LB, PB_RB, PB_BACK, PB_START, PB_LS, PB_RS, PB_DUP, PB_DDOWN, PB_DLEFT, PB_DRIGHT, PB_GUIDE, PB_COUNT };
enum { PA_LX, PA_LY, PA_RX, PA_RY, PA_LT, PA_RT, PA_COUNT };      /* sticks -1..1 (up and right are positive), triggers 0..1 */
#define RAW_BUTTONS 128
#define RAW_AXES 8
#define RAW_HATS 4
typedef struct PadState {
    int connected;
    unsigned buttons;                      /* bit PB_* (standard layout) */
    float axis[PA_COUNT];
    unsigned raw_buttons[RAW_BUTTONS / 32];/* DirectInput devices: the physical buttons, bit n = button n+1 */
    float raw_axis[RAW_AXES];              /* DirectInput devices: X Y Z Rx Ry Rz slider0 slider1, -1..1 (raw direction: Y is positive downwards) */
    signed char hat[RAW_HATS];             /* -1 = centred, else 0..7 clockwise from up */
} PadState;
const char *pad_button_name(int pb);       /* "A", "B", "X", "Y", "LB", ... */
const char *pad_axis_name(int pa);         /* "LX", "LY", "RX", "RY", "LT", "RT" */

/* ---- binding sources ---- */
enum { SRC_NONE = 0, SRC_KEY, SRC_MBTN, SRC_WHEEL, SRC_MAXIS, SRC_PBTN, SRC_PAXIS, SRC_PHAT };
enum { CTX_ANY = 0, CTX_GAME = 1, CTX_MENU = 2 };    /* a source can be limited to free play or to menus / pause / intermissions */
typedef struct Source {
    unsigned char type;      /* SRC_* */
    unsigned char ctx;       /* CTX_* */
    signed char sign;        /* axes: +1 / -1; hats: direction 0 up, 1 right, 2 down, 3 left; otherwise 0 */
    unsigned short id;       /* SRC_KEY: (extended << 7) | scancode.  MBTN: 0..4.  WHEEL: 0 up, 1 down, 2 left, 3 right.  MAXIS: 0 x, 1 y.
                                PBTN: PB_* or 32 + n (raw button n+1).  PAXIS: PA_* or 8 + n (raw axis n+1).  PHAT: hat index */
} Source;
#define MAX_SRC 12
typedef struct Binding { int n; Source s[MAX_SRC]; } Binding;

int  src_parse(const char *text, Source *out);                     /* 1 when text is a valid source ("W", "menu:Mouse1", "Pad.LX-", ...) */
int  src_format(const Source *s, char *buf, int cap);              /* canonical text, round-trips through src_parse */
int  src_describe(const Source *s, char *buf, int cap);            /* friendly text for the GUI: "Key W", "Mouse Left", "Pad A", "Pad Left stick left" */
int  src_equal(const Source *a, const Source *b);                  /* same physical input (contexts ignored) */
int  src_ctx_overlap(const Source *a, const Source *b);
int  key_id_from_name(const char *name);                           /* -1 when unknown */
const char *key_name(int id);                                      /* NULL when the id has no name */
int  key_count(void);
int  key_id_at(int index);                                         /* enumerate the named keys */

/* a source is either family: keyboard + mouse, or gamepad */
#define FAM_KBM 1
#define FAM_PAD 2
int  src_family(const Source *s);

/* ---- configuration ---- */
#define MAX_PLAYERS 4
#define MAX_PADS_PER_PLAYER 2
enum { PS_AUTO = 0, PS_XINPUT, PS_DI_INDEX, PS_DI_GUID, PS_DI_NAME };
typedef struct PadSpec { int kind; int index; char text[64]; } PadSpec;    /* PS_XINPUT: index 0..3.  PS_DI_INDEX: index 1.. */
enum { MC_AUTO = 0, MC_CLICK, MC_OFF };
enum { ESC_CONFIRM = 0, ESC_QUIT, ESC_IGNORE };

typedef struct PlayerCfg {
    int use_keyboard, use_mouse;
    int npads; PadSpec pad[MAX_PADS_PER_PLAYER];
    Binding bind[IN_COUNT];
    float mouse_sens_x, mouse_sens_y;      /* 1.0 = 0.05 degrees of turn per mouse count */
    float mouse_backlog;                   /* degrees of motion that may be queued while the game turns at its maximum speed (the rest is dropped) */
    float mouse_smooth;                    /* 0 = off, up to 0.9 */
    int   mouse_invert_y;
    float stick_deadzone;                  /* radial, 0..0.9 */
    float stick_sens_x, stick_sens_y;      /* scale of the pad stick -> N64 stick */
    float stick_curve;                     /* response exponent, 1 = linear, 2 = finer around the centre */
    int   stick_invert_y;
    float trigger_threshold;               /* trigger value that counts as a pressed button */
    float axis_threshold;                  /* stick deflection (after the dead zone) that counts as a pressed button */
    int   key_stick;                       /* stick units a key bound to a stick direction gives (1..80) */
} PlayerCfg;

typedef struct ControlsCfg {
    int version;
    int mouse_capture;                     /* MC_* */
    int esc_mode;                          /* ESC_* */
    int rumble; float rumble_strength;
    int background_input;                  /* read devices while the window is not focused */
    int hot_reload;                        /* re-read the file when it changes */
    int mouse_menu_guard;                  /* mouse motion only moves the stick during free play */
    int show_status;                       /* short notices in the window title */
    int native_controls;                   /* free play: the mouse turns / tilts the view and the C buttons move the player directly (port/overrides/func_002231B0.c, func_002631D0.c), whatever the game's own control style */
    PlayerCfg player[MAX_PLAYERS];
} ControlsCfg;

int  padspec_parse(const char *text, PadSpec *out);                /* "pad:auto", "xinput:2", "dinput:3", "dinput:{guid}", "dinput:name=Wireless Controller" */
int  padspec_format(const PadSpec *p, char *buf, int cap);

typedef void (*CfgLogFn)(void *user, int line, const char *msg);

void cfg_defaults(ControlsCfg *c);                                  /* player 1 keyboard+mouse+first pad, players 2-4 one pad each */
void cfg_player_defaults(PlayerCfg *p, int index);                  /* built-in default of player slot 0..3 */
void cfg_player_clear_bindings(PlayerCfg *p);
int  cfg_parse(ControlsCfg *c, const char *text, int len, CfgLogFn log, void *user);   /* 0 = ok (bad lines only warn), -1 = unusable file (c = defaults) */
int  cfg_load(ControlsCfg *c, const char *path, CfgLogFn log, void *user);             /* 0 ok, -1 unusable, -2 cannot read */
int  cfg_write(const ControlsCfg *c, char *buf, int cap);                              /* text of the whole file; length, or -1 when buf is too small */
int  cfg_save(const ControlsCfg *c, const char *path);                                 /* 0 ok */
int  cfg_equal(const ControlsCfg *a, const ControlsCfg *b);

/* built-in profiles: presets of bindings (one family each: keyboard/mouse or gamepad) */
int  cfg_profile_count(void);
const char *cfg_profile_name(int i);                                /* "kbm_fps", "kb_left", "kb_right", "xbox", "xbox_n64", "generic" */
const char *cfg_profile_title(int i);
int  cfg_profile_family(int i);
int  cfg_profile_find(const char *name);
/* mode 0: replace the player's bindings of the profile's family; mode 1: merge (append the profile's sources) */
int  cfg_apply_profile(PlayerCfg *p, const char *name, int mode);
void cfg_copy_player(PlayerCfg *dst, const PlayerCfg *src, int bindings_only);

/* sources bound to two different inputs of one player (with overlapping contexts) */
typedef struct Conflict { int in_a, in_b; Source src; } Conflict;
int  cfg_conflicts(const PlayerCfg *p, Conflict *out, int max);
/* the same keyboard key / mouse input used by two players that both have the keyboard (resp. mouse) */
typedef struct CrossConflict { int player_a, player_b, in_a, in_b; Source src; } CrossConflict;
int  cfg_cross_conflicts(const ControlsCfg *c, CrossConflict *out, int max);
int  binding_add(Binding *b, const Source *s);                      /* 1 added, 0 duplicate (same input and context), -1 no room left */
void binding_remove_family(Binding *b, int family);

/* ---- the mapping engine ---- */
typedef struct InputSample {
    const unsigned char *keys;             /* [256] physical key state, index = (extended << 7) | scancode; NULL = none */
    unsigned mouse_buttons;                /* bit n = Mouse(n+1) */
    float mouse_dx, mouse_dy;              /* counts since the previous sample (right and down are positive) */
    int   wheel[4];                        /* ticks since the previous sample: up, down, left, right */
    int   mouse_valid;                     /* 0 = the mouse is not captured: ignore motion */
    int   npad; const PadState *pad[MAX_PADS_PER_PLAYER];
    double dt;                             /* seconds since the previous sample of this player (0 = unknown) */
    int   gameplay;                        /* 1 free play, 0 menu / pause, -1 unknown (both context layers are active) */
} InputSample;

typedef struct MapState {
    float acc[2];                          /* mouse look: degrees of turn still to deliver (x = yaw, y = pitch) */
    float smooth[2];
    int   wheel_pend[4], wheel_on[4];
    int   mouse_out[2];                    /* the signed stick value the mouse contributed in the last sample (including the game's dead zone) */
    int   valid;
} MapState;

void map_reset(MapState *st);
void map_eval(const PlayerCfg *c, MapState *st, const InputSample *in, N64Pad *out);
/* activation of a single source for the "test area" of the GUI: 0..1 (the same arithmetic as map_eval, processed pad axes included) */
float map_source_level(const PlayerCfg *c, const MapState *st, const InputSample *in, const Source *s);
float map_pad_axis(const PlayerCfg *c, const PadState *pad, int axis);       /* processed (dead zone, curve, sensitivity) axis value, -1..1 */
/* "press the input" capture of the mapping tool: which gamepad source did the user just activate?  base = the state when the capture started, cur = now.
 * raw_names: a DirectInput pad of unknown layout is addressed by its physical numbers (Btn / Axis / Hat), everything else by the standard layout names. */
int  pad_detect_source(const PadState *base, const PadState *cur, int raw_names, Source *out);

/* Mouse look is delivered through the stick, so it has to follow the game's own response (measured in the level with scripted sticks, RAM dumps of the view matrix at
 * the default CONTROL STICK sliders): the turn rate is cubic in the stick value after the game's dead zone, e = |stick| - 3:  yaw  = 1.978e-4 * e^3 degrees per second
 * (e = 77 -> 90 deg/s), pitch = 3.10e-4 * e^3 (pitch is clamped to about +-48 degrees).  The mapping inverts that curve: the angle the mouse asked for in the last
 * poll interval becomes the stick value that turns the view by exactly that angle. */
#define GAME_YAW_RATE_PER_E3 1.978e-4f
#define GAME_PITCH_RATE_PER_E3 3.10e-4f
#define MOUSE_DEG_PER_COUNT 0.05f          /* degrees of turn per mouse count at mouse_sens 1.0 */

#ifdef __cplusplus
}
#endif
#endif
