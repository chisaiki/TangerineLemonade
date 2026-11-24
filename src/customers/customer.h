#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "customerArchetype.h"

struct GameState;   // "a struct with this name exists; details later"

struct Customer {
    const CustomerArchetype* archetype; /*Just a vector*/
    int order_amount;
    double patience;
};

struct Sale { 
    double money; 
    std::string message; 
};



// Creates a customer with a weighted random type (factory function)
// then updates the game state, mostly its added to the queue
Customer makeCustomer(GameState& s);

// Serves a customer, updates the game state, and returns the sale result
Sale serveCustomer(const Customer& c, GameState& s);


#endif 