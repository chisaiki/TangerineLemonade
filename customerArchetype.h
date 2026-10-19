#ifndef CUSTOMER_ARCHETYPE
#define CUSTOMER_ARCHETYPE

#include "libraries.h"

struct CustomerArchetype {
    std::string name;
    double tipMultiplier;
    double patienceMin, patienceMax;
    int    maxCups;
    std::vector<std::string> greetings;
    std::vector<std::string> angryLines;
};

#endif