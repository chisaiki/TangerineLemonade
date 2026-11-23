#ifndef CUSTOMER_ARCHETYPE_H
#define CUSTOMER_ARCHETYPE_H

#include <string>
#include <vector> 

struct CustomerArchetype {
    std::string name;
    double tip_multiplier;
    double patience_min, patience_max;
    int    max_cups;
    std::vector<std::string> greetings;
    std::vector<std::string> angry_lines;
};

extern const std::vector<CustomerArchetype> all_archetypes;

#endif

