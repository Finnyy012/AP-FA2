//
// Created by Finn on 20/05/2022.
//

#ifndef UNTITLED1_REARRANGESHELF_H
#define UNTITLED1_REARRANGESHELF_H

#include "Employee.h"
#include "Task.h"

class RearrangeShelf : public Task {
private:
    int shelfID;

public:
    /**
     * constructor for RearrangeShelf
     *
     * @param id: task ID (int)
     * @param shelfId: shelf ID (int)
     */
    RearrangeShelf(int id, int shelfId);

    /**
     * getter for shelfId
     * @return shelf ID (int)
     */
    int getShelfId();

    /**
     * @brief rearranges the pallets in a shelf, based on the number of items, in ascending order.
     *
     * rearranges the pallets in the specified shelf, according to a sorting algorithm implemented in Shelf.
     * returns false if assigned to an employee with no forklift certificate or if there exists no shelf with the
     * privided shelf ID, returns true otherwise.
     *
     * @param employee: employee to perform the task (Employee&)
     * @param shelves: collection of shelves to be searched (vector<Shelf*>&)
     *
     * @return task result (bool)
     */
    bool runTask(Employee& employee, vector<Shelf*> &shelves) override;
};


#endif //UNTITLED1_REARRANGESHELF_H
