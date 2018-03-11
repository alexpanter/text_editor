#include "../../utils.hpp"
#include "../../error.hpp"

namespace Graphics {

    typedef enum {
        Fill,

        AllLeft,
        AllRight,
        AllTop,
        AllBottom,

        OnlyLeft,
        OnlyRight,
        OnlyTop,
        OnlyBottom,

        LeftAndTop,
        LeftAndBottom,
        RightAndTop,
        RightAndBottom,

        OnlyLeftAndRight,
        OnlyTopAndBottom
    } WindowDocking;

    /*
     * This class
     */
    class IWindow {
    protected:
        WindowDocking _dockStyle;

    public:
        WindowDocking GetDockStyle() {
            return _dockStyle;
        }

        void SetDockStyle(WindowDocking newDockStyle) {
            // TODO: is void a clever return type?
            _dockStyle = newDockStyle;
        }
    }
}
