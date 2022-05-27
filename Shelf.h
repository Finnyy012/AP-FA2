//
// Created by Finn on 20/05/2022.
//

#ifndef UNTITLED1_SHELF_H
#define UNTITLED1_SHELF_H

#include <ostream>
#include "IContainer.h"
#include "Pallet.h"

class Shelf : public IContainer{
private:
    const int id;
    array<Pallet*, 4> pallets;

public:
    /**
     * constructor for Shelf
     *
     * @param id: shelf ID (int)
     */
    Shelf(int id);

    /**
     * getter for id
     *
     * @return shelf ID (int)
     */
    int getId();

    /**
     * @brief status of the slots in the shelf
     *
     * initialises an empty array of booleans, then iterates through the slots in the shelf and updates the respective
     * slot in the array of booleans to true iff there exists a pallet in this slot
     *
     * @return array with the status of slots in the shelf (array<bool, 4>)
     */
    array<bool, 4> getSlotStatus();

    /**
     * getter for pallets
     *
     * @return array od pallets (array<Pallet*, 4>&)
     */
    array<Pallet*, 4>& getPallets();

    /**
     * @brief removes the pallet at slot
     *
     * replaces the pointer in the array at the provided slot with a nullpointer, and returns the removed pallet
     *
     * @param slot: the slot of the pallet to be removed (int)
     *
     * @throws invalid_argument: if the provided slot is out of bounds (0 to 3),
     *                           or if there is no pallet at the provided slot
     *
     * @return the removed pallet (Pallet&)
     */
    Pallet& removePallet(int slot);

    /**
     * inserts a pallet at the provided slot.
     * returns false iff there is no pallet at the slot, returns true otherwise
     *
     * @param slot: slot where the pallet should be inserted (int)
     * @param pallet: pallet to be inserted (Pallet*)
     *
     * @return task result (bool)
     */
    bool insertPallet(int slot, Pallet* pallet);

    /**
     * returns true iff all slots are empty (when all pointers in pallets are nullptr)
     * overrides isEmpty() from IContainer
     *
     * @return empty status (bool)
     */
    bool isEmpty() override;

    /**
     * returns true iff all slots contain a pallet (when no pointers in pallets are nullptr)
     * overrides isFull() from IContainer
     *
     * @return empty status (bool)
     */
    bool isFull() override;

    /**
     * @brief sorts the pallets in the shelf on number of items, ascending
     *
     * the function uses insertion sort to sort all the pallets in the shelf on number of items, in ascending order.
     * empty slots (nullptr) will be placed at the start of the shelf.
     */
    void sortPallets();

    /**
     * Stream output operator
     */
    friend ostream &operator<<(ostream &os, const Shelf &shelf);
};


#endif //UNTITLED1_SHELF_H
