#include <iostream>
#include <string>
#include <cmath> 
#include"character.h"
#include"Archer.h"
using namespace std;

Archer::Archer(string n, int l, int h, int ap, int dist)
 : Character(n, l, h, ap)
{
    distance = dist;
    cout << "Archer constructor\n";
}

Archer::~Archer()
{
    cout << "Archer destructor\n";
}

void Archer::performAttack() {
    cout << "Archer attacks using arrows being "<<distance<<" meters away"<<endl;
}

void Archer::MakeDamage(){
    int power = 0;
    if ((distance>0)&&(distance<=50)) power = 5;
    else power = 3;
    cout<<"Attack damage:"<<attackPower*power<<endl;
}

void Archer::performAttack(int bonusDamage) {
    cout << "Archer attacks with bonus damage: "
         << attackPower + bonusDamage << endl;
}

void Archer::displayInfo(){
    Character::displayInfo();
    cout << "Distance: "<< distance<< endl;
}