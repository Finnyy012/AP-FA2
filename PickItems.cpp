//
// Created by Finn on 20/05/2022.
//

#include "PickItems.h"

PickItems::PickItems(int id, string& itemName, int itemCount)
        : Task(id, false, 0), itemName(itemName), itemCount(itemCount) {}

string &PickItems::getItemName() {
    return itemName;
}

int PickItems::getItemCount() {
    return itemCount;
}

bool PickItems::runTask(Employee& employee, vector<Shelf*>& shelves) {
    vector<Pallet*> pallets;
    int acc = 0;
    for(Shelf* s : shelves) { //sorry voor de nested loops maar dit is iig naar mijn idee de efficientste manier om het te doen
        for (Pallet *p: s->getPallets()) {
            if(p!=nullptr && p->getItemName()==itemName){
                pallets.push_back(p);
                acc += p->getItemCount();
                if (acc >= itemCount) {
                    bool check;
                    for (Pallet* q: pallets) {
                        check = true;
                        while (check) {
                            check = q->takeOne();
                            if (check) {
                                itemCount--;
                                if (!itemCount) {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
