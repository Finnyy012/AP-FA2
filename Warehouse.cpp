//
// Created by Finn on 20/05/2022.
//

#include "Warehouse.h"
#include "RearrangeShelf.h"

Warehouse::Warehouse() {
    Warehouse::employees = vector<Employee*>();
    Warehouse::shelves = vector<Shelf*>();
    Warehouse::tasks = vector<Task*>();
}

vector<Task*>& Warehouse::getTasks(){
    return tasks;
}

void Warehouse::setTasks(vector<Task*> &tasks) {
    Warehouse::tasks = tasks;
}

vector<Employee*>& Warehouse::getEmployees(){
    return employees;
}

void Warehouse::setEmployees(vector<Employee*>& employees) {
    Warehouse::employees = employees;
}

vector<Shelf*> &Warehouse::getShelves(){
    return shelves;
}

void Warehouse::setShelves(vector<Shelf*>& shelves) {
    Warehouse::shelves = shelves;
}

void Warehouse::addEmployee(Employee* employee) {
    Warehouse::employees.push_back(employee);
}

void Warehouse::addTask(Task* task) {
    Warehouse::tasks.push_back(task);
}

void Warehouse::addShelf(Shelf* shelf) {
    Warehouse::shelves.push_back(shelf);
}

int Warehouse::getTotalTaskStatus() {   //heb de functie veranderd naar hoe het naar mijn mening het meest nuttig is;
                                        //nu returnt het het aantal tasks die niet finished zijn
    int res = 0;
    for(Task* task : tasks){
        if(task->getTaskStatus()!=finished){
            res++;
        }
    }
    return res;
}

TaskStatus Warehouse::performOneTask(int taskID, Employee* employee) { //het leek me beter als performAllTasks() de employee uitzoekt
    if(employee->isBusy()){return failed;}
    for(Task* t : tasks){
        if(t->getTaskStatus()!=finished && t->getId() == taskID){
            auto res = (TaskStatus)t->runTask(*employee, shelves);
            t->setTaskStatus(res);
            return res;
        }
    }
    return failed;
}

TaskStatus Warehouse::performAllTasks() {
    int status = getTotalTaskStatus();
    for(Task* task : tasks){
        if(task->getTaskStatus()!=finished){
            for(Employee* employee : employees){
                try {
                    RearrangeShelf& t = dynamic_cast<RearrangeShelf&> (*task);
                    if(!employee->isBusy() && employee->hasForkLiftCertificate()) {
                        employee->setBusy(true);
                        performOneTask(task->getId(), employee);
                    }
                } catch(bad_cast&) {
                    if(!employee->isBusy()) {
                        employee->setBusy(true);
                        performOneTask(task->getId(), employee);  //gewoon een pointer naar de task passen lijkt me
                                                                        //beter hier maar zo staat het in de opdracht
                    }
                }
            }
        }
    }
    for(Employee* employee : employees){
        employee->setBusy(false);
    }
    if(getTotalTaskStatus()!=0 && status!=getTotalTaskStatus()){
        performAllTasks();
    }
    if(getTotalTaskStatus()==0) {return finished;}
    return failed;
}


