#include <iostream>
#include "Character.h"
#include "Warrior.h"
#include "Archer.h"
#include "Mage.h"
#include "FireMage.h"
#include "IceMage.h"
#include "BattleMage.h"
#include "UltimateHero.h"

using namespace std;

int main() {

    cout << "========== CHARACTER CREATION ==========\n";

    Warrior* warrior = new Warrior("Thor", 10, 250, 30, 50);
    Archer* archer = new Archer("Legolas", 8, 180, 25, 40);
    Mage* mage = new Mage("Merlin", 12, 150, 20, 80);

    FireMage* fireMage = new FireMage("Ignis", 15, 140, 35, 100);
    IceMage* iceMage = new IceMage("Frost", 14, 160, 28, 90);


    cout << "\n========== BATTLEMAGE (2 PARENTS) ==========\n";

    BattleMage battleMage("Gandalf", 18, 300, 45, 60, 120);


    cout << "\n========== ULTIMATE HERO (3 PARENTS / DIAMOND) ==========\n";

    UltimateHero hero("Arthur", 20, 500, 40, 60, 70, 80);


    cout << "\n========== DISPLAY INFO ==========\n";

    warrior->displayInfo();
    cout << endl;

    archer->displayInfo();
    cout << endl;

    mage->displayInfo();
    cout << endl;

    fireMage->displayInfo();
    cout << endl;

    iceMage->displayInfo();
    cout << endl;

    battleMage.displayInfo();
    cout << endl;

    hero.displayInfo();
    cout << endl;

    cout << "\n========== BATTLE ==========\n";

    cout << "---- Warrior ----\n";
    warrior->performAttack();
    warrior->MakeDamage();
    warrior->performAttack(20);

    cout << "\n---- Archer ----\n";
    archer->performAttack();
    archer->MakeDamage();
    archer->performAttack(30);

    cout << "\n---- Mage ----\n";
    mage->performAttack();
    mage->MakeDamage();
    mage->performAttack(20);

    cout << "\n---- Fire Mage ----\n";
    fireMage->performAttack();
    fireMage->MakeDamage();
    fireMage->performAttack(30);

    cout << "\n---- Ice Mage ----\n";
    iceMage->performAttack();
    iceMage->MakeDamage();
    iceMage->performAttack(20);

    cout << "\n---- BattleMage (2 PARENTS TEST) ----\n";
    battleMage.performAttack();
    battleMage.MakeDamage();

    cout << "\n---- Ultimate Hero (ROMB TEST) ----\n";
    hero.performAttack();
    hero.MakeDamage();

    /*cout << "\n========== POLYMORPHISM TEST ==========\n";

    Character* team[7];

    team[0] = warrior;
    team[1] = archer;
    team[2] = mage;
    team[3] = fireMage;
    team[4] = iceMage;
    team[5] = &battleMage;
    team[6] = &hero;

    for (int i = 0; i < 7; i++) {
        team[i]->performAttack();
        team[i]->MakeDamage();
        cout << "------------------------\n";
    }*/

    cout << "\n========== CLEANUP ==========\n";

    delete warrior;
    delete archer;
    delete mage;
    delete fireMage;
    delete iceMage;

    cout << "\n========== END ==========\n";

    return 0;
}