#include "gamefunctions.h"

void startInfo(){
    std::cout << "--- Welcome To L'Quackies Lemonade! ---" << std::endl;
    std::cout << "Available Options: \n" << "d: Display Inventory \n" << "m: Make Lemonade \n" << 
    "s: Sell Lemonade \n" << "q: Quit Game \n";  
}

bool makeLemonade(int& total_lemons, int& total_sugar, int& stock){

    if (total_lemons < 1 || total_sugar < 1){
        return false;
    }

    total_lemons--;
    total_sugar--;
    stock++;

    return true;

}

void generateCustomers(int& stock, double& money){

    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Set the range from 1 to 10 (inclusive)
    std::uniform_int_distribution<> distr(1, stock);

    // Generate 
    int num_of_customers = distr(gen);

    std::cout << num_of_customers << " has arrived!" << std::endl;

    for (int i = 0; i < num_of_customers; i++){

        std::cout << "Now serving customer #" << i << std::endl;

        stock--;
        money += 2.75;
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