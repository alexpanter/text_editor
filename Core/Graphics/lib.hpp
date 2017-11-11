//
// <TODO: insert license here...>
//
// Inspired by naming conventions of the .NET library

// TODO: check for c++ compiler version before using pragma, to accomodate for old compilers
// (or old people). Pretty brain dead to compose this file using C because no classes!
#pragma once

#include <vector>

// TODO: apply strategy pattern here for graphics interface


typedef enum {
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

class GUIControlBlock { // TODO: devise a better name.
public:
    // TODO: define common properties for window, panels, text boxes, buttons, etc.
    GUIBlock* _parent;
    std::vector <GUIBlock*> _children;
    DockStyle _docking; // TODO: dock or docking?
};

class WindowPosition {
public:
    // in screen pixels
    unsigned int xLocation, yLocation;
    unsigned int width, height;
};
class IWindow {
protected:
    WindowPosition _info; // TODO: is info a proper name?
public:
    virtual void OnResize(WindowPosition info) = 0; // TODO: marked for deletion??
    virtual void OnClose() = 0;
    virtual void OnMaximize() = 0;
    virtual void OnMinimize() = 0;
};



class IPanel {
protected:
    IWindow* _window; // TODO: do we need this reference?
    GUIControlBlock _control;
public:
    virtual
};
class ITextBox {
public:

};
class IButton {
public:

};
