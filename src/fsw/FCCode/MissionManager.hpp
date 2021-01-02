#ifndef MISSION_MANAGER_HPP_
#define MISSION_MANAGER_HPP_

#include "ControlTask.hpp"
#include "StateFieldRegistry.hpp"
#include "mission_mode_t.hpp"
class MissionManager : public ControlTask {
    public:

        MissionManager();
    
        void execute() override;

    protected:

        void set_mission_mode(mission_mode_t mode);

        void calibrate_data();

        void dispatch_warmup();
        void dispatch_initialization();
        void dispatch_standby();
        void dispatch_detumble();
        void dispatch_bellyflop();
        void dispatch_landed();

        // Fields that control overall mission state.
        /**
         * @brief Current mission mode (see mission_mode_t.enum)
         */
        
        long enter_init_millis;
        int enter_init_ccno;
        int enter_freefall_cnno;
        long enter_bellyflop_millis;
        // long enter_standby_millis;
};

#endif
