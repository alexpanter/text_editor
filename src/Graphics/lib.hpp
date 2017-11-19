//
// <TODO: insert license here...>
//
// Inspired by naming conventions of the .NET library

// TODO: check for c++ compiler version before using pragma, to accomodate for old compilers
// (or old people). Pretty brain dead to compose this file using C because no classes!
#pragma once

#include <vector>

namespace Graphics
{


// TODO: should screen coordinates be used in normalized coordinates instead of pixels?
typedef coord_t unsigned int;

typedef enum {
    Fill,

    OnlyLeft,
    OnlyRight,
    OnlyTop,
    OnlyBottom,

    LeftAndTop,
    LeftAndBottom,
    RightAndTop,
    RightAndBottom,

    AllTop,
    AllLeft,
    AllRIght,
    AllBottom,

    // probably less common?
    OnlyLeftAndRight,
    OnlyTopAndBottom
} DockStyle;

class IMouseEventControl {
public:
    virtual void OnClick(coord_t x, coord_t y) = 0;
    virtual void OnMouseHover() = 0;
    virtual void OnMouseEnter() = 0;
    virtual void OnMouseLeave() = 0;
};
class IKeyboardEventControl {
public:
    virtual void OnKeyPress() = 0; // TODO: use template for variadic argument list!
    virtual void OnKeyRelease() = 0;
}

class IGUIControlBlock { // TODO: devise a better name.
public:
    // TODO: define common properties for window, panels, text boxes, buttons, etc.
    IGUIControlBlock* _parent;
    std::vector <IGUIControlBlock*> _children;
    // there must always be a docking style for any GUI control block
    DockStyle _dock;
};

class IWindow : IMouseEventControl, IKeyboardEventControl {
protected:
    coord_t width, height;
    coord_t xLocation, yLocation;
    IGUIControlBlock _main_panel; // there must always be a main panel attached!
                                  // TODO: is this a smart design decision?
public:
    virtual void OnResize(coord_t width, coord_t height) = 0;
    virtual void OnMove(coord_t x, coord_t y) = 0; // pixel coordinates
    virtual void OnClose() = 0;
    virtual void OnMaximize() = 0;
    virtual void OnMinimize() = 0;
};

class IPanel {
protected:
    IWindow* _window; // TODO: do we need this reference?
    IGUIControlBlock _control;
};
class ITextBox {
protected:
    IGUIControlBlock _control;
};
class IButton {
protected:
    IGUIControlBlock _control;
};



} // namespace Graphics
