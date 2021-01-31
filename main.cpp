#include <iostream>
#include <ctime>

#include "dice.h"
#include "army.h"

using namespace std;

int main()
{
    srand(unsigned(time(NULL)));

    Army DOM("TaticalSquad",4, "SpaceMarines",4, 6.0, 3, 3, 4, 4, 1, 1, 7, 3);

    DOM.AdvanceMovement(false, DOM);
    std::cout<<DOM.getUnitName()<<", "<<DOM.getProfileName()<<" Moves "<<DOM.getMovement()<<" spaces";
    std::cout<<std::endl<<std::endl<<std::endl;
    DOM.AdvanceMovement(true, DOM);
    std::cout<<DOM.getUnitName()<<", "<<DOM.getProfileName()<<" Moves "<<DOM.getMovement()<<" spaces";
    std::cout<<std::endl;

    return 0;
}
