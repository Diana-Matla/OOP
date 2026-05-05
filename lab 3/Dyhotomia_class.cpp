#include "Dyhotomia_Class.h"
#include<iostream>
#include <cmath>
using namespace std;

Dyhotomia_class::Dyhotomia_class() {
    a = 0;
    b = 0;
    eps = 0;
}

Dyhotomia_class::~Dyhotomia_class() {}

void Dyhotomia_class::setVolumes (double vol_a, double vol_b){
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance (double vol_eps){
    eps = vol_eps;
}


double Dyhotomia_class::f(double x) {
    if (fabs(x) < 1e-12)
        return NAN;
    return cos(2/x) - 2*sin(1/x) + 1/x;
}

double Dyhotomia_class::df(double x){
    double h = 1e-6;
    return (f(x + h) - f(x - h)) / (2*h);
}

double Dyhotomia_class::Dyhotomia() {
    double left = a;
    double f_left = f(left);
    double right = b;
    double f_right = f(right);

    if (isnan(f_left) || isnan(f_right)) {
        cout << "Function undefined in interval" << endl;
        return NAN;
    }

    if (f_left * f_right > 0) {
        cout << "No root in interval" << endl;
        return NAN;
    }

    if (fabs(f_left)<eps)
        return left;

    if (fabs(f_right)<eps)
        return right;

    double mid;
    double f_mid;

    //for (int i = 0; i < 1000; i++) { 
    while (fabs(right - left) >= eps) {
        mid = (left + right) / 2.0;
        f_mid = f(mid);

        if (fabs(f_mid) < eps)
            return mid;

        if (f_left * f_mid < 0) {
            right = mid;
            f_right = f_mid;
        } else {
            left = mid;
            f_left = f_mid;
        }
    }

    return (left + right) / 2;
}


double Dyhotomia_class::Newton(){
    double x = (a + b) / 2;
    if (fabs(f(x))<eps)
        return x;

    double dfx;
    double x_new;

    for (int i = 0; i < 100; i++) {
        dfx = df(x);

        if (fabs(dfx) < 1e-12) {
            cout << "Derivative too small" << endl;
            return NAN;
        }

        x_new = x - f(x) / dfx;
        if (fabs(f(x_new))<eps)
            return x_new;

        if (fabs(x_new - x) < eps)
            return x_new;

        x = x_new;
    }

    cout << "Newton did not converge" << endl;
    return x;
}


void result(){
    Dyhotomia_class*dyh = new Dyhotomia_class();

    dyh->setVolumes(1, 2);
    dyh->setTolerance(0.0001);

    cout <<"Dyhotomia: "<< dyh->Dyhotomia() << endl;
    cout <<"Newton: "<< dyh->Newton() << endl;

    delete dyh;
}