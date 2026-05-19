#include <iostream>
#include <string>
#include"character.h"
using namespace std;


Character::Character(string n, int l, int h, int ap){
    characterName = n;
    level = l;
    healthPoints = h;
    attackPower = ap;

    cout << "Character constructor\n";
}

Character::~Character()
{
    cout << "Character destructor\n";
}


void Character::displayInfo(){
    cout<<"---------------------------"<<endl;
    cout<<"Name:"<<characterName<<endl;
    cout<<"Level:"<<level<<endl;
    cout<<"Health points:"<<healthPoints<<endl;
    cout<<"Attack power:"<<attackPower<<endl;
}

void Character::performAttack(){
    cout<<"Character attacks"<<endl;
}

void Character::MakeDamage(){
    cout<<"Attack damage:"<<attackPower<<endl;
}
