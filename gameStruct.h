#ifndef GAME_STRUCT_H
#define GAME_STRUCT_H

#include <string> 
#include <vector>
#include <random> // Used for random number generation (mt19937 and random_device)

struct Inventory {
    int lemons = 10;
    int sugar  = 10;
    int stock  = 0;
};

struct GameState {
    Inventory inventory;
    double money = 0;
    int day = 1;

    std::mt19937 rng{std::random_device{}()};   // one RNG, created once
    std::vector<std::string> log;               // messages for the UI to show
};


// struct GameState {
//     int lemons = 10;
//     int sugar = 10;
//     int stock = 0;
//     double money = 0;
//     int day = 1;


    
// };

#endif