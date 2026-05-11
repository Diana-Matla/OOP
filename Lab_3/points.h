#pragma once

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;
    
    double area() const;
    int containsByArea(const Point &p) const;
    int containsByVector(const Point &p) const;
};

double distance(const Point &p1, const Point &p2);
double heronArea(const Triangle &t);

void result();
