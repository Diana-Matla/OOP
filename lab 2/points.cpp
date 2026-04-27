#include "points.h"
#include<cmath>
#include <iostream>
#include <algorithm>
using namespace std;

//Відстань між точками
double distance(const Point &A, const Point &B) {
    return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}


//Площа трикутника
double Triangle::triangleArea() const {
    double a = distance(A, B);
    double b = distance(B, C);
    double c = distance(C, A);

    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));

}

//Позиція точки відносно трикутника(за Героном)
void Triangle::PositionHeron(Point P) const{
    double S  = triangleArea();

    Triangle T1 = {P, A, B};
    Triangle T2 = {P, B, C};
    Triangle T3 = {P, C, A};

    double S1 = T1.triangleArea();
    double S2 = T2.triangleArea();
    double S3 = T3.triangleArea();

    if (fabs(S - (S1 + S2 + S3)) < 1e-9) {
        if (S1 < 1e-9 || S2 < 1e-9 || S3 < 1e-9)
            cout << "on the edge (Heron method)" << endl;
        else
            cout << "inside the triangle (Heron method)" << endl;
    } else {
        cout << "outside the triangle (Heron method)" << endl;
    }
}

double determinant(Point A, Point B, Point P) {
    return (B.x - A.x)*(P.y - A.y) - (B.y - A.y)*(P.x - A.x);
}

bool onSegment(Point A, Point B, Point P) {
    return (P.x >= min(A.x, B.x) && P.x <= max(A.x, B.x) &&
            P.y >= min(A.y, B.y) && P.y <= max(A.y, B.y));
}

int sign(double n) {
    if (fabs(n) < 1e-9) return 0;
    return (n > 0) ? 1 : -1;
}

void Triangle::Position(Point P) const{
    int sign1 = sign(determinant(A, B, P ));
    int sign2 = sign(determinant(B, C, P ));
    int sign3 = sign(determinant(C, A, P ));

    if (((sign1>0) && (sign2>0) && (sign3>0)) || ((sign1<0) && (sign2<0) && (sign3<0))) cout<<"inside the triangle(Vector)"<<endl;

    else if ((sign1 == 0 && onSegment(A, B, P)) ||
             (sign2 == 0 && onSegment(B, C, P)) ||
             (sign3 == 0 && onSegment(C, A, P))) {
        cout << "on the edge(Vector)" << endl;
    }
    else cout<<"outside the triangle(Vector)"<<endl;
}


void inputPoint(Point &p) {
    while (true) {
        cin >> p.x >> p.y;

        if (!cin.fail()) break;

        cout << "Invalid input. Enter two numbers: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

int result(){
    int amount=0;
    Triangle triangle;
    Point points[100];

    cout << "Enter coordinates A (x1, y1): ";
    inputPoint(triangle.A);

    cout << "Enter coordinates B (x1, y1): ";
    inputPoint(triangle.B);

    cout << "Enter coordinates C (x1, y1): ";
    inputPoint(triangle.C);


    if (triangle.triangleArea()< 1e-9) {
        cout<<"Triangle is degenerated"<<endl;
    }
    else {
        cout<<"Triangle is not degenerated"<<endl;
    }

    cout<<"Enter amount of points you want to add"<<endl;
    cin>>amount;

    if(amount>100){
        cout<<"Too much points"<<endl;
        return 1;
    } 

    for (int i=0; i<amount; i++){
        cout<<"Enter coordinates for "<<i+1<<" point (x,y):"<<endl;
       inputPoint(points[i]);
    }

    for (int i = 0; i<amount; i++){
        cout<<"The Point "<< i+1 <<" is "<<endl;
        triangle.Position(points[i]);
        triangle.PositionHeron(points[i]);

        cout << endl;
    }
    return 0;
}