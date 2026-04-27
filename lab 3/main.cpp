#include "Dyhotomia_class.cpp"
#include <iostream>
using namespace std;

int main() {
    Dyhotomia_class*dyh = new Dyhotomia_class();

    dyh->setVolumes(2, 3);
    dyh->setTolerance(0.0001);

    cout <<"Dyhotomia: "<< dyh->solve() << endl;
    cout <<"Newton: "<< dyh->newton() << endl;

    delete dyh;
    return 0;
}