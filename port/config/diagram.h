// diagram.h - the N64 controller diagram of the mapping tool: a custom control that draws the pad, highlights the pressed buttons and the stick position live,
// and reports clicks on the buttons.  Coordinates inside are a logical 560 x 360 box scaled to the control.
#pragma once
#include <windows.h>

#define WM_DIAGRAM_SELECT (WM_APP + 10)     // wParam = N64 input (IN_*): single click / hover-select
#define WM_DIAGRAM_BIND   (WM_APP + 11)     // wParam = N64 input: double click (start the capture)
#define WM_DIAGRAM_HOVER  (WM_APP + 12)     // wParam = N64 input under the mouse + 1 (0 = none)

struct DiagramState {
    int selected;                // IN_* or -1
    unsigned buttons;            // live N64 buttons (N64_BTN_*)
    int stickX, stickY;          // live stick -80..80
    unsigned char bound[18];     // number of sources bound to each input
    unsigned char conflict[18];  // 1 = the input shares a source with another one
    int dpi;
};

void Diagram_Register(HINSTANCE inst);
HWND Diagram_Create(HWND parent, int id, int x, int y, int w, int h);
void Diagram_SetState(HWND h, const DiagramState &st);
int  Diagram_Hover(HWND h);          // input under the mouse or -1
