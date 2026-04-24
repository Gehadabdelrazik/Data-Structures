#ifndef ARRAY_H
#define ARRAY_H

#include "resident.h"
#include <iostream>
using namespace std;

class ResidentData {
private:
    Resident* ResidentDatabase;
    int capacity;
    int size;
public:
    ResidentData(int cap);
    ~ResidentData();

    void addResident( Resident value);

    Resident get(int index) const;

    int getSize();

    Resident* getData();
 
};

#endif