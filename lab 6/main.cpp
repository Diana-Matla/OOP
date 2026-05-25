#include "Dyhotomia_Class.h"
#include <iostream>

using namespace std;

int main() {

    cout << "QUADRATIC EQUATION \n";
    quadratic(1, -5, 6);

    Dyhotomia_class solver;

    solver.setVolumes(1, 2);
    solver.setTolerance(0.0001);

    cout << "\nBISECTION METHOD\n";
    cout << "Root: " << solver.Dyhotomia() << endl;

    cout << "\nNEWTON METHOD\n";
    cout << "Root: " << solver.Newton() << endl;

    return 0;
}