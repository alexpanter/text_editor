#pragma once

#include "graphicsContext.hpp"


namespace Context {

    /*
     * This class stores the context of a running process
     * of the text editor.
     */
    class ApplicationContext
    {
    private:
      bool _isRunning;

    public:
        GraphicsContext* graphicsContext;

        bool IsRunning() {
            return _isRunning;
        }

        void CloseApplication() {
            _isRunning = false;
        }
    };
}
