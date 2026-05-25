#include "Dyhotomia_Class.h"
#include <iostream>
#include <cmath>

using namespace std;

Dyhotomia_class::Dyhotomia_class() {
    a = 0;
    b = 0;
    eps = 0;
}

Dyhotomia_class::~Dyhotomia_class() {}

void Dyhotomia_class::setVolumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance(double vol_eps) {
    eps = vol_eps;
}


double Dyhotomia_class::Dyhotomia() {

    auto f = [](double x) -> double {
        if (fabs(x) < 1e-12)
            return NAN;
        return cos(2 / x) - 2 * sin(1 / x) + 1 / x;
    };

    double left = a;
    double right = b;

    double f_left = f(left);
    double f_right = f(right);

    if (isnan(f_left) || isnan(f_right)) {
        cout << "Function undefined in interval" << endl;
        return NAN;
    }

    if (f_left * f_right > 0) {
        cout << "No root in interval" << endl;
        return NAN;
    }

    if (fabs(f_left) < eps) return left;
    if (fabs(f_right) < eps) return right;

    double mid, f_mid;

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

    return (left + right) / 2.0;
}


double Dyhotomia_class::Newton() {

    auto f = [](double x) -> double {
        if (fabs(x) < 1e-12)
            return NAN;
        return cos(2 / x) - 2 * sin(1 / x) + 1 / x;
    };

    auto df = [&](double x) -> double {
        double h = 1e-6;
        return (f(x + h) - f(x - h)) / (2 * h);
    };

    double x = (a + b) / 2.0;

    if (fabs(f(x)) < eps)
        return x;

    for (int i = 0; i < 100; i++) {

        double dfx = df(x);

        if (fabs(dfx) < 1e-12) {
            cout << "Derivative too small" << endl;
            return NAN;
        }

        double x_new = x - f(x) / dfx;

        if (fabs(f(x_new)) < eps || fabs(x_new - x) < eps)
            return x_new;

        x = x_new;
    }

    cout << "Newton did not converge" << endl;
    return x;
}

void quadratic(double a, double b, double c) {

    auto D = [](double a, double b, double c) {
        return b * b - 4 * a * c;
    };

    double d = D(a, b, c);

    if (a == 0) {
        cout << "Not quadratic equation\n";
        return;
    }

    if (d < 0) {
        cout << "No real roots\n";
        return;
    }

    auto x1 = [&](double a, double b, double d) {
        return (-b + sqrt(d)) / (2 * a);
    };

    auto x2 = [&](double a, double b, double d) {
        return (-b - sqrt(d)) / (2 * a);
    };

    if (d == 0) {
        cout << "x = " << x1(a, b, d) << endl;
    } else {
        cout << "x1 = " << x1(a, b, d) << endl;
        cout << "x2 = " << x2(a, b, d) << endl;
    }
}