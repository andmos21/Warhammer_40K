#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon
{
private:
    std::string WeaponName;
    float Range;
    std::string Type;
    int TypeAttack;
    int WStrength;
    int ArmourPenetration;
    int Damage;
public:
    Weapon(std::string, float, std::string, int, int, int, int);
    ~Weapon();
    std::string getWeaponName();
    float getRange();
    std::string getType();
    int getTypeAttack();
    int getWStrength();
    int getArmourPenetration();
    int getDamage();
};

#endif // WEAPON_H
