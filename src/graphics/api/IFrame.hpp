#pragma once

#include <vector>

#include "./IWindow.hpp"
#include "../../utils.hpp"
#include "../../error.hpp"


namespace Graphics {

    /*
     * This class represents the modern interpretation
     * of an application window.
     */
    class IFrame {
    protected:
        // TODO: Would it be better if windows were arranged in a tree-like structure!!?
        //       That way, an entire Window group could be terminated in one action.
        std::vector<IWindow*> _windows;
        int _activeWindow;

    public:
        //                          //
        // WINDOW-RELATED FUNCTIONS //
        //                          //
        IWindow* GetActiveWindow() {
            return _windows[_activeWindow];
        }

        int GetNumberOfWindows() {
            return _windows.size();
        }

        bool AddNewWindow() {
            _windows.push_back(new Window()); // TODO: can we use factory pattern instead!!?

            // if adding the first window, then set active index accordingly
            if(_windows.size() == 1) {
                _activeWindow = 0;
            }

            return true; // TODO: can this sometimes fail?
        }

        /* Switches to a specific Window in the list, using its index.
         * This binds the caller to a contract where the index is
         * known and well-defined. If the caller fails to provide
         * this guarantee, an exception is thrown.
         */
        bool SwitchWindow(int index) {
            PRECONDITION(index >= 0);
            PRECONDITION(index < _windows.size());
            bool retval = false;

            // ...
            POSTCONDITION(retval == true);
            return retval;
        }

        bool PreviousWindow() {
            PRECONDITION(false);
            bool retval = false;

            // ...
            POSTCONDITION(false);
            return retval;
        }

        bool NextWindow() {
            PRECONDITION(false);
            bool retval = false;

            // ...
            POSTCONDITION(false);
            return retval;
        }


        //                         //
        // GRAPHICS-EVENT HANDLING //
        //                         //

        // When the frame is re-sized
        virtual void OnResize() = 0;

        // when the operation system's window manager moves
        // this frame across the screen
        virtual void OnMove() = 0;

        // when this frame is closed - this is not necessarily a
        // complete application shutdown, as several frame instances
        // can be attached to the text editor's process.
        virtual void OnClose() = 0;

        // when this frame is maximized to fill out the entire screen
        virtual void OnMaximize() = 0;

        // when this frame is minimized
        virtual void OnMinimize() = 0;

        // when this frame is being rendered (by calling the
        // implemented 'Render' function).
        virtual void OnRender() = 0;


        //                         //
        // KEYBOARD-EVENT HANDLING //
        //                         //

        // used for retrieving the current sequence of prefix keys
        // entered - an implementation must clean this list every time
        // a key input is processed.
        virtual void GetCurrentKeyPrefix() = 0;

        // when any key is pressed this function is being called.
        // An implementation must do several things:
        //  * If the key is a modifier key (CTRL, SHIFT, ALT), set this
        //    modifier key as internally activated.
        //  * If there is no keybinding for this key (amended to currently
        //    entered key prefix), then amend this key to currently entered
        //    key prefix.
        //  * If a keybinding exists for this key, then call the associated,
        //    bound function.
        virtual void OnKeyPress() = 0;

        // when a key is released, then there are two options:
        //  * If the released key is a modifier key (CTRL, SHIFT, ALT), set
        //    this key as internally deactivated.
        //  * Otherwise, no action should be performed.
        virtual void OnKeyRelease() = 0;


        //                      //
        // MOUSE-EVENT HANDLING //
        //                      //


        //                     //
        // RENDERING FUNCTIONS //
        //                     //
    };
}
