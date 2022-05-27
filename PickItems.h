//
// Created by Finn on 20/05/2022.
//

#ifndef UNTITLED1_PICKITEMS_H
#define UNTITLED1_PICKITEMS_H

#include "Task.h"
#include "Employee.h"

class PickItems : public Task {
private:
    string itemName;
    int itemCount;

public:
    /**
     * constructor for PickItems
     *
     * @param id: task ID (int)
     * @param itemName: name of item to be picked (string&)
     * @param itemCount: amount of item to be picked (int)
     */
    PickItems(int id, string& itemName, int itemCount);

    /**
     * getter for itemName
     *
     * @return item name (string&)
     */
    string& getItemName();

    /**
     * getter for itemCount
     *
     * @return item count (int)
     */
    int getItemCount();

    /**
     * @brief takes items from pallets
     *
     * iterates through all pallets in the provided vector, until enough items are counted.
     * then it iterates through all pallets that hold the provided item to remove items until (itemCoun) items have been removed.
     * returns true iff there are enough instances of the named item in pallets throughout the warehouse, returns false otherwise.
     *
     * @param employee: employee to perform the task (Employee&)
     * @param shelves: collection of shelves to be searched (vector<Shelf*>&)
     *
     * @return task result (bool)
     */
    bool runTask(Employee& employee, vector<Shelf*>& shelves) override;
    //staat een fout in de opdracht: er staat als enige parameter `Employee& employee`, terwijl bij de functie die het
    //overridet in de opdracht als parameters `Employee& employee` en `vector<Shelf*>&` shelves staat
};


#endif //UNTITLED1_PICKITEMS_H
