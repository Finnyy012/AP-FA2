//
// Created by Finn on 20/05/2022.
//

#include "Task.h"

Task::Task(int id, bool requiresForkLift, int requiredTaskForce) :
        id(id), requiresForkLift(requiresForkLift), requiredTaskForce(requiredTaskForce), taskStatus(todo) {}

int Task::getId() {
    return id;
}

void Task::setId(int id) {
    Task::id = id;
}

bool Task::RequiresForkLift() {
    return requiresForkLift;
}

void Task::setRequiresForkLift(bool requiresForkLift) {
    Task::requiresForkLift = requiresForkLift;
}

TaskStatus& Task::getTaskStatus() {
    return taskStatus;
}

void Task::setTaskStatus(TaskStatus& taskStatus) {
    Task::taskStatus = taskStatus;
}
