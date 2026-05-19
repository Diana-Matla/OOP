#ifndef ULTIMATEHERO_H
#define ULTIMATEHERO_H

#include "character.h"
#include "Warrior.h"
#include "Archer.h"
#include "Mage.h"
#include <string>
using namespace std;

class UltimateHero : public Warrior, public Mage, public Archer
{
public:
    UltimateHero(string n, int l, int h, int ap, int str, int m, int dist);

    void performAttack() override; 
    void MakeDamage()override;
    void displayInfo() override;
    ~UltimateHero();
};

#endif