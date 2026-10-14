#include "gamefunctions.h"

void startInfo(){
    std::cout << "--- Welcome To L'Quackies Lemonade! ---" << std::endl;
    std::cout << "Available Options: \n" << "1: Display Inventory \n" << "2: Make Lemonade \n" << 
    "3: Sell Lemonade \n" << "4: Quit Game \n";  
}

bool makeLemonade(int& total_lemons, int& total_sugar, int& stock){

    if (total_lemons < 1 || total_sugar < 1){
        std::cout << "Not enough inventory!";        
        return false;
    }

    total_lemons--;
    total_sugar--;
    stock++;

    std::cout << "Added lemonade to inventory!" << std::endl;
    return true;

}

void generateCustomers(int& stock, double& money){

    if (stock <= 0){
        std::cout << "Out of lemonade!" << std::endl;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Set the range from 1 to 10 (inclusive)
    std::uniform_int_distribution<> distr(1, stock);

    // Generate 
    int num_of_customers = distr(gen);

    std::cout << num_of_customers << " customer(s) has arrived!" << std::endl;

    for (int i = 1; i <= num_of_customers; i++){

        std::cout << "Now serving customer #" << i << std::endl;
        std::cout << "SOLD!" << std::endl;

        stock--;
        money += 2.75;
    }
}

void displayInfo(const GameState& game_block){
                std::cout << "~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "Lemons: " << game_block.lemons << std::endl;
                std::cout << "Sugar: " << game_block.sugar << std::endl;
                std::cout << "Stock: " << game_block.stock << std::endl;
                std::cout << "Money: $" << game_block.money << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}


void applyAction(GameState& s, Action a){
    if (a == Action::Display){
        displayInfo(s);
    }
    else if (a == Action::Make){
        makeLemonade(s.lemons, s.sugar, s.stock);
    }
    else if (a == Action::Sell){
        generateCustomers(s.stock, s.money);
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