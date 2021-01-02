#include "StateFieldRegistry.hpp"
#include "mission_mode_t.hpp"
namespace SFR {
    namespace MCL {

       unsigned int ccno = 0;
    }

    namespace LED {
    }

    namespace MM {
        mission_mode_t mission_mode_f = mission_mode_t::initialization;
    }
}
