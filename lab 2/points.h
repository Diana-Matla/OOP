#ifndef POINTS_H
#define POINTS_H

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;

    double triangleArea() const;
    void PositionHeron(Point P) const ;
    void Position(Point P) const;
};

double distance(const Point &A, const Point &B);
double determinant(Point A, Point B, Point P);
bool onSegment(Point A, Point B, Point P);
int sign(double n);
void inputPoint(Point &p);
int result();

#endif