#include "weapon.h"

Weapon::Weapon(std::string Name, float R, std::string T, int TA, int S, int AP, int D)
{
    this->WeaponName=Name;
    this->Range=R;
    this->Type=T;
    this->TypeAttack=TA;
    this->WStrength=S;
    this->ArmourPenetration=AP;
    this->Damage=D;
}

Weapon::~Weapon()
{

}



std::string Weapon::getWeaponName()
{
    return WeaponName;
}
float Weapon::getRange()
{
    return Range;
}
std::string Weapon::getType()
{
    return Type;
}
int Weapon::getTypeAttack()
{
    return TypeAttack;
}
int Weapon::getWStrength()
{
    return WStrength;
}
int Weapon::getArmourPenetration()
{
    return ArmourPenetration;
}
int Weapon::getDamage()
{
    return Damage;
}
