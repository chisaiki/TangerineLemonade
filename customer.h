#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "libraries.h"
#include "gameStruct.h"

struct Customer {
    const CustomerArchetype* archetype;
    int wants;
    double patience;
};

struct Sale { 
    double money; 
    std::string message; 
};

// Creates a customer with a weighted random type (factory function)
Customer makeCustomer(GameState& s);

// Serves a customer, updates the game state, and returns the sale result
Sale serveCustomer(const Customer& c, GameState& s);


#endif 