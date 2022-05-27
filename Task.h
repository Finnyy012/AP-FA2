//
// Created by Finn on 20/05/2022.
//

#ifndef UNTITLED1_TASK_H
#define UNTITLED1_TASK_H

#include <string>
#include "Employee.h"
#include "Shelf.h"

using namespace std;

enum TaskStatus{todo, finished=true, failed=false};

class Task {
private:
    int id;
    bool requiresForkLift;
    int requiredTaskForce;
    TaskStatus taskStatus;

public:
    /**
     * constructor for Task
     *
     * @param id: task ID (int)
     * @param requiresForkLift: true iff task requires a forklift, false otherwise
     * @param requiredTaskForce: ? (int)
     */
    Task(int id, bool requiresForkLift, int requiredTaskForce);

    /**
     * getter for id
     * @return task ID (int)
     */
    int getId();

    /**
     * setter for id
     * @param id: task ID (int)
     */
    void setId(int id);

    /**
     * getter for requiresForkLift
     * @return true iff task requires a forklift, false otherwise (bool)
     */
    bool RequiresForkLift();

    /**
     * setter for requiresForkLift
     * @param requiresForkLift: updated forklift status (bool)
     */
    void setRequiresForkLift(bool requiresForkLift);

    /**
     * getter for taskStatus
     * @return task status (TaskStatus&)
     */
    TaskStatus& getTaskStatus();

    /**
     * setter for taskStatus
     * @param taskStatus status of the task (taskStatus&)
     */
    void setTaskStatus(TaskStatus& taskStatus);

    /**
     * virtual function to be implemented in child classes; runs the respective task
     *
     * @param employee: employee to perform the task (Employee&)
     * @param shelves: collection of shelves to be searched (vector<Shelf*>&)
     *
     * @return task result (bool)
     */
    virtual bool runTask(Employee &employee, vector<Shelf*>& shelves)=0;
};

#endif //UNTITLED1_TASK_H
