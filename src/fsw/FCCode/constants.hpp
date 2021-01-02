#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

namespace constants {
    namespace MCL {
        constexpr unsigned int freq_Mhz = 1;
        constexpr unsigned int freq = freq_Mhz * 1000000;


        // assume we're not clocked above 1000 Mhz
        constexpr unsigned int cycle_length_ns = 1000*1000*1000 / freq;
    }

    namespace LED {
    }

    namespace MM {
    }
}

#endif