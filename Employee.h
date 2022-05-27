//
// Created by Finn on 20/05/2022.
//

#ifndef UNTITLED1_EMPLOYEE_H
#define UNTITLED1_EMPLOYEE_H

#include <string>

using namespace std;


class Employee {
private:
    const int id;
    string name; //iemand zou zijn naam moeten kunnen veranderen; dit zou niet immutable moeten zijn
    bool busy;
    bool forkLiftCertificate;

public:
    /**
     * constructor for Employee
     *
     * @param id: employee ID (int)
     * @param name: employee name (string&)
     * @param forkLiftCertificate: true if employee has a forklift certificate (bool)
     */
    Employee(int id, string& name, bool forkLiftCertificate);

    /**
     *  getter for id
     * @return employee ID (int)
     */
    int getId();

    /**
     * getter for name
     * @return employee ID (string&)
     */
    string& getName();

    /**
     * setter for name
     * @param name: updated name
     */
    void setName(string& name);

    /**
     * getter for busy
     * @return busy status (bool)
     */
    bool isBusy();

    /**
     * setter for busy
     * @param busy: updated busy status (bool)
     */
    void setBusy(bool busy);

    /**
     * getter for forkLiftCertificate
     * @return true if employee has a forklift certificate (bool)
     */
    bool hasForkLiftCertificate();

    /**
     * setter for forkLiftCertificate
     * @param forkLiftCertificate: updated certificate status (bool)
     */
    void setForkLiftCertificate(bool forkLiftCertificate);
};


#endif //UNTITLED1_EMPLOYEE_H
