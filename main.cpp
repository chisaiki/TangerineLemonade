#include "libraries.h"
#include "gamefunctions.h"


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
                break;
            }
            
            // display stock
            case Action::Display:{
                applyAction(newcharacter, Action::Display);
                break;
            }

            // sell lemonade
            case Action::Sell:{
                applyAction(newcharacter, Action::Sell);
                break;
            }
            
        }

    }
    

}