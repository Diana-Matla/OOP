#include <iostream>
#include <string>
#include"character.h"
#include"Warrior.h"
using namespace std;

Warrior::Warrior(string n, int l, int h, int ap, int str): Character(n, l, h, ap)
{
    strength = str;
    cout << "Warrior constructor\n";
}

Warrior::~Warrior()
{
    cout << "Warrior destructor\n";
}

void Warrior::performAttack() {
    cout << "Warrior attacks with sword" << endl;
}

void Warrior::performAttack(int bonusDamage) {
    cout << "Warrior attacks with bonus damage: "
         << attackPower + bonusDamage << endl;
}

void Warrior::MakeDamage(){
    cout<<"Attack damage:"<<attackPower*(strength/10)<<endl;
}

void Warrior::displayInfo(){
    Character::displayInfo();
    cout << "Strength: "<<strength<< endl;
}