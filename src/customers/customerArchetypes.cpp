#include "customerArchetype.h"

const std::vector<CustomerArchetype> all_archetypes = {
    { "Normal",    1.0, 15, 25, 2, { "Hi there!" },       { "Forget it." } },
    { "BigTipper", 3.0, 20, 30, 3, { "Keep the change!" }, { "Shame..." } },
    { "Karen",     0.5,  8, 12, 1, { "I'm in a hurry." },  { "Manager. Now." } },
};

    // std::string name;
    // double tipMultiplier;
    // double patienceMin, patienceMax;
    // int    maxCups;
    // std::vector<std::string> greetings;
    // std::vector<std::string> angryLines;