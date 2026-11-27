#include "customerArchetypes.h"

const std::vector<CustomerArchetype> all_archetypes = {
    // Keep "Normal" first: it's used as the default type.
    //  name        weight tip  patience  cups
    { "Normal",    50,   0.5, 15, 25, 2, { "Hi there." }, {"Thanks."} ,{ "Forget it." } },
    { "BigTipper", 15,   1.5, 20, 30, 3, { "Feeling really good today!" }, {"Something extra for you!"}, { "Shame..." } },
    { "Karen",     35,   -1.0,  8, 12, 1, { "I'm in a hurry." }, {"I don't tip. This is literally your job."}, { "Manager. Now." } },
};

    // std::string name;
    // double tipMultiplier;
    // double patienceMin, patienceMax;
    // int    maxCups;
    // std::vector<std::string> greetings;
    // std::vector<std::string> angryLines;