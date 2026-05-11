#ifndef FIREMAGE_H
#define FIREMAGE_H

#include "Mage.h"
#include <string>
using namespace std;

class FireMage : public Mage
{
private:
    string spellType;
public:
    FireMage(string n, int l, int h, int ap, int m);
    void performAttack() override;
    void MakeDamage()override;
    void displayInfo();
};

#endif