#ifndef POINTS_H
#define POINTS_H

struct Point {
    double x, y;
};

int sign(double n);
double determinant(Point A, Point B, Point P);
bool PointIsOnSegment(Point A, Point B, Point P);
double distance(const Point A, const Point B);

void inputPoint(Point &p);
int result();

struct Triangle {
    Point A, B, C;

    bool IsDegenerate() const;
    double triangleArea() const;
    bool PointIsOnEdge(Point P)const;
    void PositionHeron(Point P) const ;
    void Position(Point P) const;
};

#endif