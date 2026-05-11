#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character
{
protected: 
    string characterName;
    int level;
    int healthPoints;
    int attackPower;

public:
    Character(string n, int l, int h, int ap);
    virtual void performAttack();
    virtual void MakeDamage();
    virtual void displayInfo();
};


#endif