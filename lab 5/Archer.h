#ifndef ARCHER_H
#define ARCHER_H

#include "character.h"
#include <string>
using namespace std;

class Archer : virtual public Character 
{
protected:
    int distance;
public:
    Archer(string n, int l, int h, int ap, int dist);
    virtual ~Archer();
    void performAttack() override;
    void MakeDamage()override;
    void performAttack(int bonusDamage);
    void displayInfo();
};

#endif