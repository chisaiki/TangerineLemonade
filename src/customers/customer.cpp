#include "customer.h"
#include "gameStruct.h"


// Creates a customer with a weighted random type (factory function)
// then updates the game state, mostly its added to the queue
Customer makeCustomer(GameState& s){}

// Serves a customer, updates the game state, and returns the sale result
Sale serveCustomer(const Customer& c, GameState& s){}
