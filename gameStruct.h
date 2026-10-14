#include "libraries.h"

struct GameState {
    int lemons = 10;
    int sugar = 10;
    int stock = 0;
    double money = 0;
    int day = 1;


    std::mt19937 rng{std::random_device{}()};   // one RNG, created once
    std::vector<std::string> log;               // messages for the UI to show
};
