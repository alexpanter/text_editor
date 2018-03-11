#pragma once

#include <vector>

#include "../graphics/api/IBuffer.hpp"
#include "../graphics/api/IWindow.hpp"
#include "../graphics/api/IFrame.hpp"

#include "../error.hpp"
#include "../utils.hpp"


namespace Context {

    /*
     * This class stores the graphics context of a running process
     * of the text editor, ie. number of Frames attached, render
     * configurations, and more.
     */
    class GraphicsContext
    {
    private:
        std::vector<IFrame*> _frames;
        int _activeFrame;

    public:
        IFrame* GetActiveFrame() {
            return _frames[_activeFrame]; // TODO: naive implementation!
        }

        int GetNumberOfFrames() {
            return _frames.size();
        }

        bool AddNewFrame() {
            _frames.push_back(new Frame()); // TODO: can we use factory pattern instead!!?

            // if adding the first frame, then set active index accordingly
            if(_frames.size() == 1) {
                _activeFrame = 0;
            }

            return true; // TODO: can this sometimes fail?
        }

        /* Switches to a specific Frame in the list, using its index.
         * This binds the caller to a contract where the index is
         * known and well-defined. If the caller fails to provide
         * this guarantee, an exception is thrown.
         */
        bool SwitchFrame(int index) {
            PRECONDITION(index >= 0);
            PRECONDITION(index < _frames.size());
            bool retval = false;

            // ...
            POSTCONDITION(retval == true);
            return retval;
        }

        /* Switch focus to previous frame in list */
        bool PreviousFrame() {
            PRECONDITION(false);
            bool retval = false;

            // ...
            POSTCONDITION(retval == true);
            return retval;
        }

        /* Switch focus to next frame in list */
        bool NextFrame() {
            PRECONDITION(false);
            bool retval = false;

            // ...
            POSTCONDITION(retval == true);
            return retval;
        }
    };
}
