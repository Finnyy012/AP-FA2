//
// Created by Finn on 20/05/2022.
//

#include "Employee.h"

Employee::Employee(int id, string &name, bool forkLiftCertificate) :
    id(id), name(name), forkLiftCertificate(forkLiftCertificate), busy(false){}

int Employee::getId() {
    return id;
}

string &Employee::getName(){
    return name;
}

void Employee::setName(string& name) {
    Employee::name = name;
}

bool Employee::isBusy() {
    return busy;
}

void Employee::setBusy(bool busy) {
    Employee::busy = busy;
}

bool Employee::hasForkLiftCertificate(){
    return forkLiftCertificate;
}

void Employee::setForkLiftCertificate(bool forkLiftCertificate) {
    Employee::forkLiftCertificate = forkLiftCertificate;
}


