#include "array.h"
#include "resident.h"

ResidentData::ResidentData(int cap) 
{

    capacity = cap;
    size = 0;
    ResidentDatabase = new Resident[capacity];

}

ResidentData::~ResidentData()
{
    delete[] ResidentDatabase;
}

void ResidentData::addResident(Resident value)
{
    if (size < capacity) {
        ResidentDatabase[size++] = value;
    }
    else { cout << "Array is full" << endl; }
}

Resident ResidentData::get(int index) const {
    return ResidentDatabase[index];
}

int ResidentData::getSize()
{
    return size;
}

 Resident* ResidentData::getData()
{
    return ResidentDatabase;
}
