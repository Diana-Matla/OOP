#ifndef ICEMAGE_H
#define ICEMAGE_H

#include "Mage.h"
#include <string>
using namespace std;

class IceMage : public Mage
{
public:
    IceMage(string n, int l, int h, int ap, int m);
    void performAttack() override;
    void MakeDamage()override;
     void performAttack(int bonusDamage);
    void displayInfo();
};

#endif