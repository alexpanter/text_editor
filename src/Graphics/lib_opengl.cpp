// API to fill out
#include "lib.hpp"

// GLEW
#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// STANDARD
#include <string>


namespace Graphics
{
    class GLFWContext {
    private:
        static bool GLFW_initialized = false;
        static bool GLEW_initialized = false;

    public:
        static void InitGLFW()
        {
            if(GLFWContext::GLFW_initialized) return;

            if(glfwInit() == GL_FALSE)
            {
                // TODO: error handling system!
                std::cout << "Could not initialize GLFW!" << std::endl;
            }
            GLFWContext::GLFW_initialized = true;
        }
        static void InitGLEW()
        {
            if(GLFWContext::GLEW_initialized) return;

            glewExperimental = GL_TRUE;
            if (glewInit() != GLEW_OK)
            {
                std::cout << "Failed to initialize GLEW" << std::endl;
            }
            GLFWContext::GLEW_initialized = true;
        }
        static void SetWindowHints()
        {
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            // fix compilation on MAC OS X
            if (System::_system_platform == System::SYSTEM_MACOSX)
            {
                glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
            }
            glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
        }
    };




    class Window : IWindow {
    private:
        std::string _title;
        int _width, height;

        GLFWWindow* _window;

        glm::vec4 _clear_color = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
        unsigned long _clear_bits = GL_COLOR_BUFFER_BIT;
    public:
        Window(const char* title, int width, int height)
        {
            // TODO: if each window has its own thread, then GLFW and GLEW could
            // (but should?) be instantiated once for each thread.
            GLFWContext::InitGLFW();
            GLFWContext::SetWindowHints();
            _width = width;
            _height = height;

            // last parameters are: monitor and share
            _window = glfwCreateWindow(_width, _height, title, NULL, NULL);

            if(_window == NULL)
            {
                std::cerr << "Failed to create GLFW windowed window" << std::endl;
                glfwTerminate();
                exit(1); // TODO: might redecide later, because opening window #54 might crash!
            }
            _title = title;

            // activating the window within the current thread,
            // should be done from the main thread
            glfwMakeContextCurrent(_window);

            //
            // TODO: might rethink this, since it is related to Panels!
            //
            // tell OpenGL the size of the rendering window
            // this information is retrieved from GLFW
            glfwGetFramebufferSize(_window, &_width, &_height);

            // parameters: bottom-left corner and the dimensions of the rendering window
            glViewport(0, 0, _width, _height);

            GLFWContext::InitGLEW();
        }
        ~Window()
        {
            glfwDestroyWindow(_window);
            glfwTerminate(); // TODO: put inside GLFWContext class?
        }

        GLFWwindow* GetWindow()
        {
            return _window;
        }

        std::string GetTitle()
        {
            return _title;
        }
        void SetTitle(std::string new_title)
        {
            _title = new_title;
            glfwSetWindowTitle(_window, _title.c_str());
        }

        int GetWidth()
        {
            return _width;
        }
        void SetWidth(int width)
        {
            _width = width;
            // TODO: also change _window attributes
        }
        void SetWidthRelative(int change)
        {
            _width += change;
            // TODO: also change _window attributes
        }
        int GetHeight()
        {
            return _height;
        }
        void SetHeight(int height)
        {
            _height = height;
            // TODO: also change _window attributes
        }
        void SetHeightRelative(int change)
        {
            _height += change;
            // TODO: also change _window attributes
        }

        bool ShouldClose()
        {
            return glfwWindowShouldClose(_window);
        }
        // this function does not actually close the window,
        // but marks it as 'ready to close'
        void CloseWindow()
        {
            glfwSetWindowShouldClose(_window, GL_TRUE);
        }

        // Double buffering, should be done at the end of each
        // iteration of the rendering loop
        void SwapBuffers()
        {
            glfwSwapBuffers(_window);
        }

        // clear the window to prevent artifacts from the previous
        // iteration of the rendering loop
        void ClearScreen()
        {
            glClearColor(_clear_color.x, _clear_color.y,
                         _clear_color.z, 1.0f);
            glClear(_clear_bits);
        }
        void SetClearBits(unsigned long bits)
        {
            _clear_bits = bits;
        }

        // this method adds any incoming events to openGL's
        // event queue. Should be called at the start of every
        // iteration of the game loop
        void PollEvents()
        {
            glfwPollEvents();
        }
        // this method does the same as the above, except
        // here the main thread is blocked until any event is received
        void WaitEvents()
        {
            glfwWaitEvents();
        }
    };




    class Panel : IPanel {
    private:
    public:
        Panel(GLFWWindow* window) : _window(window)
        {}
        ~Panel() {}
    };

}
