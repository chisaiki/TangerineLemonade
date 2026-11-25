#include "core/gamefunctions.h"
#include "core/gameStruct.h"
#include "customers/customer.h"


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
                applyAction(newcharacter, Action::Make);
                
                // only adding it here so the game has an ending
                makeCustomer(newcharacter);
                break;
            }
            
            // display stock
            case Action::Display:{
                applyAction(newcharacter, Action::Display);
                break;
            }

            // sell lemonade
            case Action::Sell:{
                
                if(newcharacter.customer_arrivals.empty()){
                    std::cout << "There's no customers to sell to! (-_-;)" << std::endl;
                }
                
                else{
                    applyAction(newcharacter, Action::Sell);
                }
                
                break;
            }
            
        }

        if (!newcharacter.customer_arrivals.empty()){
            
            std::cout << "[ ";
            for (int i = 0; i < newcharacter.customer_arrivals.size(); i++){
                std::cout << newcharacter.customer_arrivals[i].archetype->name << " | ";
            }

            std::cout << " ]" << std::endl;
        }
        else{
            std::cout << "[             ...(@)...             ]" << std::endl;
        }

    }
    

}