//
// Bind the graphics API to a namespace, and check
// for supported graphics backends before doing so.
//


// basic graphics API
#include "lib.hpp"


// NOTE: __has_include() is a macro that is only supported from c++17.
// IF OPENGL IS SUPPORTED!
#if __has_include(<some_opengl_header>)

