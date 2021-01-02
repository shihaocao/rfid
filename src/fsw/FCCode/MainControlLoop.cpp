#include "MainControlLoop.hpp"
#include "constants.hpp"

#include "StateFieldRegistry.hpp"

MainControlLoop::MainControlLoop()
    : ControlTask()

 // This item is initialized last so it has access to all state fields
{
    delay(1000); //necessary for imu warm-up
}

void MainControlLoop::execute() {
    led_ct.execute();

    timing_overhead();
}

void MainControlLoop::timing_overhead() {
    
    SFR::MCL::ccno++;
    asm volatile ( "nop":: );

}

unsigned int nanos_to_wait(){
    return 0;
}