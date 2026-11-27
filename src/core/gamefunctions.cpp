#include "gamefunctions.h"
#include "gameStruct.h"
#include "../customers/customer.h"

#include <random> // Used for random number generation (mt19937 and random_device)


void startInfo(){
    std::cout << "--- Welcome To L'Quackies Lemonade! ---" << std::endl;
    std::cout << "Available Options: \n" << "1: Display Inventory \n" << "2: Make Lemonade \n" << 
    "3: Sell Lemonade \n" << "4: Quit Game \n";  
}

bool makeLemonade(int& total_lemons, int& total_sugar, int& stock){

    if (total_lemons < 1 || total_sugar < 1){
        std::cout << "Not enough inventory!" << std::endl;        
        return false;
    }

    total_lemons--;
    total_sugar--;
    stock++;

    std::cout << "Added lemonade to inventory!" << std::endl;
    return true;

}

/*Requires gamestate struct to exist*/
void sellLemonade(GameState& s){

    if (s.inventory.stock <= 0){
        std::cout << "Out of lemonade!" << std::endl;
        return;
    }

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "Sold to " << s.customer_arrivals.front().archetype->name << "!"<< std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    // so adding price up at a constant rate is not including the tip amount
    // i need make a seperate function to calculate tip and final profit made
    //serveCustomer(s);
    
    s.inventory.stock--;
    s.money += 2.75;
    s.money += s.customer_arrivals.front().archetype->tip_multiplier;

    std::cout << s.customer_arrivals.front().archetype->tip_lines[0] << std::endl; 

    s.customer_arrivals.pop_front();
    
    return;
}


void displayInfo(const GameState& game_block){
                std::cout << "~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "Lemons: " << game_block.inventory.lemons << std::endl;
                std::cout << "Sugar: " << game_block.inventory.sugar << std::endl;
                std::cout << "Stock: " << game_block.inventory.stock << std::endl;
                std::cout << "Money: $" << game_block.money << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}


void applyAction(GameState& s, Action a){
    if (a == Action::Display){
        displayInfo(s);
    }
    else if (a == Action::Make){
        makeLemonade(s.inventory.lemons, s.inventory.sugar, s.inventory.stock);
    }
    else if (a == Action::Sell){
        sellLemonade(s);
    }
}


std::istream& operator>>(std::istream& in, Action& action) {
    int choice;

    if (in >> choice) {
        if (choice >= 1 && choice <= 4) {
            action = static_cast<Action>(choice);
        } else {
            in.setstate(std::ios::failbit);
        }
    }

    return in;
}