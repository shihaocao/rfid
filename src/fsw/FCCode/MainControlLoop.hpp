#ifndef MAIN_CONTROL_LOOP_TASK_HPP_
#define MAIN_CONTROL_LOOP_TASK_HPP_

#include "ControlTask.hpp"
#include "LEDControlTask.hpp"
class MainControlLoop : public ControlTask {
   protected:

    /**
     * @brief Total memory use, in bytes.
     */
    LEDControlTask LEDControlTask;

   public:
    /*
     * @brief Construct a new Main Control Loop Task object
     * 
     * @param registry State field registry
     * @param flow_data Metadata for telemetry flows.
     */
    MainControlLoop();

    /**
     * @brief Processes state field commands present in the serial buffer.
     */
    void execute() override;

};

#endif