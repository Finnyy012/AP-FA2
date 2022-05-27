//
// Created by Finn on 20/05/2022.
//

#ifndef UNTITLED1_WAREHOUSE_H
#define UNTITLED1_WAREHOUSE_H

#include <vector>
#include "Task.h"
#include "Employee.h"
#include "Shelf.h"

using namespace std;

class Warehouse {
private:
    vector<Task*> tasks;
    vector<Employee*> employees;
    vector<Shelf*> shelves;

public:
    /**
     * constructor for Warehouse
     */
    Warehouse();

    /**
     * returns the amount of tasks that have not yet been finished
     * @return cumulative task status (int)
     */
    int getTotalTaskStatus();

    /**
     * runs and updates the provided task, and returns finished if the task exists, is not yet finished
     * and the task can be performed by the provided Employee.
     *
     * @param taskID : id of tak to be performed (int)
     * @param employee: employee to perform the task (Employee)
     * @return status of respective task (TaskStatus)
     */
    TaskStatus performOneTask(int taskID, Employee* employee);

    /**
     * finds a suitable employee for each unfinished task and lets them perform this task.
     * if there are any tasks left to perform it recursively calls itself until either all tasks are finished
     * or there are no tasks left that can be performed
     *
     * @return finished if all unfinished tasks have been performed, failed otherwise (TaskStatus)
     */
    TaskStatus performAllTasks();

    /**
     * adds an employee to employees
     *
     * @param employee: employee to be added (Employee*)
     */
    void addEmployee(Employee* employee);

    /**
     * getter for employees
     *
     * @return collection of employees (vector<Employee*>&)
     */
    vector<Employee*>& getEmployees();

    /**
     * setter for employees
     *
     * @param employees: collection of employees (vector<Employee*>&)
     */
    void setEmployees(vector<Employee*>& employees);

    /**
     * adds a task to tasks
     *
     * @param task: task to be added (Task*)
     */
    void addTask(Task* task);

    /**
     * getter for tasks
     *
     * @return collection of tasks (vector<Task*>&)
     */
    vector<Task*>& getTasks();

    /**
     * setter for tasks
     *
     * @param tasks: collection of tasks (vector<Task*>&)
     */
    void setTasks(vector<Task*>& tasks);

    /**
     * adds a shelf to shelves
     *
     * @param shelf: shelf to be added (Shelf*)
     */
    void addShelf(Shelf* shelf);

    /**
     * getter for shelves
     *
     * @return collection of shelves (vector<Shelf*>&)
     */
    vector<Shelf*>& getShelves();

    /**
     * setter for shelves
     *
     * @param shelves: collection of shelves (vector<Shelf*>&)
     */
    void setShelves(vector<Shelf*>& shelves);
};


#endif //UNTITLED1_WAREHOUSE_H