#include "customer.h"
#include "../core/gameStruct.h"
#include <iostream>


// Creates a customer with a weighted random type (factory function)
// then updates the game state, mostly its added to the queue
Customer makeCustomer(GameState& s){
    // pick a random type but "Normal" is more likely than the rest

    // Collect each archetype's weight, in the SAME order as all_archetypes.
    // loop over all_archetypes and gather each type's weight into a list, in table order.
    std::vector<double> weights;
    for (const CustomerArchetype& a : all_archetypes) {
        weights.push_back(a.spawn_weight);
    }

    // discrete_distribution returns an index (0, 1, 2...) picked in
    // proportion to the weights. Rolling it with s.rng gives that index.
    std::discrete_distribution<std::size_t> pickType(weights.begin(), weights.end());
    const CustomerArchetype& type = all_archetypes[pickType(s.rng)];

    // Roll this customer's stats using the chosen type's rules.
    std::uniform_real_distribution<double> rollPatience(type.patience_min, type.patience_max);
    std::uniform_int_distribution<int>     rollCups(1, type.max_cups);

    // Build the customer (fields in struct order: archetype, order_amount, patience).
    // &type points at the entry inside all_archetypes, not a copy.
    Customer c{ &type, rollCups(s.rng), rollPatience(s.rng) };

    s.customer_arrivals.push_back(c);

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << " (^o^) Riiing. Customer has arrived!" << std::endl;
    std::cout << type.greetings[0] << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;


    return c;
}

// Serves a customer, updates the game state, and returns the sale result
//Sale serveCustomer(GameState& s){}
