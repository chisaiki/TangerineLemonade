#include "source.h"

bool makeLemonade(int& total_lemons, int& total_sugar, int& stock){

    if (total_lemons < 1 || total_sugar < 1){
        return false;
    }

    total_lemons--;
    total_sugar--;
    stock++;

    return true;

}