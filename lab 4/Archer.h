#ifndef ARCHER_H
#define ARCHER_H

#include "character.h"
#include <string>
using namespace std;

class Archer : public Character 
{
protected:
    int distance;
public:
    Archer(string n, int l, int h, int ap, int dist);
    void performAttack() override;
    void MakeDamage()override;
    void displayInfo();
};

#endif