//
// Created by Finn on 24/05/2022.
//

//#include <iostream>
//#include "Warehouse.h"
//#include "PickItems.h"
//#include "RearrangeShelf.h"
//
//
//int main(){
//    Warehouse res = Warehouse();
//
//    string name1 = "name1";
//    string name2 = "name2";
//    string name3 = "name3";
//    string name4 = "name4";
//    string name5 = "name5";
//
//    PickItems pick_items1 = PickItems(1,name1,5);
//    PickItems pick_items2 = PickItems(2,name1,10);
//    RearrangeShelf rearrange_shelf1 = RearrangeShelf(3, 1);
//    RearrangeShelf rearrange_shelf2 = RearrangeShelf(4, 2);
//    RearrangeShelf rearrange_shelf3 = RearrangeShelf(5, 3);
//
//    Employee employee1 = Employee(1, name1, true);
//    Employee employee2 = Employee(2, name2, false);
//    Employee employee3 = Employee(3, name3, true);
//
//    Pallet pallet1 = Pallet(1, 0, name1, 10);
//    Pallet pallet2 = Pallet(2, 1, name2, 10);
//    Pallet pallet3 = Pallet(3, 3, name3, 10);
//    Pallet pallet4 = Pallet(4, 7, name1, 10);
//    Pallet pallet5 = Pallet(5, 2, name4, 10);
//
//    res.addTask(&pick_items1);
//    res.addTask(&pick_items2);
//    res.addTask(&rearrange_shelf1);
//    res.addTask(&rearrange_shelf2);
//    res.addTask(&rearrange_shelf3);
//
//    res.addEmployee(&employee1);
//    res.addEmployee(&employee2);
//
//    Shelf shelf1 = Shelf(1);
//    Shelf shelf2 = Shelf(2);
//    Shelf shelf3 = Shelf(3);
//    shelf1.insertPallet(2, &pallet1);
//    shelf1.insertPallet(3, &pallet2);
//    shelf2.insertPallet(0, &pallet3);
//    shelf2.insertPallet(2, &pallet4);
//    shelf2.insertPallet(3, &pallet5);
//
//    res.addShelf(&shelf1);
//    res.addShelf(&shelf2);
//    res.addShelf(&shelf3);
//
//    cout<<shelf2;
//}