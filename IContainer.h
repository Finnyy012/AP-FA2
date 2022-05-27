//
// Created by Finn on 20/05/2022.
//

#ifndef UNTITLED1_ICONTAINER_H
#define UNTITLED1_ICONTAINER_H

#include <stdexcept>
#include <string>
#include <vector>
#include <array>

using namespace std;

class IContainer {
public:
    virtual bool isEmpty()=0;
    virtual bool isFull()=0;
};


#endif //UNTITLED1_ICONTAINER_H
