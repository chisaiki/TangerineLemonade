#include <iostream>
#include "source.h"

int main(){

    int lemons = 5;
    int sugar = 5;
    int stock = 0;
    double money = 0;

    char actions;
    
    while (std::cin >> actions){
        switch (actions)
        {
            case 'q':
                std::cout << "...Exiting Game...";
                exit(0);
                
            // make lemonade 
            case 'm':{
                if(!makeLemonade(lemons, sugar, stock)){
                    std::cout << "Not enough inventory!";
                }
                else{
                    std::cout << "Added lemonade to inventory!" << std::endl;
                }
                break;
            }
            
            // display stock
            case 'd':{
                std::cout << "~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "Lemons: " << lemons << std::endl;
                std::cout << "Sugar: " << sugar << std::endl;
                std::cout << "Stock: " << stock << std::endl;
                std::cout << "Money: $" << money << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~" << std::endl;

                break;
            }

            // sell lemonade
            case 's':{
                if (stock > 0){
                    std::cout << "SOLD!" << std::endl;
                    stock--;
                    money += 2.75;
                }
                else{
                    std::cout << "Out of lemonade!" << std::endl;
                }
                
                break;
            }
            
        }

    }
    

}