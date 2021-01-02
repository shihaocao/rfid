#ifndef TIMED_CONTROL_TASK_HPP_
#define TIMED_CONTROL_TASK_HPP_



#include "ControlTask.hpp"

/**
 * @brief A control ControlTaskBase is a wrapper around any high-level ControlTaskBase that
 * interacts with satellite data.
 *
 * This class is subclassed heavily in order to provide multiple
 * implementations of execute() for different kinds of ControlTasks.
 */
class TimedControlTask : public ControlTask{
  public:
    /**
     * @brief Construct a new Control ControlTaskBase object
     *
     * @param name     Name of control ControlTaskBase
     * @param registry Pointer to state field registry
     */
    TimedControlTask() {

    }

    /**
     * @brief Run main method of control ControlTaskBase.
     */
    virtual void execute();

    /**
     * @brief Destroy the Control Task object
     * 
     * We need to have this destructor to avoid compilation errors.
     */
    virtual ~TimedControlTask() = 0;

};

TimedControlTask::~TimedControlTask() {}

#endif
