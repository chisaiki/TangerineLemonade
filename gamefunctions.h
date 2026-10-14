#ifndef GAME_FUNCS
#define GAME_FUNCS

#include "libraries.h"
#include "gameStruct.h"

enum class Action { Display = 1, Make, Sell, Quit };

std::istream& operator>>(std::istream& in, Action& action);

void startInfo();

bool makeLemonade(int& total_lemons, int& total_sugar, int& stock);

void generateCustomers(int& stock, double& money);

void displayInfo(const GameState& game_block);

void applyAction(GameState& s, Action a);



#endif

