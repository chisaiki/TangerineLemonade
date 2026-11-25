#ifndef GAME_FUNCS_H
#define GAME_FUNCS_H

#include <iostream>

struct GameState;

enum class Action { Display = 1, Make, Sell, Quit };

std::istream& operator>>(std::istream& in, Action& action);

void startInfo();

bool makeLemonade(int& total_lemons, int& total_sugar, int& stock);

void sellLemonade(GameState& s);

void displayInfo(const GameState& game_block);

void applyAction(GameState& s, Action a);



#endif
