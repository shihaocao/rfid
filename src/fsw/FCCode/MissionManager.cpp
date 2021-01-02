#include "MissionManager.hpp"
#include "StateFieldRegistry.hpp"

MissionManager::MissionManager() :
    ControlTask()
{

    enter_init_ccno = -1;
    enter_freefall_cnno = -1;

}

void MissionManager::execute() {
    mission_mode_t mode = SFR::MM::mission_mode_f;
    calibrate_data();

    switch(mode) {
        case mission_mode_t::warmup:
            dispatch_warmup();
            break;
        case mission_mode_t::initialization:
            dispatch_initialization();
            break;
        case mission_mode_t::standby:
            dispatch_standby();
            break;
        case mission_mode_t::detumble:
            dispatch_detumble();
            break;
        case mission_mode_t::bellyflop:
            dispatch_bellyflop();
            break;
        case mission_mode_t::landed:
            dispatch_landed();
            break;
        default:
            // printf(debug_severity::error, "Master state not defined: %d\n", static_cast<unsigned int>(mode));
            // mission_mode_f.set(static_cast<unsigned char>(mission_mode_t::landed));
            break;
    }
}

void MissionManager::dispatch_warmup() {
    // if 5 sec elapse go to init

    if(true)  {
        SFR::MM::mission_mode_f = mission_mode_t::initialization;
    }

}

void MissionManager::dispatch_initialization() {
    // weight the current altitude readings

}

void MissionManager::dispatch_standby() {


}

// lode star needs detumble too. If we're tumbling waaaay to fast, 
// step one should just be to keep fins out to zero out all spin
void MissionManager::dispatch_detumble() {
    
}

void MissionManager::dispatch_bellyflop() {
    //servo should already be on

    //actuate as you would during belly flop
}

void MissionManager::dispatch_landed() {
    //dump data from registry to SD Card
    // safe vehicle

}

