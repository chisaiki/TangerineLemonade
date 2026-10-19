#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "libraries.h"
#include "gameStruct.h"
#include "customerArchetype.h"

struct Customer {
    const CustomerArchetype* archetype;
    int order_amount;
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