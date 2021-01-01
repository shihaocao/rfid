#include "LEDControlTask.hpp"

LEDControlTask::LEDControlTask()
    : ControlTask()
    {
        pinMode(13, OUTPUT);
    }

static long last_millis = millis();
static bool led_on = false;

void LEDControlTask::execute(){
    if(millis() - last_millis > 500){
        led_on = !led_on;
        last_millis = millis();
        digitalWrite(13, led_on);
    }
}