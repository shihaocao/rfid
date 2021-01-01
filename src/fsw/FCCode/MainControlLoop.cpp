#include "MainControlLoop.hpp"
#include "constants.hpp"


MainControlLoop::MainControlLoop()
    : ControlTask()

 // This item is initialized last so it has access to all state fields
{
    delay(1000); //necessary for imu warm-up
}

void MainControlLoop::execute() {
    LEDControlTask.execute();   
}