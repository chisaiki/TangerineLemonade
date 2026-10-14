#include "libraries.h"
#include "gamefunctions.h"
#include "gameStruct.h"


void applyAction(GameState& s, Action a);

int main(){
    GameState newcharacter;
    Action action;

    startInfo();
    
    while (std::cin >> action){
        switch (action)
        {
            case Action::Quit:
                std::cout << "...Exiting Game...";
                exit(0);
                
            // make lemonade 
            case Action::Make:{
                if(!makeLemonade(newcharacter.lemons, newcharacter.sugar, newcharacter.stock)){
                    std::cout << "Not enough inventory!";
                }
                else{
                    std::cout << "Added lemonade to inventory!" << std::endl;
                }
                break;
            }
            
            // display stock
            case Action::Display:{
                std::cout << "~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "Lemons: " << newcharacter.lemons << std::endl;
                std::cout << "Sugar: " << newcharacter.sugar << std::endl;
                std::cout << "Stock: " << newcharacter.stock << std::endl;
                std::cout << "Money: $" << newcharacter.money << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~" << std::endl;

                break;
            }

            // sell lemonade
            case Action::Sell:{
                if (newcharacter.stock > 0){
                    std::cout << "SOLD!" << std::endl;
                    generateCustomers(newcharacter.stock, newcharacter.money);
                }
                else{
                    std::cout << "Out of lemonade!" << std::endl;
                }
                
                break;
            }
            
        }

    }
    

}