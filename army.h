#ifndef ARMY_H
#define ARMY_H

#include <iostream>
#include <string>


class Army
{
private:
    std::string UnitName;
    std::string ProfileName;
    int PowerRating;
    int UnitSize;
    float Move;
    int WeaponSkill;
    int BallisticSkill;
    int Strength;
    int Thoughness;
    int Wounds;
    int Attacks;
    int Leadership;
    int Save;
public:
    Army(std::string UN, int PR, std::string PN,int US, float M, int WS, int BS, int S, int T, int W, int A, int Ld, int Sv);
    ~Army();
    int AdvanceMovement(bool checkAdvance, Army army);

    std::string getProfileName();
    std::string getUnitName();
    int getPowerRating();
    int getUnitSize();
    float getMovement();
    int getWeaponSkill();
    int getBallisticSkill();
    int getStrength();
    int getThoughness();
    int getWounds();
    int getAttacks();
    int getLeadership();
    int getSave();
};

#endif // ARMY_H
