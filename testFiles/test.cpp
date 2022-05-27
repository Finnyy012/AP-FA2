//
// Created by Finn on 23/05/2022.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "createTestWarehouse.h"

//TEST_CASE() {
//    Warehouse warehouse = create();
//    REQUIRE();
//}

TEST_CASE("perform task - rearrange shelf - no forklift") {
    Warehouse warehouse = create();
    REQUIRE(warehouse.performOneTask(3,warehouse.getEmployees()[1])==false);
}

TEST_CASE("perform task - rearrange shelf - success") {
    Warehouse warehouse = create();
    warehouse.performOneTask(4,warehouse.getEmployees()[0]);
    REQUIRE(warehouse.getShelves()[1]->getPallets()[0]==nullptr);
    REQUIRE(warehouse.getShelves()[1]->getPallets()[1]->getId()==5);
    REQUIRE(warehouse.getShelves()[1]->getPallets()[2]->getId()==3);
    REQUIRE(warehouse.getShelves()[1]->getPallets()[3]->getId()==4);
}

TEST_CASE("perform task - rearrange shelf - no change") {
    Warehouse warehouse = create();
    warehouse.performOneTask(3,warehouse.getEmployees()[0]);
    REQUIRE(warehouse.getShelves()[0]->getSlotStatus() == array<bool, 4> {false, false, true, true});
    REQUIRE(warehouse.getShelves()[0]->getPallets()[0] == nullptr);
    REQUIRE(warehouse.getShelves()[0]->getPallets()[1] == nullptr);
    REQUIRE(warehouse.getShelves()[0]->getPallets()[2]->getId() == 1);
    REQUIRE(warehouse.getShelves()[0]->getPallets()[3]->getId() == 2);
}

TEST_CASE("perform task - rearrange shelf - nullptr") {
    Warehouse warehouse = create();
    warehouse.performOneTask(5,warehouse.getEmployees()[0]);
    REQUIRE(warehouse.getShelves()[3]->getPallets() == array<Pallet*, 4> {nullptr});
}

TEST_CASE("perform task - pickitems") {
    Warehouse warehouse = create();
    warehouse.performOneTask(1,warehouse.getEmployees()[0]);
}

