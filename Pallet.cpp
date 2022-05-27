//
// Created by Finn on 20/05/2022.
//

#include "Pallet.h"

Pallet::Pallet(int id, int itemCount, string& itemName, int itemCapacity) :
                id(id), itemCount(itemCount), itemName(itemName), itemCapacity(itemCapacity){}

bool Pallet::isEmpty() {
    return itemCount==0;
}

bool Pallet::isFull() {
    return itemCount==itemCapacity;
}

int Pallet::getId() {
    return id;
}

int Pallet::getItemCount() {
    return itemCount;
}

string &Pallet::getItemName() {
    return itemName;
}

int Pallet::getRemainingSpace() {
    return itemCapacity-itemCount;
}

void Pallet::reallocateEmptyPallet(string& itemName, int itemCapacity) {
    if(!isEmpty()){throw domain_error("non-empty pallets cannot be reallocated");}
    Pallet::itemName = itemName;
    Pallet::itemCapacity = itemCapacity;
}

bool Pallet::takeOne() {
    if(!itemCount){     //ik weet dat ik ook isEmpty() had kunnen aanroepen maar de duplicate code die daarmee wordt
                        // vermeden is letterlijk een statement. dit zou ook efficienter moeten zijn
        itemCount--;
        return true;
    }
    return false;
}

bool Pallet::putOne() {
    if(itemCount!=itemCapacity){
        itemCount++;
        return true;
    }
    return false;
}

ostream &operator<<(ostream &os, const Pallet &pallet) {
    os << "id: " << pallet.id << " itemCount: " << pallet.itemCount
       << " itemName: " << pallet.itemName << " itemCapacity: " << pallet.itemCapacity;
    return os;
}


