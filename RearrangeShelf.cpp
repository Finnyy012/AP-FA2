//
// Created by Finn on 20/05/2022.
//

#include "RearrangeShelf.h"

RearrangeShelf::RearrangeShelf(int id, int shelfId) : Task(id, true, 0), shelfID(shelfId) {}

int RearrangeShelf::getShelfId() {
    return shelfID;
}

bool RearrangeShelf::runTask(Employee& employee, vector<Shelf*>& shelves) {
    if(!employee.hasForkLiftCertificate()){return false;}
    Shelf* shelf = nullptr;
    for(Shelf* s : shelves){
        if(s->getId()==shelfID){
            shelf = s;
            break;
        }
    }
    if(shelf==nullptr){return false;}
    shelf->sortPallets(); //het daadwerkelijke algoritme staat in Shelf; dit leek mij efficienter
    return true;
}


