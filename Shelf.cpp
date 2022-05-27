//
// Created by Finn on 20/05/2022.
//

#include <iostream>
#include "Shelf.h"

Shelf::Shelf(int id) : id(id){
    Shelf::pallets = {nullptr};
}

int Shelf::getId() {
    return id;
}

bool Shelf::isEmpty() {
    return array<bool, 4> {false} == getSlotStatus();
}

bool Shelf::isFull() {
    return array<bool, 4> {true} == getSlotStatus();
}

array<Pallet*, 4> &Shelf::getPallets() {
    return pallets;
}

Pallet& Shelf::removePallet(int slot) {
    if(pallets[slot]==nullptr || slot>3 || slot<0){throw invalid_argument("No pallet at this slot");}
    Pallet* pallet = pallets[slot];
    pallets[slot] = nullptr;
    Pallet& res = *pallet;
    return res;
}

bool Shelf::insertPallet(int slot, Pallet* pallet) {
    if(pallets[slot]!=nullptr){return false;}
    pallets[slot] = pallet;
    return true;
}

array<bool, 4> Shelf::getSlotStatus() {
    array<bool, 4> res = {};
    for(int i=0; i<4; i++){
        if(pallets[i]!=nullptr){
            res[i] = true;
        }
    }
    return res;
}

void Shelf::sortPallets() {
    Pallet* temp;
    for(int i=0; i<3; i++){
        if(pallets[i]!=nullptr && (pallets[i+1]==nullptr || pallets[i]->getItemCount()>pallets[i+1]->getItemCount())){
            temp = pallets[i];
            pallets[i] = pallets[i+1];
            pallets[i+1] = temp;
            for(int j=i; j>0; j--) {
                if(pallets[j-1]!=nullptr && (pallets[j]->getItemCount()<pallets[j-1]->getItemCount())){
                    temp = pallets[j];
                    pallets[j] = pallets[j-1];
                    pallets[j-1] = temp;
                } else {break;}
            }
        }
    }
}

ostream &operator<<(ostream &os, const Shelf &shelf) {
    os << "id: " << shelf.id << " pallets: " << endl;
    for(Pallet* i : shelf.pallets) {
        if(i){
            os << " - "<< *i << endl;
        } else {os << " - empty slot" << endl;}
    }
    return os;
}


