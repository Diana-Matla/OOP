#include "UltimateHero.h"
#include <iostream>

using namespace std;

UltimateHero::UltimateHero(string n, int l, int h, int ap,
                           int str, int m, int dist)
    : Character(n, l, h, ap), 
      Warrior(n,l,h,ap,str),
      Mage(n,l,h,ap,m),
      Archer(n,l,h,ap,dist)
{
    cout << "UltimateHero constructor\n";
}

void UltimateHero::performAttack()
{
    cout << "UltimateHero performs combined attack (Warrior + Mage + Archer)\n";
}

void UltimateHero::MakeDamage(){
    cout<<"Attack damage:"<<attackPower*12<<endl;
}

void UltimateHero::displayInfo()
{
    Character::displayInfo(); 

    cout << "Strength: " << strength << endl;
    cout << "Mana: " << mana << endl;
    cout << "Distance: " << distance << endl;
}

UltimateHero::~UltimateHero()
{
    cout << "UltimateHero destructor\n";
}