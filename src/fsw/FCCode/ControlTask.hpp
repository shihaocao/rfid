#ifndef CONTROL_TASK_HPP_
#define CONTROL_TASK_HPP_

#include <memory>
#include <string>

#ifdef DESKTOP
#include <iostream>
#else
#include <Arduino.h>
#endif

/**
 * @brief A control ControlTaskBase is a wrapper around any high-level ControlTaskBase that
 * interacts with satellite data.
 *
 * This class is subclassed heavily in order to provide multiple
 * implementations of execute() for different kinds of ControlTasks.
 */
class ControlTask{
  public:
    /**
     * @brief Construct a new Control ControlTaskBase object
     *
     * @param name     Name of control ControlTaskBase
     * @param registry Pointer to state field registry
     */
    ControlTask() {

    }

    /**
     * @brief Run main method of control ControlTaskBase.
     */
    void execute();

    /**
     * @brief Destroy the Control Task object
     * 
     * We need to have this destructor to avoid compilation errors.
     */
    virtual ~ControlTask() = 0;

};

ControlTask::~ControlTask() {}

#endif
