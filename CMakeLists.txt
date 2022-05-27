cmake_minimum_required(VERSION 3.22)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled1 Warehouse.cpp Warehouse.h Task.cpp Task.h Employee.cpp Employee.h Shelf.cpp Shelf.h RearrangeShelf.cpp RearrangeShelf.h PickItems.cpp PickItems.h IContainer.cpp IContainer.h Pallet.cpp Pallet.h testFiles/test.cpp testFiles/createTestWarehouse.cpp testFiles/createTestWarehouse.h main.cpp)
