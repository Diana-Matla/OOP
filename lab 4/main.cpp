#include <iostream>
#include "Character.h"
#include "Warrior.h"
#include "Archer.h"
#include "Mage.h"
#include "FireMage.h"
#include "IceMage.h"

using namespace std;

int main() {

    Warrior warrior("Thor", 10, 250, 30, 50);

    Archer archer("Legolas", 8, 180, 25, 40);

    Mage mage("Merlin", 12, 150, 20, 80);

    FireMage fireMage("Ignis", 15, 140, 35, 100);

    IceMage iceMage("Frost", 14, 160, 28, 90);


    cout << "--------------CHARACTERS --------------\n\n";

    warrior.displayInfo();
    cout << endl;

    archer.displayInfo();
    cout << endl;

    mage.displayInfo();
    cout << endl;

    fireMage.displayInfo();
    cout << endl;

    iceMage.displayInfo();
    cout << endl;

    cout << "              BATTLE\n";
    cout << "--------------------------------------\n\n";


    cout << "---- Warrior attack ----\n";

    warrior.performAttack();
    warrior.MakeDamage();

    cout << endl;


    cout << "---- Archer attack ----\n";

    archer.performAttack();
    archer.MakeDamage();

    cout << endl;

    cout << "---- Mage attack ----\n";

    mage.performAttack();
    mage.MakeDamage();

    cout << endl;


    cout << "---- Fire Mage attack ----\n";

    fireMage.performAttack();
    fireMage.MakeDamage();

    cout << endl;


    cout << "---- Ice Mage attack ----\n";

    iceMage.performAttack();
    iceMage.MakeDamage();

    cout << endl;

    cout << "          POLYMORPHISM TEST\n";
    cout << "--------------------------------------\n\n";


    Character* team[5];

    team[0] = &warrior;
    team[1] = &archer;
    team[2] = &mage;
    team[3] = &fireMage;
    team[4] = &iceMage;


    for (int i = 0; i < 5; i++) {

        team[i]->performAttack();
        team[i]->MakeDamage();

        cout << "------------------------\n";
    }


    cout << "\n-------------------------------\n";
    cout << "        BATTLE END\n";

    return 0;
}