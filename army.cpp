#include "army.h"
#include "dice.h"

Army::Army(std::string UN, int PR, std::string PN, int US, float M, int WS, int BS, int S, int T, int W, int A, int Ld, int Sv)
{
    this->UnitName=UN;
    this->PowerRating=PR;
    this->ProfileName=PN;
    this->UnitSize=US;
    this->Move=M;
    this->WeaponSkill=WS;
    this->BallisticSkill=BS;
    this->Strength=S;
    this->Thoughness=T;
    this->Wounds=W;
    this->Attacks=A;
    this->Leadership=Ld;
    this->Save=Sv;
}

Army::~Army()
{

}

int Army::AdvanceMovement(bool checkAdvance, Army army)
{
    Dice d6;

    float diceRoll= d6.roll();

    if(checkAdvance==false)
    {
        return army.getMovement();
    }
    else if(checkAdvance==true)
    {
        army.Move=army.getMovement()+diceRoll;
        return army.getMovement();
    }
    return army.getMovement();
}


std::string Army::getUnitName()
{
    return UnitName;
}
std::string Army::getProfileName()
{
    return ProfileName;
}
int Army::getPowerRating()
{
    return PowerRating;
}
int Army::getUnitSize()
{
    return UnitSize;
}
float Army::getMovement()
{
    return Move;
}
int Army::getWeaponSkill()
{
    return WeaponSkill;
}
int Army::getBallisticSkill()
{
    return BallisticSkill;
}
int Army::getStrength()
{
    return Strength;
}
int Army::getThoughness()
{
    return Thoughness;
}
int Army::getWounds()
{
    return Wounds;
}
int Army::getAttacks()
{
    return Attacks;
}
int Army::getLeadership()
{
    return Leadership;
}
int Army::getSave()
{
    return Save;
}
