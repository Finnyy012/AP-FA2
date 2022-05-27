//
// Created by Finn on 20/05/2022.
//

#ifndef UNTITLED1_PALLET_H
#define UNTITLED1_PALLET_H

#include <ostream>
#include "IContainer.h"

class Pallet : public IContainer {
private:
    const int id;
    int itemCount;
    string itemName;
    int itemCapacity;

public:
    /**
     * constructor for Pallet
     *
     * @param id: pallet ID (int)
     * @param itemCount: amount of items in pallet (int)
     * @param itemName: name of the item (string&)
     * @param itemCapacity: max amount of items in pallet (int)
     */
    Pallet(int id, int itemCount, string& itemName, int itemCapacity);

    /**
     * getter for id
     *
     * @return pallet id (int)
     */
    int getId();

    /**
     * getter for itemCount
     *
     * @return amount of items in pallet (int)
     */
    int getItemCount();

    /**
     * getter for itemName
     *
     * @return name of items in pallet (string&)
     */
    string& getItemName();

    /**
     * @brief returns space left in the pallet
     *
     * returns the amount of items that can still fit in the pallet (itemCapacity - itemCount)
     *
     * @return remaining space (int)
     */
    int getRemainingSpace();

    /**
     * @brief reallocate an empty pallet to hold a different item
     *
     * updates the name and capacity for the items in the pallet, but only if the pallet is empty
     * will throw domain_error if the pallet still contains any items (function is not defined for empty pallets).
     *
     * @param itemName: updated item name (string&)
     * @param itemCapacity: updated item capacity (int)
     *
     * @throws domain_error: if the pallet is not empty
     */
    void reallocateEmptyPallet(string& itemName, int itemCapacity);

    /**
     * returns true if the pallet is empty (itemCount equals 0)
     * overrides isEmpty() from IContainer
     *
     * @return: empty status (bool)
     */
    bool isEmpty() override;

    /**
     * returns true if the pallet is full (itemCount equals itemCapacity)
     * overrides isFull() from IContainer
     *
     * @return: empty status (bool)
     */
    bool isFull() override;

    /**
     * decrements itemCount by 1 iff itemCount does not equal 0
     * returns false if it fails, returns true otherwise
     *
     * @return task result (bool)
     */
    bool takeOne();

    /**
     * increments itemCount by 1 iff itemCount does not equal itemCapacity
     * returns false if it fails, returns true otherwise
     *
     * @return task result (bool)
     */
    bool putOne();

    /**
     * Stream output operator
     */
    friend ostream &operator<<(ostream &os, const Pallet &pallet);
};


#endif //UNTITLED1_PALLET_H
