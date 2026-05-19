#include "points.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <iomanip>


using namespace std;

const double EPS = 1e-12;

// Знак числа
int sign(double n) {
    if (fabs(n) < EPS) return 0;
    return (n > 0) ? 1 : -1;
}

// скалярний добуток векторів AB та AP
double determinant(Point A, Point B, Point P) {
    return (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
}

// Перевірка чи точка P на відрізку AB
bool PointIsOnSegment(Point A, Point B, Point P) {
    bool Result = (min(A.x, B.x) <= P.x) && (P.x <= max(A.x, B.x)) && (min(A.y, B.y) <= P.y) && (P.y <= max(A.y, B.y));
    Result = Result && (fabs(determinant(A, B, P)) < EPS);
    return Result;
}

// Відстань між точками A та B
double distance(const Point A, const Point B) {
    double result = (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
    return sqrt(result);
}


// Ввід-вивід даних

// Введення координат точки
void inputPoint(Point &p) {
    while (true) {
        cin >> p.x >> p.y;
        if (!cin.fail()) break;

        cout << "Invalid input. Enter two numbers: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

// Ввід даних та вивід результатів
int result() {
    int amount = 0;
    Triangle triangle;
    Point points[100];

    cout << "Enter coordinates A (x, y): ";
    inputPoint(triangle.A);

    cout << "Enter coordinates B (x, y): ";
    inputPoint(triangle.B);

    cout << "Enter coordinates C (x, y): ";
    inputPoint(triangle.C);


    if (triangle.IsDegenerate()) {
        cout << "Triangle is degenerated" << endl;
    } else {
        cout << "Triangle is not degenerated" << endl;
    }

    cout << "Enter amount of points you want to add" << endl;
    cin >> amount;

    if (amount > 100) {
        cout << "Too much points" << endl;
        return 1;
    }

    for (int i = 0; i < amount; i++) {
        cout << "Enter coordinates for " << i + 1 << " point (x,y):" << endl;
        inputPoint(points[i]);
    }

    for (int i = 0; i < amount; i++) {
        cout << "The Point " << i + 1 << " is " << endl;

        triangle.Position(points[i]);
        triangle.PositionHeron(points[i]);

        cout << endl;
    }

    return 0;
}


// Об'єкт Triangle


// Перевірка чи трикутник вироджений
bool Triangle::IsDegenerate() const {
    bool Result = (triangleArea() < EPS
        //PointIsOnSegment(A, B, C) ||
        //PointIsOnSegment(B, C, A) ||
        //PointIsOnSegment(C, A, B)
        );
    return Result;
}


//Площа трикутника
/*double Triangle::triangleArea() const {
    double a = distance(A, B);
    double b = distance(B, C);
    double c = distance(C, A);
    double p = (a + b + c) / 2.0;
    double val = p * (p - a) * (p - b) * (p - c);
    if (val < 0) val = 0;
    else val = sqrt(val); 
    return val;
}*/

double Triangle::triangleArea() const {
    return fabs(
        (B.x - A.x) * (C.y - A.y) -
        (B.y - A.y) * (C.x - A.x)
    ) / 2.0;
}


bool Triangle::PointIsOnEdge(Point P) const {
    return (
        PointIsOnSegment(A, B, P) ||
        PointIsOnSegment(B, C, P) ||
        PointIsOnSegment(C, A, P)
        );
}


// Позиція точки відносно трикутника - метод Герона
void Triangle::PositionHeron(Point P) const {
    if (PointIsOnEdge(P)) {
        cout << "Heron: on the edge" << endl;
        return;
    }
    
    if (IsDegenerate()) {
        cout << "Heron: outside the triangle" << endl;
        return;
    }

    double S = triangleArea();

    Triangle T1 = {P, A, B};
    Triangle T2 = {P, B, C};
    Triangle T3 = {P, C, A};

    double S1 = T1.triangleArea();
    double S2 = T2.triangleArea();
    double S3 = T3.triangleArea();

    if (fabs(S - (S1 + S2 + S3)) < EPS * S) {
        cout << "Heron: inside the triangle" << endl;
    }
    else
        cout << "Heron: outside the triangle" << endl;
}


// Позиція точки відносно трикутника - метод векторного добутку
void Triangle::Position(Point P) const {
    if (PointIsOnEdge(P)) {
        cout << "Vector: on the edge" << endl;
        return;
    }
    
    if (IsDegenerate()) {
        cout << "Vector: outside the triangle" << endl;
        return;
    }

    int sign1 = sign(determinant(A, B, P));
    int sign2 = sign(determinant(B, C, P));
    int sign3 = sign(determinant(C, A, P));

    if (((sign1 > 0) && (sign2 > 0) && (sign3 > 0)) ||
        ((sign1 < 0) && (sign2 < 0) && (sign3 < 0)))
        cout << "Vector: inside the triangle" << endl;
    else
        cout << "Vector: outside the triangle" << endl;
}
