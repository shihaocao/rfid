#ifndef mission_mode_t_hpp_
#define mission_mode_t_hpp_

// pan.mode
enum class mission_mode_t {
    warmup,
    pause,
    initialization,
    standby,
    detumble,
    bellyflop,
    landed,
    flight,
    descent,

};

#endif
