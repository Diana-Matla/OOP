#include <iostream>
#include <cmath>
#include "points.h"

using namespace std;

double distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double heronArea(const Triangle &t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Triangle::area() const {
    return heronArea(*this);
}

int checkDegenerate(const Triangle &t, const Point &p) {
    double dAB = distance(t.A, t.B);
    double dBC = distance(t.B, t.C);
    double dCA = distance(t.C, t.A);

    Point start = t.A, end = t.B;
    double maxDist = dAB;

    if (dBC > maxDist) { start = t.B; end = t.C; maxDist = dBC; }
    if (dCA > maxDist) { start = t.C; end = t.A; maxDist = dCA; }

    if (fabs(distance(p, start) + distance(p, end) - maxDist) < 1e-9) {
        return 0;
    }
    return -1;
}

int Triangle::containsByArea(const Point &p) const {
    double mainArea = area();
    
    if (mainArea < 1e-9) {
        return checkDegenerate(*this, p);
    }

    Triangle t1 = {A, B, p};
    Triangle t2 = {B, C, p};
    Triangle t3 = {C, A, p};

    double s1 = t1.area();
    double s2 = t2.area();
    double s3 = t3.area();
    double sumArea = s1 + s2 + s3;

    if (fabs(mainArea - sumArea) < 1e-9) {
        if (s1 < 1e-9 || s2 < 1e-9 || s3 < 1e-9) return 0;
        return 1;
    }
    return -1;
}

int Triangle::containsByVector(const Point &p) const {
    if (area() < 1e-9) {
        return checkDegenerate(*this, p);
    }

    double cp1 = (B.x - A.x) * (p.y - A.y) - (B.y - A.y) * (p.x - A.x);
    double cp2 = (C.x - B.x) * (p.y - B.y) - (C.y - B.y) * (p.x - B.x);
    double cp3 = (A.x - C.x) * (p.y - C.y) - (A.y - C.y) * (p.x - C.x);

    if (fabs(cp1) < 1e-9 || fabs(cp2) < 1e-9 || fabs(cp3) < 1e-9) return 0;

    if ((cp1 > 0 && cp2 > 0 && cp3 > 0) || (cp1 < 0 && cp2 < 0 && cp3 < 0)) return 1;

    return -1;
}

void result() {
    Triangle t;
    cout << "Enter coordinates  A (x y): "; cin >> t.A.x >> t.A.y;
    cout << "Enter coordinates  B (x y): "; cin >> t.B.x >> t.B.y;
    cout << "Enter coordinates C (x y): "; cin >> t.C.x >> t.C.y;

    bool isDegen = (t.area() < 1e-9);
    if (isDegen) {
        cout << "The triangle is degenerate." << endl;
    }

    int pointsCount;
    cout << "\nHow many points to check? "; cin >> pointsCount;

    for (int i = 0; i < pointsCount; i++) {
        Point p;
        cout << "\nPoint " << i + 1 << " (x y): "; cin >> p.x >> p.y;

        int resA = t.containsByArea(p);
        int resV = t.containsByVector(p);

        cout << "Heron: ";
        if (resA == 0) cout << "On the border" << endl;
        else if (resA == 1) cout << "Inside the triangle." << endl;
        else cout << "Outside." << endl;

        cout << "Vector: ";
        if (resV == 0) cout << "On the border." << endl;
        else if (resV == 1) cout << "Inside the triangle." << endl;
        else cout << "Outside." << endl;
    }
}