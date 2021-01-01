#ifndef LED_CONTROL_TASK_HPP_
#define LED_CONTROL_TASK_HPP_
#pragma once

#include "ControlTask.hpp"

/**
* @brief Gets inputs from the ADCS box and dumps them into the state
* fields listed below.
*/
class LEDControlTask : public ControlTask
{
public:
    /**
     * @brief Construct a new ADCSBoxMonitor control task
     * 
     * @param registry input StateField registry
     * @param offset control task offset
     */
    LEDControlTask();

    /**
    * @brief Gets inputs from the ADCS box and dumps them into the state
    * fields listed below.
    */
    void execute() override;

protected:
    /**
    * @brief Inputs to get from ADCS box.
    */

 
};

#endif
