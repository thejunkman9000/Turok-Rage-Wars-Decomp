// diagram.cpp - see diagram.h
#include "diagram.h"
#include <windowsx.h>
#include <math.h>
#include <string.h>
extern "C" {
#include "../input_core.h"
}

namespace {

struct Spot { int input; int shape; int a, b, c, d; const wchar_t *label; COLORREF color; };   // shape 0 circle (cx, cy, r, -), 1 rect (l, t, r, b), 2 rounded rect
// logical coordinates (560 x 360)
const Spot kSpots[] = {
    { IN_L,           2,  44,  30, 206,  58, L"L",     RGB(190, 190, 196) },
    { IN_R,           2, 354,  30, 516,  58, L"R",     RGB(190, 190, 196) },
    { IN_DUP,         1,  92, 108, 118, 134, L"",      RGB(70, 70, 76) },
    { IN_DDOWN,       1,  92, 160, 118, 186, L"",      RGB(70, 70, 76) },
    { IN_DLEFT,       1,  66, 134,  92, 160, L"",      RGB(70, 70, 76) },
    { IN_DRIGHT,      1, 118, 134, 144, 160, L"",      RGB(70, 70, 76) },
    { IN_START,       0, 280, 118,  15,   0, L"START", RGB(205, 60, 60) },
    { IN_CUP,         0, 452,  96,  17,   0, L"",      RGB(236, 196, 40) },
    { IN_CDOWN,       0, 452, 162,  17,   0, L"",      RGB(236, 196, 40) },
    { IN_CLEFT,       0, 419, 129,  17,   0, L"",      RGB(236, 196, 40) },
    { IN_CRIGHT,      0, 485, 129,  17,   0, L"",      RGB(236, 196, 40) },
    { IN_B,           0, 396, 196,  23,   0, L"B",     RGB(70, 170, 90) },
    { IN_A,           0, 454, 222,  27,   0, L"A",     RGB(60, 110, 210) },
    { IN_Z,           2, 224, 312, 336, 338, L"Z",     RGB(170, 170, 176) },
    { IN_STICK_UP,    0, 280, 182,  17,   0, L"",      RGB(150, 150, 158) },
    { IN_STICK_DOWN,  0, 280, 290,  17,   0, L"",      RGB(150, 150, 158) },
    { IN_STICK_LEFT,  0, 226, 236,  17,   0, L"",      RGB(150, 150, 158) },
    { IN_STICK_RIGHT, 0, 334, 236,  17,   0, L"",      RGB(150, 150, 158) },
};
const int kNumSpots = sizeof kSpots / sizeof kSpots[0];

struct Data {
    DiagramState st;
    int hover;
    bool tracking;
    float scale; int ox, oy;
};

Data *getData(HWND h) { return (Data *)GetWindowLongPtrW(h, GWLP_USERDATA); }

POINT toLogical(Data *d, int x, int y) { POINT p; p.x = (int)((x - d->ox) / d->scale); p.y = (int)((y - d->oy) / d->scale); return p; }

bool hit(const Spot &s, POINT p) {
    if (s.shape == 0) { int dx = p.x - s.a, dy = p.y - s.b; return dx * dx + dy * dy <= s.c * s.c; }
    return p.x >= s.a && p.x <= s.c && p.y >= s.b && p.y <= s.d;
}
int hitTest(POINT p) {
    for (int i = kNumSpots - 1; i >= 0; i--) if (hit(kSpots[i], p)) return kSpots[i].input;
    return -1;
}

void computeScale(Data *d, RECT rc) {
    float sx = (rc.right - rc.left) / 560.0f, sy = (rc.bottom - rc.top) / 360.0f;
    d->scale = sx < sy ? sx : sy;
    d->ox = (int)((rc.right - rc.left - 560 * d->scale) / 2);
    d->oy = (int)((rc.bottom - rc.top - 360 * d->scale) / 2);
}

struct Gfx {
    HDC dc; Data *d;
    int X(int v) const { return d->ox + (int)(v * d->scale + 0.5f); }
    int Y(int v) const { return d->oy + (int)(v * d->scale + 0.5f); }
    int L(int v) const { return (int)(v * d->scale + 0.5f); }
};

void fillRound(Gfx &g, int l, int t, int r, int b, int rad, COLORREF fill, COLORREF line, int lw = 1) {
    HBRUSH br = CreateSolidBrush(fill); HPEN pen = CreatePen(PS_SOLID, lw, line);
    HGDIOBJ ob = SelectObject(g.dc, br), op = SelectObject(g.dc, pen);
    RoundRect(g.dc, g.X(l), g.Y(t), g.X(r), g.Y(b), g.L(rad) * 2, g.L(rad) * 2);
    SelectObject(g.dc, ob); SelectObject(g.dc, op); DeleteObject(br); DeleteObject(pen);
}
void fillCircle(Gfx &g, int cx, int cy, int r, COLORREF fill, COLORREF line, int lw = 1) {
    HBRUSH br = CreateSolidBrush(fill); HPEN pen = CreatePen(PS_SOLID, lw, line);
    HGDIOBJ ob = SelectObject(g.dc, br), op = SelectObject(g.dc, pen);
    Ellipse(g.dc, g.X(cx - r), g.Y(cy - r), g.X(cx + r), g.Y(cy + r));
    SelectObject(g.dc, ob); SelectObject(g.dc, op); DeleteObject(br); DeleteObject(pen);
}
COLORREF mix(COLORREF a, COLORREF b, int pctB) {
    return RGB((GetRValue(a) * (100 - pctB) + GetRValue(b) * pctB) / 100, (GetGValue(a) * (100 - pctB) + GetGValue(b) * pctB) / 100, (GetBValue(a) * (100 - pctB) + GetBValue(b) * pctB) / 100);
}
void text(Gfx &g, const wchar_t *s, int cx, int cy, COLORREF col, int px, bool bold = true) {
    HFONT f = CreateFontW(-g.L(px), 0, 0, 0, bold ? FW_BOLD : FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, L"Segoe UI");
    HGDIOBJ of = SelectObject(g.dc, f); SetBkMode(g.dc, TRANSPARENT); SetTextColor(g.dc, col);
    SIZE sz; GetTextExtentPoint32W(g.dc, s, (int)wcslen(s), &sz);
    TextOutW(g.dc, g.X(cx) - sz.cx / 2, g.Y(cy) - sz.cy / 2, s, (int)wcslen(s));
    SelectObject(g.dc, of); DeleteObject(f);
}
void triangle(Gfx &g, int cx, int cy, int r, int dir, COLORREF col) {   // dir 0 up, 1 right, 2 down, 3 left
    POINT p[3];
    switch (dir) {
    case 0: p[0] = { g.X(cx), g.Y(cy - r) }; p[1] = { g.X(cx - r), g.Y(cy + r / 2) }; p[2] = { g.X(cx + r), g.Y(cy + r / 2) }; break;
    case 2: p[0] = { g.X(cx), g.Y(cy + r) }; p[1] = { g.X(cx - r), g.Y(cy - r / 2) }; p[2] = { g.X(cx + r), g.Y(cy - r / 2) }; break;
    case 3: p[0] = { g.X(cx - r), g.Y(cy) }; p[1] = { g.X(cx + r / 2), g.Y(cy - r) }; p[2] = { g.X(cx + r / 2), g.Y(cy + r) }; break;
    default: p[0] = { g.X(cx + r), g.Y(cy) }; p[1] = { g.X(cx - r / 2), g.Y(cy - r) }; p[2] = { g.X(cx - r / 2), g.Y(cy + r) }; break;
    }
    HBRUSH br = CreateSolidBrush(col); HPEN pen = CreatePen(PS_SOLID, 1, col); HGDIOBJ ob = SelectObject(g.dc, br), op = SelectObject(g.dc, pen);
    Polygon(g.dc, p, 3); SelectObject(g.dc, ob); SelectObject(g.dc, op); DeleteObject(br); DeleteObject(pen);
}

void paint(HWND h, HDC wdc) {
    Data *d = getData(h); RECT rc; GetClientRect(h, &rc);
    HDC dc = CreateCompatibleDC(wdc); HBITMAP bmp = CreateCompatibleBitmap(wdc, rc.right, rc.bottom); HGDIOBJ obmp = SelectObject(dc, bmp);
    HBRUSH bg = GetSysColorBrush(COLOR_WINDOW); FillRect(dc, &rc, bg);
    computeScale(d, rc);
    Gfx g = { dc, d };
    const COLORREF body = RGB(214, 214, 220), edge = RGB(90, 90, 98), accent = RGB(255, 140, 0), good = RGB(60, 200, 90);
    // body: top bar, three prongs
    fillRound(g, 26, 56, 534, 210, 62, body, edge, 2);
    fillRound(g, 26, 100, 186, 340, 76, body, edge, 2);
    fillRound(g, 374, 100, 534, 340, 76, body, edge, 2);
    fillRound(g, 196, 150, 364, 352, 62, body, edge, 2);
    fillRound(g, 30, 60, 530, 204, 58, body, body, 1);                       // hides the seams inside
    fillRound(g, 200, 154, 360, 346, 58, body, body, 1);
    // stick base, d-pad centre
    fillCircle(g, 280, 236, 46, RGB(110, 110, 118), edge, 2);
    fillCircle(g, 280, 236, 30, RGB(60, 60, 66), edge, 1);
    fillRound(g, 92, 134, 118, 160, 2, RGB(70, 70, 76), RGB(70, 70, 76));
    // the live stick position
    {
        int sx = d->st.stickX, sy = d->st.stickY; if (sx > 80) sx = 80; if (sx < -80) sx = -80; if (sy > 80) sy = 80; if (sy < -80) sy = -80;
        fillCircle(g, 280 + sx * 22 / 80, 236 - sy * 22 / 80, 13, (sx || sy) ? RGB(60, 180, 255) : RGB(160, 160, 168), RGB(30, 30, 34), 1);
    }
    for (int i = 0; i < kNumSpots; i++) {
        const Spot &s = kSpots[i];
        bool down = false;
        if (s.input < IN_BUTTONS) down = (d->st.buttons & in_button_mask(s.input)) != 0;
        else if (s.input == IN_STICK_LEFT) down = d->st.stickX < -4; else if (s.input == IN_STICK_RIGHT) down = d->st.stickX > 4;
        else if (s.input == IN_STICK_UP) down = d->st.stickY > 4; else if (s.input == IN_STICK_DOWN) down = d->st.stickY < -4;
        bool sel = d->st.selected == s.input, hov = d->hover == s.input;
        COLORREF fill = s.color; if (!d->st.bound[s.input]) fill = mix(fill, RGB(255, 255, 255), 55);
        if (down) fill = good; else if (hov) fill = mix(fill, RGB(255, 255, 255), 30);
        COLORREF line = sel ? accent : (d->st.conflict[s.input] ? RGB(220, 40, 40) : edge); int lw = sel ? 3 : (d->st.conflict[s.input] ? 2 : 1);
        if (s.input >= IN_STICK_LEFT) {
            int dir = s.input == IN_STICK_UP ? 0 : s.input == IN_STICK_RIGHT ? 1 : s.input == IN_STICK_DOWN ? 2 : 3;
            fillCircle(g, s.a, s.b, s.c, down ? good : mix(RGB(225, 225, 230), RGB(255, 255, 255), hov ? 60 : 0), line, lw);
            triangle(g, s.a, s.b, 8, dir, down ? RGB(20, 90, 40) : (d->st.bound[s.input] ? RGB(70, 70, 80) : RGB(170, 170, 176)));
        } else if (s.shape == 0) {
            fillCircle(g, s.a, s.b, s.c, fill, line, lw);
            if (s.label[0]) text(g, s.label, s.a, s.b, RGB(255, 255, 255), s.c > 20 ? 20 : 11);
            else if (s.input >= IN_CUP) { int dir = s.input == IN_CUP ? 0 : s.input == IN_CRIGHT ? 1 : s.input == IN_CDOWN ? 2 : 3; triangle(g, s.a, s.b, 7, dir, RGB(110, 80, 0)); }
        } else if (s.shape == 1) {
            fillRound(g, s.a, s.b, s.c, s.d, 3, down ? good : (hov ? RGB(110, 110, 118) : s.color), line, lw);
            int dir = s.input == IN_DUP ? 0 : s.input == IN_DRIGHT ? 1 : s.input == IN_DDOWN ? 2 : 3; triangle(g, (s.a + s.c) / 2, (s.b + s.d) / 2, 6, dir, RGB(230, 230, 235));
        } else {
            fillRound(g, s.a, s.b, s.c, s.d, 12, fill, line, lw);
            text(g, s.label, (s.a + s.c) / 2, (s.b + s.d) / 2, RGB(40, 40, 46), 16);
        }
        if (d->st.conflict[s.input]) text(g, L"!", s.shape == 0 ? s.a + s.c - 2 : s.c - 4, s.shape == 0 ? s.b - s.c + 2 : s.b + 4, RGB(220, 40, 40), 16);
    }
    text(g, L"stick", 280, 270, RGB(210, 210, 216), 11, false);
    text(g, L"D-pad", 105, 205, RGB(90, 90, 98), 12, false);
    text(g, L"C buttons", 452, 66, RGB(120, 100, 20), 12, false);
    BitBlt(wdc, 0, 0, rc.right, rc.bottom, dc, 0, 0, SRCCOPY);
    SelectObject(dc, obmp); DeleteObject(bmp); DeleteDC(dc);
}

LRESULT CALLBACK proc(HWND h, UINT m, WPARAM w, LPARAM l) {
    Data *d = getData(h);
    switch (m) {
    case WM_NCCREATE: { Data *nd = new Data(); memset(nd, 0, sizeof *nd); nd->hover = -1; nd->st.selected = -1; SetWindowLongPtrW(h, GWLP_USERDATA, (LONG_PTR)nd); break; }
    case WM_NCDESTROY: delete d; SetWindowLongPtrW(h, GWLP_USERDATA, 0); break;
    case WM_ERASEBKGND: return 1;
    case WM_PAINT: { PAINTSTRUCT ps; HDC dc = BeginPaint(h, &ps); paint(h, dc); EndPaint(h, &ps); return 0; }
    case WM_PRINTCLIENT: paint(h, (HDC)w); return 0;
    case WM_MOUSEMOVE: {
        RECT rc; GetClientRect(h, &rc); computeScale(d, rc);
        int hv = hitTest(toLogical(d, GET_X_LPARAM(l), GET_Y_LPARAM(l)));
        if (!d->tracking) { TRACKMOUSEEVENT t = { sizeof t, TME_LEAVE, h, 0 }; TrackMouseEvent(&t); d->tracking = true; }
        if (hv != d->hover) { d->hover = hv; InvalidateRect(h, NULL, FALSE); SetCursor(LoadCursorW(NULL, hv >= 0 ? IDC_HAND : IDC_ARROW)); SendMessageW(GetParent(h), WM_DIAGRAM_HOVER, (WPARAM)(hv + 1), 0); }
        return 0;
    }
    case WM_MOUSELEAVE: d->tracking = false; if (d->hover != -1) { d->hover = -1; InvalidateRect(h, NULL, FALSE); SendMessageW(GetParent(h), WM_DIAGRAM_HOVER, 0, 0); } return 0;
    case WM_SETCURSOR: if (d->hover >= 0) { SetCursor(LoadCursorW(NULL, IDC_HAND)); return TRUE; } break;
    case WM_LBUTTONDOWN: case WM_LBUTTONDBLCLK: {
        RECT rc; GetClientRect(h, &rc); computeScale(d, rc);
        int in = hitTest(toLogical(d, GET_X_LPARAM(l), GET_Y_LPARAM(l)));
        if (in >= 0) SendMessageW(GetParent(h), m == WM_LBUTTONDBLCLK ? WM_DIAGRAM_BIND : WM_DIAGRAM_SELECT, (WPARAM)in, 0);
        return 0;
    }
    }
    return DefWindowProcW(h, m, w, l);
}

}  // namespace

void Diagram_Register(HINSTANCE inst) {
    WNDCLASSW wc = {}; wc.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW; wc.lpfnWndProc = proc; wc.hInstance = inst; wc.hCursor = LoadCursorW(NULL, IDC_ARROW); wc.lpszClassName = L"N64Diagram";
    RegisterClassW(&wc);
}
HWND Diagram_Create(HWND parent, int id, int x, int y, int w, int h) {
    return CreateWindowExW(WS_EX_CLIENTEDGE, L"N64Diagram", L"", WS_CHILD | WS_VISIBLE, x, y, w, h, parent, (HMENU)(INT_PTR)id, GetModuleHandleW(NULL), NULL);
}
void Diagram_SetState(HWND h, const DiagramState &st) {
    Data *d = getData(h);
    if (!d) return;
    if (memcmp(&d->st, &st, sizeof st) != 0) { d->st = st; InvalidateRect(h, NULL, FALSE); }
}
int Diagram_Hover(HWND h) { Data *d = getData(h); return d ? d->hover : -1; }
