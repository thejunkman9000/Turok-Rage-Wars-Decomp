/* input_test.c - unit tests of the input core (config parser / writer, names, defaults, mapping engine with fake device states).
 * Build + run: powershell port\build_config.ps1 -Test        (or turok_controls.exe --selftest, which calls the same code) */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../input_core.h"
#include "../input_dev.h"

static int g_fail, g_checks;
#define CHECK(cond) do { g_checks++; if (!(cond)) { g_fail++; printf("  FAIL %s:%d: %s\n", __FILE__, __LINE__, #cond); } } while (0)
#define CHECK_EQ(a, b) do { long _a = (long)(a), _b = (long)(b); g_checks++; if (_a != _b) { g_fail++; printf("  FAIL %s:%d: %s == %s (%ld vs %ld)\n", __FILE__, __LINE__, #a, #b, _a, _b); } } while (0)

static int g_nwarn; static char g_lastwarn[200];
static void warn_cb(void *u, int line, const char *msg) { (void)u; (void)line; g_nwarn++; strncpy(g_lastwarn, msg, sizeof g_lastwarn - 1); }

static unsigned char g_keys[256];
static void keys_clear(void) { memset(g_keys, 0, sizeof g_keys); }
static void key_down(const char *name) { int id = key_id_from_name(name); if (id >= 0) g_keys[id] = 1; else printf("  (test bug: unknown key %s)\n", name); }

static void sample_init(InputSample *in) { memset(in, 0, sizeof *in); in->keys = g_keys; in->dt = 1.0 / 60.0; in->gameplay = 1; in->mouse_valid = 1; }
static void pad_init(PadState *p) { memset(p, 0, sizeof *p); p->connected = 1; memset(p->hat, -1, sizeof p->hat); }

static N64Pad eval(const PlayerCfg *c, MapState *st, const InputSample *in) { N64Pad o; map_eval(c, st, in, &o); return o; }

static void test_names(void) {
    int i; char t[64]; Source s, s2;
    printf("names / sources\n");
    for (i = 0; i < IN_COUNT; i++) CHECK_EQ(in_from_name(in_name(i)), i);
    CHECK_EQ(in_from_name("c-up"), IN_CUP); CHECK_EQ(in_from_name("Stick Left"), IN_STICK_LEFT); CHECK_EQ(in_from_name("nope"), -1);
    for (i = 0; i < key_count(); i++) {
        int id = key_id_at(i); CHECK(key_name(id) != NULL);
        CHECK_EQ(key_id_from_name(key_name(id)), id);
        CHECK(src_parse(key_name(id), &s)); CHECK_EQ(s.type, SRC_KEY); CHECK_EQ(s.id, id);
        CHECK(src_format(&s, t, sizeof t) > 0); CHECK(src_parse(t, &s2) && src_equal(&s, &s2));
    }
    CHECK_EQ(key_id_from_name("w"), 0x11); CHECK_EQ(key_id_from_name("Return"), 0x1C); CHECK_EQ(key_id_from_name("Escape"), 0x01);
    CHECK_EQ(key_id_from_name("Up"), 0xC8); CHECK_EQ(key_id_from_name("Num8"), 0x48); CHECK(key_id_from_name("Up") != key_id_from_name("Num8"));
    {   /* every textual form round-trips */
        static const char *const forms[] = { "Mouse1", "Mouse5", "WheelUp", "WheelRight", "MouseX+", "MouseY-", "Pad.A", "Pad.Guide", "Pad.DLeft", "Pad.LX+", "Pad.LY-", "Pad.RX-", "Pad.RY+",
                                              "Pad.LT", "Pad.RT", "Pad.Btn1", "Pad.Btn128", "Pad.Axis1+", "Pad.Axis8-", "Pad.Hat1Up", "Pad.Hat4Left", "menu:Mouse1", "game:WheelDown", "menu:Pad.A", "game:W", "SC:E048", "SC:1E" };
        for (i = 0; i < (int)(sizeof forms / sizeof forms[0]); i++) {
            CHECK(src_parse(forms[i], &s)); CHECK(src_format(&s, t, sizeof t) > 0);
            if (strcmp(forms[i], "SC:E048") && strcmp(forms[i], "SC:1E")) CHECK(!_stricmp(t, forms[i]));
            CHECK(src_parse(t, &s2)); CHECK(src_equal(&s, &s2) && s.ctx == s2.ctx);
            CHECK(src_describe(&s, t, sizeof t) > 0);
        }
    }
    CHECK(!src_parse("", &s)); CHECK(!src_parse("Pad.Btn0", &s)); CHECK(!src_parse("Pad.Btn129", &s)); CHECK(!src_parse("Mouse6", &s)); CHECK(!src_parse("MouseX", &s));
    CHECK(!src_parse("Pad.Axis9+", &s)); CHECK(!src_parse("Pad.Hat5Up", &s)); CHECK(!src_parse("Bogus", &s)); CHECK(!src_parse("menu:", &s));
    CHECK(src_parse("lmb", &s) && s.type == SRC_MBTN && s.id == 0); CHECK(src_parse("  pad.lt+ ", &s) && s.type == SRC_PAXIS && s.id == PA_LT);
}

static void test_defaults_and_roundtrip(void) {
    ControlsCfg d, r; static char buf[32768]; int n, i; Conflict cf[32]; CrossConflict xc[8];
    printf("defaults / writer / parser round trip\n");
    cfg_defaults(&d);
    CHECK(d.player[0].use_keyboard && d.player[0].use_mouse && d.player[0].npads == 1 && d.player[0].pad[0].kind == PS_AUTO);
    for (i = 1; i < MAX_PLAYERS; i++) CHECK(!d.player[i].use_keyboard && !d.player[i].use_mouse && d.player[i].npads == 1);
    for (i = 0; i < MAX_PLAYERS; i++) CHECK_EQ(cfg_conflicts(&d.player[i], cf, 32), 0);
    CHECK_EQ(cfg_cross_conflicts(&d, xc, 8), 0);
    n = cfg_write(&d, buf, sizeof buf); CHECK(n > 1000);
    g_nwarn = 0; CHECK_EQ(cfg_parse(&r, buf, n, warn_cb, NULL), 0); CHECK_EQ(g_nwarn, 0); CHECK(cfg_equal(&d, &r));
    { static char buf2[32768]; int n2 = cfg_write(&r, buf2, sizeof buf2); CHECK_EQ(n, n2); CHECK(!memcmp(buf, buf2, n)); }
    CHECK_EQ(cfg_write(&d, buf, 100), -1);                                    /* too small */
    /* P1 default bindings spot checks */
    { const PlayerCfg *p = &d.player[0]; Source s;
      CHECK(src_parse("game:W", &s) && p->bind[IN_CUP].n == 2 /* game:W + Pad.LY+ (game) */);
      CHECK(p->bind[IN_STICK_LEFT].n >= 3);                                  /* Left, MouseX-, Pad.RX- */
      CHECK(p->bind[IN_Z].n >= 3); CHECK(p->bind[IN_START].n == 2); CHECK_EQ(p->bind[IN_A].n, 9); CHECK(p->bind[IN_A].n < MAX_SRC); }
    /* a player with the keyboard twice is a cross conflict */
    { ControlsCfg c2 = d; c2.player[1].use_keyboard = 1; c2.player[1].use_mouse = 0;
      CHECK(cfg_cross_conflicts(&c2, xc, 8) > 0);                             /* kb_right vs kbm_fps share the arrow keys */
      cfg_apply_profile(&c2.player[0], "kb_left", 0); cfg_apply_profile(&c2.player[1], "kb_right", 0);
      CHECK_EQ(cfg_cross_conflicts(&c2, xc, 8), 0); }                         /* the two split layouts do not overlap */
    /* profiles */
    CHECK_EQ(cfg_profile_count(), 6);
    for (i = 0; i < cfg_profile_count(); i++) { PlayerCfg p; int k; Conflict c2[8]; memset(&p, 0, sizeof p); cfg_apply_profile(&p, cfg_profile_name(i), 1);
        CHECK(cfg_profile_title(i) != NULL); CHECK_EQ(cfg_conflicts(&p, c2, 8), 0);
        for (k = 0; k < IN_COUNT; k++) CHECK(p.bind[k].n > 0); }
}

static void test_parser(void) {
    ControlsCfg c; int r; static char big[300000];
    printf("parser robustness\n");
    g_nwarn = 0; r = cfg_parse(&c, "", 0, warn_cb, NULL); CHECK_EQ(r, 0); { ControlsCfg d; cfg_defaults(&d); CHECK(cfg_equal(&c, &d)); }
    r = cfg_parse(&c, "; only a comment\n\n# another\n", 28, warn_cb, NULL); CHECK_EQ(r, 0);
    g_nwarn = 0; r = cfg_parse(&c, "this is not an ini file\nneither is this\n", 40, warn_cb, NULL); CHECK_EQ(r, -1); CHECK(g_nwarn > 0);
    { ControlsCfg d; cfg_defaults(&d); CHECK(cfg_equal(&c, &d)); }                                      /* unusable -> defaults */
    { char bin[64]; memset(bin, 'x', sizeof bin); bin[10] = 0; r = cfg_parse(&c, bin, sizeof bin, warn_cb, NULL); CHECK_EQ(r, -1); }
    memset(big, ' ', sizeof big); r = cfg_parse(&c, big, (int)sizeof big, warn_cb, NULL); CHECK_EQ(r, -1);
    { const char *t = "\xEF\xBB\xBF[general]\nmouse_capture = click ; comment\nrumble=off\nrumble_strength = 7\nesc = quit\n[player1]\nmouse_sens_x = 2.5\nstick_deadzone=5\nkey_stick = 40\n";
      g_nwarn = 0; r = cfg_parse(&c, t, (int)strlen(t), warn_cb, NULL); CHECK_EQ(r, 0);
      CHECK_EQ(c.mouse_capture, MC_CLICK); CHECK_EQ(c.rumble, 0); CHECK(fabsf(c.rumble_strength - 1.0f) < 1e-6f); CHECK_EQ(c.esc_mode, ESC_QUIT);
      CHECK(fabsf(c.player[0].mouse_sens_x - 2.5f) < 1e-6f); CHECK(fabsf(c.player[0].stick_deadzone - 0.9f) < 1e-6f); CHECK_EQ(c.player[0].key_stick, 40); }
    { const char *t = "[player2]\ndevices = keyboard, mouse, xinput:2, dinput:name=Wireless Controller\nA = Space, Mouse3 ; why not\nB += Q\nZ = none\nBogus = 3\nL = Q, Wibble\n[nosuch]\nx=1\n[player9]\n";
      g_nwarn = 0; r = cfg_parse(&c, t, (int)strlen(t), warn_cb, NULL); CHECK_EQ(r, 0); CHECK(g_nwarn >= 4);
      CHECK(c.player[1].use_keyboard && c.player[1].use_mouse); CHECK_EQ(c.player[1].npads, 2);
      CHECK_EQ(c.player[1].pad[0].kind, PS_XINPUT); CHECK_EQ(c.player[1].pad[0].index, 1); CHECK_EQ(c.player[1].pad[1].kind, PS_DI_NAME); CHECK(!strcmp(c.player[1].pad[1].text, "Wireless Controller"));
      CHECK_EQ(c.player[1].bind[IN_A].n, 2); CHECK_EQ(c.player[1].bind[IN_Z].n, 0);
      CHECK(c.player[1].bind[IN_B].n >= 2);                                                              /* += appended to the default */
      CHECK_EQ(c.player[1].bind[IN_L].n, 1); }                                                           /* the valid token of a half bad line is kept */
    { const char *t = "[player1]\ndevices = none\n[player3]\ndevices = pad:auto, pad:auto, pad:auto\n"; g_nwarn = 0; r = cfg_parse(&c, t, (int)strlen(t), warn_cb, NULL);
      CHECK_EQ(r, 0); CHECK(!c.player[0].use_keyboard && !c.player[0].use_mouse && c.player[0].npads == 0); CHECK_EQ(c.player[2].npads, 2); CHECK(g_nwarn >= 1); }
    { const char *t = "[player1]\nprofile = xbox_n64\nA = Pad.X\n"; r = cfg_parse(&c, t, (int)strlen(t), warn_cb, NULL); CHECK_EQ(r, 0);
      CHECK_EQ(c.player[0].bind[IN_A].n, 1); CHECK_EQ(c.player[0].bind[IN_CUP].n, 1); CHECK_EQ(c.player[0].bind[IN_CUP].s[0].id, PA_RY); }
    { const char *t = "[PLAYER1]\r\nDEVICES = Keyboard\r\na = e\r\n"; r = cfg_parse(&c, t, (int)strlen(t), warn_cb, NULL); CHECK_EQ(r, 0);
      CHECK(c.player[0].use_keyboard && !c.player[0].use_mouse && c.player[0].npads == 0); CHECK_EQ(c.player[0].bind[IN_A].n, 1); }
    { char line[2000]; int i; memset(line, 'a', sizeof line); strcpy(line, "[player1]\nA = "); for (i = 14; i < 1990; i++) line[i] = (i % 2) ? 'W' : ' ';
      line[1990] = '\n'; line[1991] = 0; r = cfg_parse(&c, line, (int)strlen(line), warn_cb, NULL); CHECK_EQ(r, 0); }          /* very long line does not crash */
    /* hand-written minimal files */
    { const char *t = "[player1]\ndevices = keyboard\n[player2]\ndevices = keyboard\nprofile = kb_right\n"; r = cfg_parse(&c, t, (int)strlen(t), warn_cb, NULL); CHECK_EQ(r, 0);
      CHECK(c.player[1].use_keyboard); CHECK(c.player[1].bind[IN_Z].n > 0); }
}

static void test_keyboard_mapping(void) {
    PlayerCfg p; MapState st; InputSample in; N64Pad o; ControlsCfg d;
    printf("mapping: keyboard\n");
    cfg_defaults(&d); p = d.player[0]; map_reset(&st); sample_init(&in);
    keys_clear(); o = eval(&p, &st, &in); CHECK_EQ(o.buttons, 0); CHECK_EQ(o.x, 0); CHECK_EQ(o.y, 0);
    key_down("W"); o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_CUP);                      /* game context: C-Up */
    in.gameplay = 0; o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_DUP);                    /* menu context: D-pad up */
    in.gameplay = -1; o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_CUP | N64_BTN_DUP);    /* unknown context: both layers */
    in.gameplay = 1; keys_clear(); key_down("A"); key_down("S"); key_down("D"); key_down("Space"); key_down("Enter"); key_down("E"); key_down("Q");
    o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_CLEFT | N64_BTN_CDOWN | N64_BTN_CRIGHT | N64_BTN_R | N64_BTN_START | N64_BTN_A | N64_BTN_L);
    keys_clear(); key_down("Left"); o = eval(&p, &st, &in); CHECK_EQ(o.x, -80); CHECK_EQ(o.y, 0); CHECK_EQ(o.buttons, 0);
    key_down("Up"); o = eval(&p, &st, &in); CHECK_EQ(o.x, -80); CHECK_EQ(o.y, 80);
    key_down("Right"); o = eval(&p, &st, &in); CHECK_EQ(o.x, 0);                                    /* opposite directions cancel */
    keys_clear(); key_down("Down"); key_down("Z"); key_down("X"); key_down("C"); o = eval(&p, &st, &in); CHECK_EQ(o.y, -80); CHECK_EQ(o.buttons, N64_BTN_Z | N64_BTN_B | N64_BTN_A);
    p.key_stick = 40; keys_clear(); key_down("Right"); o = eval(&p, &st, &in); CHECK_EQ(o.x, 40);
    p.use_keyboard = 0; o = eval(&p, &st, &in); CHECK_EQ(o.x, 0);                                    /* keyboard not assigned: keys ignored */
    /* left hand split layout */
    cfg_apply_profile(&p, "kb_left", 0); p.use_keyboard = 1; p.key_stick = 80; keys_clear(); key_down("Q"); key_down("F"); key_down("LShift");
    o = eval(&p, &st, &in); CHECK_EQ(o.x, -80); CHECK_EQ(o.y, -80); CHECK(o.buttons & N64_BTN_Z);
}

/* what the game turns by: degrees during dt for a delivered stick value x (x = n + the game's dead zone) */
static double turned(int x, double dt, double k) { int n = (x < 0 ? -x : x) - GAME_STICK_DEADZONE; double a = k * n * n * n * dt; return x < 0 ? -a : a; }
static void test_mouse_mapping(void) {
    PlayerCfg p; MapState st; InputSample in; N64Pad o; ControlsCfg d; int i, n; double sum, want;
    printf("mapping: mouse\n");
    cfg_defaults(&d); p = d.player[0]; map_reset(&st); sample_init(&in); keys_clear();
    in.mouse_dx = 10; o = eval(&p, &st, &in);                                                       /* 10 counts = 0.5 degrees in 1/60 s = 30 deg/s -> e = cbrt(30 / 1.978e-4) = 53 */
    CHECK(abs(o.x - (53 + GAME_STICK_DEADZONE)) <= 1); CHECK_EQ(o.y, 0);
    in.mouse_dx = 0; for (i = 0; i < 5; i++) o = eval(&p, &st, &in); CHECK_EQ(o.x, 0);               /* the rounding remainder is delivered or dropped, motion stops */
    /* motion is conserved: the angle the game turns by equals the angle the mouse asked for, for slow, medium and fast motion alike */
    { static const int speeds[4] = { 1, 4, 12, 40 }; int s;
      for (s = 0; s < 4; s++) {
          map_reset(&st); in.mouse_dx = (float)speeds[s]; in.mouse_dy = 0; sum = 0; want = 0;
          for (i = 0; i < 200; i++) { want += speeds[s] * MOUSE_DEG_PER_COUNT; o = eval(&p, &st, &in); sum += turned(o.x, 1.0 / 60.0, GAME_YAW_RATE_PER_E3); }
          in.mouse_dx = 0; for (i = 0; i < 100; i++) { o = eval(&p, &st, &in); sum += turned(o.x, 1.0 / 60.0, GAME_YAW_RATE_PER_E3); }
          if (speeds[s] <= 12) CHECK(fabs(sum - want) <= 0.01 * want + 0.02);                          /* fast motion saturates the game's turn rate and the backlog cap drops the excess */
          else CHECK(sum < want && sum > 0.5 * want);
      } }
    map_reset(&st); in.mouse_dx = 0; in.mouse_dy = 7; sum = 0; want = 0;                           /* pitch has its own constant; mouse down = stick down (negative y) */
    for (i = 0; i < 100; i++) { want += 7 * MOUSE_DEG_PER_COUNT; o = eval(&p, &st, &in); CHECK(o.y <= 0); sum += -turned(o.y, 1.0 / 60.0, GAME_PITCH_RATE_PER_E3); }
    for (i = 0; i < 50; i++) { in.mouse_dy = 0; o = eval(&p, &st, &in); sum += -turned(o.y, 1.0 / 60.0, GAME_PITCH_RATE_PER_E3); }
    CHECK(fabs(sum - want) <= 0.01 * want + 0.02);
    map_reset(&st); in.mouse_dx = 0; in.mouse_dy = -20; o = eval(&p, &st, &in); CHECK(o.y > 0);       /* mouse up = look up */
    p.mouse_invert_y = 1; map_reset(&st); o = eval(&p, &st, &in); CHECK(o.y < 0); p.mouse_invert_y = 0;
    /* a big flick saturates at the stick maximum, is caught up over the next samples (at most the backlog) and then stops */
    map_reset(&st); in.mouse_dx = 400; in.mouse_dy = 0; o = eval(&p, &st, &in); CHECK_EQ(o.x, 77 + GAME_STICK_DEADZONE);       /* 20 degrees asked for */
    in.mouse_dx = 0; sum = turned(o.x, 1.0 / 60.0, GAME_YAW_RATE_PER_E3);
    for (n = 0; n < 200 && o.x; n++) { o = eval(&p, &st, &in); sum += turned(o.x, 1.0 / 60.0, GAME_YAW_RATE_PER_E3); }
    CHECK(n > 5 && n < 40); CHECK_EQ(o.x, 0); CHECK(fabs(sum - 20.0) < 0.5);
    map_reset(&st); in.mouse_dx = 4000; o = eval(&p, &st, &in); in.mouse_dx = 0; sum = turned(o.x, 1.0 / 60.0, GAME_YAW_RATE_PER_E3);     /* 200 degrees: only the backlog (30) is kept */
    for (n = 0; n < 400 && o.x; n++) { o = eval(&p, &st, &in); sum += turned(o.x, 1.0 / 60.0, GAME_YAW_RATE_PER_E3); }
    CHECK(fabs(sum - 30.0) < 1.0);
    map_reset(&st); in.mouse_dx = 10; in.mouse_valid = 0; o = eval(&p, &st, &in); CHECK_EQ(o.x, 0);   /* not captured: ignored */
    in.mouse_valid = 1; p.mouse_sens_x = 2.0f; map_reset(&st); o = eval(&p, &st, &in); CHECK(abs(o.x - (67 + GAME_STICK_DEADZONE)) <= 1);   /* 1 degree in 1/60 s = 60 deg/s -> e = 67 */
    p.use_mouse = 0; map_reset(&st); o = eval(&p, &st, &in); CHECK_EQ(o.x, 0); p.use_mouse = 1; p.mouse_sens_x = 1.0f;
    /* time normalisation: the same angle per second gives the same stick whatever the poll rate */
    map_reset(&st); in.dt = 1.0 / 30.0; in.mouse_dx = 20; o = eval(&p, &st, &in); CHECK(abs(o.x - (53 + GAME_STICK_DEADZONE)) <= 1); in.dt = 1.0 / 60.0;
    /* smoothing never loses motion */
    p.mouse_smooth = 0.6f; map_reset(&st); in.mouse_dx = 100; sum = 0; want = 5.0; o = eval(&p, &st, &in); sum += turned(o.x, 1.0 / 60.0, GAME_YAW_RATE_PER_E3);
    in.mouse_dx = 0; for (n = 0; n < 300; n++) { o = eval(&p, &st, &in); sum += turned(o.x, 1.0 / 60.0, GAME_YAW_RATE_PER_E3); } CHECK(fabs(sum - want) < 0.15); p.mouse_smooth = 0;
    /* buttons and wheel */
    map_reset(&st); in.mouse_dx = 0; in.mouse_buttons = 1; o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_Z);                  /* left button = Z in game */
    in.gameplay = 0; o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_A); in.gameplay = 1;                                        /* ... A in menus */
    in.mouse_buttons = 2; o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_B);
    in.mouse_buttons = 0; in.wheel[1] = 3; o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_A); in.wheel[1] = 0;                  /* first tick: pressed */
    o = eval(&p, &st, &in); CHECK_EQ(o.buttons, 0);                                                                                 /* released between ticks */
    o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_A); o = eval(&p, &st, &in); CHECK_EQ(o.buttons, 0);
    o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_A); o = eval(&p, &st, &in); CHECK_EQ(o.buttons, 0); o = eval(&p, &st, &in); CHECK_EQ(o.buttons, 0);
    in.gameplay = 0; in.wheel[0] = 1; o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_DUP);                                      /* wheel up = D-up in menus */
    in.wheel[0] = 0;
    /* mouse as D-pad: motion bound to a button */
    memset(&p.bind[IN_DLEFT], 0, sizeof p.bind[IN_DLEFT]); { Source s; src_parse("MouseX-", &s); binding_add(&p.bind[IN_DLEFT], &s); }
    in.gameplay = 1; map_reset(&st); in.mouse_dx = -30; o = eval(&p, &st, &in); CHECK(o.buttons & N64_BTN_DLEFT);
}

static void set_stick(PadState *p, float x, float y, int right) { p->axis[right ? PA_RX : PA_LX] = x; p->axis[right ? PA_RY : PA_LY] = y; }
static void test_pad_mapping(void) {
    PlayerCfg p; MapState st; InputSample in; N64Pad o; ControlsCfg d; PadState pad; float v;
    printf("mapping: gamepad\n");
    cfg_defaults(&d); p = d.player[0]; map_reset(&st); sample_init(&in); keys_clear(); pad_init(&pad); in.npad = 1; in.pad[0] = &pad;
    o = eval(&p, &st, &in); CHECK_EQ(o.buttons, 0); CHECK_EQ(o.x, 0); CHECK_EQ(o.y, 0);
    set_stick(&pad, 0, 0, 1); pad.axis[PA_RX] = 0.15f; pad.axis[PA_RY] = -0.1f; o = eval(&p, &st, &in); CHECK_EQ(o.x, 0); CHECK_EQ(o.y, 0);       /* inside the dead zone (0.2) */
    set_stick(&pad, 1.0f, 0, 1); o = eval(&p, &st, &in); CHECK_EQ(o.x, 80); CHECK_EQ(o.y, 0);                                                    /* right stick: the N64 stick */
    set_stick(&pad, -1.0f, 0, 1); o = eval(&p, &st, &in); CHECK_EQ(o.x, -80);
    set_stick(&pad, 0, 1.0f, 1); o = eval(&p, &st, &in); CHECK_EQ(o.y, 80); set_stick(&pad, 0, -1.0f, 1); o = eval(&p, &st, &in); CHECK_EQ(o.y, -80);
    v = 0.2f + 0.8f * 0.5f; set_stick(&pad, v, 0, 1); o = eval(&p, &st, &in); CHECK(abs(o.x - 40) <= 1);                                          /* dead zone is rescaled: half way = 40 */
    set_stick(&pad, 0.7071f, 0.7071f, 1); o = eval(&p, &st, &in); CHECK(abs(o.x - 80 * (0.7071f - 0.2f) / 0.8f * 1.0f) <= 12); CHECK_EQ(o.x, o.y);   /* radial: both axes equal on the diagonal */
    set_stick(&pad, 0, 0, 1);
    /* left stick: C buttons in game, D-pad in menus */
    set_stick(&pad, 0, 1.0f, 0); o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_CUP); in.gameplay = 0; o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_DUP); in.gameplay = 1;
    set_stick(&pad, 0.5f, 0, 0); o = eval(&p, &st, &in); CHECK_EQ(o.buttons, 0);                                                                  /* 0.5 -> 0.375 after the dead zone: below 0.5 */
    set_stick(&pad, 0.75f, -0.75f, 0); o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_CRIGHT | N64_BTN_CDOWN);
    set_stick(&pad, 0, 0, 0);
    /* buttons / triggers */
    pad.buttons = (1u << PB_A); o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_R); in.gameplay = 0; o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_A); in.gameplay = 1;
    pad.buttons = (1u << PB_X); o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_A);
    pad.buttons = (1u << PB_START) | (1u << PB_LB) | (1u << PB_RB) | (1u << PB_B); o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_START | N64_BTN_L | N64_BTN_R | N64_BTN_B);
    pad.buttons = (1u << PB_DUP) | (1u << PB_DRIGHT); o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_DUP | N64_BTN_DRIGHT); pad.buttons = 0;
    pad.axis[PA_RT] = 0.29f; o = eval(&p, &st, &in); CHECK_EQ(o.buttons, 0); pad.axis[PA_RT] = 0.31f; o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_Z);
    pad.axis[PA_RT] = 0; pad.axis[PA_LT] = 1.0f; o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_B); pad.axis[PA_LT] = 0;
    /* a disconnected pad contributes nothing; no pad assigned either */
    pad.buttons = 0xFFFF; pad.connected = 0; o = eval(&p, &st, &in); CHECK_EQ(o.buttons, 0); pad.connected = 1; in.npad = 0; o = eval(&p, &st, &in); CHECK_EQ(o.buttons, 0); in.npad = 1; pad.buttons = 0;
    /* invert Y, sensitivity, curve */
    set_stick(&pad, 0, 1.0f, 1); p.stick_invert_y = 1; o = eval(&p, &st, &in); CHECK_EQ(o.y, -80); set_stick(&pad, 0, 0.0f, 0); p.stick_invert_y = 0;
    set_stick(&pad, 0.6f, 0, 1); p.stick_sens_x = 2.0f; o = eval(&p, &st, &in); CHECK_EQ(o.x, 80); p.stick_sens_x = 1.0f;
    p.stick_curve = 2.0f; set_stick(&pad, 0.2f + 0.8f * 0.5f, 0, 1); o = eval(&p, &st, &in); CHECK(abs(o.x - 20) <= 1); p.stick_curve = 1.0f;                       /* 0.5^2 * 80 */
    p.stick_deadzone = 0.0f; set_stick(&pad, 0.05f, 0, 1); o = eval(&p, &st, &in); CHECK_EQ(o.x, 4); p.stick_deadzone = 0.2f;
    /* classic N64 profile: left stick = stick, right stick = C buttons */
    cfg_apply_profile(&p, "xbox_n64", 0); set_stick(&pad, 0, 0, 1); set_stick(&pad, -1.0f, 0, 0); o = eval(&p, &st, &in); CHECK_EQ(o.x, -80); CHECK_EQ(o.buttons, 0);
    set_stick(&pad, 0, 0, 0); set_stick(&pad, 0, 1.0f, 1); o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_CUP); CHECK_EQ(o.y, 0); set_stick(&pad, 0, 0, 1);
    /* generic profile: raw numbers (DirectInput) */
    cfg_apply_profile(&p, "generic", 0); pad.raw_buttons[0] = (1u << 1); o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_A);                            /* Btn2 */
    pad.raw_buttons[0] = 0; pad.raw_axis[2] = 1.0f; o = eval(&p, &st, &in); CHECK_EQ(o.x, 80); pad.raw_axis[2] = 0;
    pad.raw_axis[5] = -1.0f; o = eval(&p, &st, &in); CHECK_EQ(o.y, 80); pad.raw_axis[5] = 0;                                                                  /* Axis6- = up */
    pad.hat[0] = 2; o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_DRIGHT); pad.hat[0] = 7; o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_DUP | N64_BTN_DLEFT); pad.hat[0] = -1;
    pad.raw_axis[1] = 0.9f; o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_CDOWN); pad.raw_axis[1] = -0.9f; o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_CUP); pad.raw_axis[1] = 0;      /* Axis2- = up = C-up */
    /* two pads on one player are or'ed */
    { PadState pad2; cfg_defaults(&d); p = d.player[0]; pad_init(&pad2); in.npad = 2; in.pad[1] = &pad2; pad2.buttons = (1u << PB_B); o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_B);
      pad.buttons = (1u << PB_RB); o = eval(&p, &st, &in); CHECK_EQ(o.buttons, N64_BTN_B | N64_BTN_R); }
}

static void test_conflicts(void) {
    PlayerCfg p; Conflict cf[16]; Source s;
    printf("conflicts\n");
    cfg_player_defaults(&p, 0); CHECK_EQ(cfg_conflicts(&p, cf, 16), 0);
    src_parse("Space", &s); binding_add(&p.bind[IN_A], &s);          /* Space is already R (jump) */
    CHECK_EQ(cfg_conflicts(&p, cf, 16), 1); CHECK(cf[0].in_a == IN_A && cf[0].in_b == IN_R && cf[0].src.id == 0x39);
    { Source m; src_parse("menu:Space", &m); memset(&p.bind[IN_A], 0, sizeof p.bind[IN_A]); binding_add(&p.bind[IN_A], &m); CHECK_EQ(cfg_conflicts(&p, cf, 16), 1); }   /* menu overlaps any */
    { Source g; PlayerCfg q; cfg_player_defaults(&q, 0); src_parse("menu:W", &g); binding_add(&q.bind[IN_B], &g); CHECK_EQ(cfg_conflicts(&q, cf, 16), 1); }         /* menu:W is already DUp */
    { PlayerCfg q; Source g; cfg_player_defaults(&q, 0); src_parse("game:W", &g); memset(&q.bind[IN_B], 0, sizeof q.bind[IN_B]); binding_add(&q.bind[IN_B], &g); CHECK_EQ(cfg_conflicts(&q, cf, 16), 1); }
}

static void test_capture(void) {
    PadState base, cur; Source s; char t[48];
    printf("capture helper\n");
    pad_init(&base); pad_init(&cur);
    CHECK(!pad_detect_source(&base, &cur, 0, &s));                                                   /* nothing changed */
    cur.buttons = (1u << PB_A) | (1u << PB_X); CHECK(pad_detect_source(&base, &cur, 0, &s)); CHECK(s.type == SRC_PBTN && s.id == PB_A);
    base.buttons = (1u << PB_A); CHECK(pad_detect_source(&base, &cur, 0, &s)); CHECK(s.type == SRC_PBTN && s.id == PB_X);      /* A was already down when the capture began */
    base.buttons = cur.buttons; CHECK(!pad_detect_source(&base, &cur, 0, &s));
    cur.axis[PA_RX] = -0.9f; CHECK(pad_detect_source(&base, &cur, 0, &s)); CHECK(s.type == SRC_PAXIS && s.id == PA_RX && s.sign == -1);
    src_format(&s, t, sizeof t); CHECK(!strcmp(t, "Pad.RX-"));
    cur.axis[PA_RX] = 0.3f; cur.axis[PA_RT] = 0.8f; CHECK(pad_detect_source(&base, &cur, 0, &s)); CHECK(s.type == SRC_PAXIS && s.id == PA_RT && s.sign == 1);
    src_format(&s, t, sizeof t); CHECK(!strcmp(t, "Pad.RT"));
    cur.axis[PA_RT] = 0; cur.axis[PA_LY] = 0.7f; CHECK(pad_detect_source(&base, &cur, 0, &s)); src_format(&s, t, sizeof t); CHECK(!strcmp(t, "Pad.LY+"));
    cur.axis[PA_LY] = 0; cur.axis[PA_LX] = 0.5f; CHECK(!pad_detect_source(&base, &cur, 0, &s));                                  /* too little */
    cur.connected = 0; cur.buttons = 0xFFFF; CHECK(!pad_detect_source(&base, &cur, 0, &s)); cur.connected = 1;
    /* raw names for pads of unknown layout */
    pad_init(&base); pad_init(&cur); cur.raw_buttons[0] = 1u << 4; CHECK(pad_detect_source(&base, &cur, 1, &s)); src_format(&s, t, sizeof t); CHECK(!strcmp(t, "Pad.Btn5"));
    cur.raw_buttons[0] = 0; cur.hat[0] = 2; CHECK(pad_detect_source(&base, &cur, 1, &s)); src_format(&s, t, sizeof t); CHECK(!strcmp(t, "Pad.Hat1Right"));
    cur.hat[0] = 6; CHECK(pad_detect_source(&base, &cur, 1, &s)); src_format(&s, t, sizeof t); CHECK(!strcmp(t, "Pad.Hat1Left"));
    cur.hat[0] = -1; cur.raw_axis[2] = 0.9f; CHECK(pad_detect_source(&base, &cur, 1, &s)); src_format(&s, t, sizeof t); CHECK(!strcmp(t, "Pad.Axis3+"));
    base.raw_axis[5] = -1.0f; cur.raw_axis[2] = 0; cur.raw_axis[5] = 1.0f; CHECK(pad_detect_source(&base, &cur, 1, &s)); src_format(&s, t, sizeof t); CHECK(!strcmp(t, "Pad.Axis6+"));   /* a trigger that rests at -1 */
    cur.raw_axis[5] = -1.0f; CHECK(!pad_detect_source(&base, &cur, 1, &s));
}

int input_core_selftest(void) {
    g_fail = g_checks = 0;
    test_names(); test_defaults_and_roundtrip(); test_parser(); test_keyboard_mapping(); test_mouse_mapping(); test_pad_mapping(); test_conflicts(); test_capture();
    printf("input core: %d checks, %d failed\n", g_checks, g_fail);
    return g_fail;
}
#ifdef INPUT_TEST_MAIN
int main(void) { int f = input_core_selftest(); f += inpdev_selftest(); printf("TOTAL: %d failed\n", f); return f ? 1 : 0; }
#endif
