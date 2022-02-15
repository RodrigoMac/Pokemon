//#include "Pokemon.h"
#include "Pokemon/Squirtle.h"
#include "Pokemon/Bulbassauro.h"
#include "Pokemon/Charmander.h"

#include <iostream>

int main(){

    Charmander carlinhos("Carlinhos", 10);
    Bulbassauro berenice("Berenice", 7);
    Squirtle squirtle("Squirtle", 12);

    carlinhos.Attack(berenice);
    carlinhos.Attack(squirtle);

    squirtle.Attack(berenice);

    return 0;
}