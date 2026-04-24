#ifndef RESIDENT_H
#define RESIDENT_H

#include <string>
using namespace std;


// structure definition
struct Resident{

    string ResidentID;
    string ModeOfTransport;
    int Age;
    int AverageDayPerMonth;
    float DailyDistance;
    float CarbonEmissionFactor;
};

#endif 