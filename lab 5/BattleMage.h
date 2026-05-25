#ifndef BATTLEMAGE_H
#define BATTLEMAGE_H

#include "character.h"
#include "Warrior.h"
#include "Mage.h"
#include <string>
using namespace std;

class BattleMage : public Warrior, public Mage
{
public:
    BattleMage(string n, int l, int h, int ap,
               int str, int m);

    ~BattleMage();

    void performAttack() override;
    void MakeDamage() override;
    void displayInfo() override;
};

#endif