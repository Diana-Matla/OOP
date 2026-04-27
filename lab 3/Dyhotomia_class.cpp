#include "Dyhotomia_Class.h"
#include<iostream>
#include <cmath>
using namespace std;

Dyhotomia_class::Dyhotomia_class() {
    a = 0;
    b = 0;
    eps = 0;
}

double Dyhotomia_class::f(double x) {
    if (!isValid(x)) return 1e9;
    return 	3 * sqrt(sin(x)) + 0.35 * x - 3.8;;
}

void Dyhotomia_class::setVolumes (double vol_a, double vol_b){
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance (double vol_eps){
    eps = vol_eps;
}

double Dyhotomia_class::productSign(double a, double b){
    return f(a)*f(b);
}

double Dyhotomia_class::solve() {
    double left = a;
    double right = b;
    double mid;

    if (productSign(a,b) > 0) {
        cout << "No root in interval" << endl;
        return NAN;
    }

    while ((right - left) > eps) {
        mid = (left + right) / 2;

        if (f(mid) == 0)
            return mid;

        if (f(left) * f(mid) < 0)
            right = mid;
        else
            left = mid;
    }

    return (left + right) / 2;
}


double Dyhotomia_class::df(double x){
    double h = 1e-5;
    return (f(x + h) - f(x - h)) / (2*h);
}

double Dyhotomia_class::newton(){
    double x = (a + b) / 2;
    while (true) {
        if (fabs(df(x)) < 1e-12)
            break;

        double x_new = x - f(x) / df(x);

        if (fabs(x_new - x) < eps)
            break;

        x = x_new;
    }
    return x;
}

bool Dyhotomia_class::isValid(double x) {
    return (
        sin(x) >= 0 &&          // для sqrt
        cos(x) != 0 &&          // якщо був tan
        x > 0 &&                // якщо ln(x)
        fabs(3 - sin(3.6*x)) > 1e-9  // якщо ділення
    );
}