#include "points.h"
#include<cmath>
#include <iostream>
using namespace std;

bool Degeneracy (Point A, Point B, Point C){
    if ( A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)==0) return true;
    else return false;
}

double distance(Point A, Point B) {
    return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}

double areaHeron(double a, double b, double c) {
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double triangleArea(Triangle T) {
    double a = distance(T.A, T.B);
    double b = distance(T.B, T.C);
    double c = distance(T.C, T.A);

    return areaHeron(a, b, c);
}

void PositionHeron(Triangle T, Point P) {
    double S  = triangleArea(T);

    Triangle T1 = {P, T.A, T.B};
    Triangle T2 = {P, T.B, T.C};
    Triangle T3 = {P, T.C, T.A};

    double S1 = triangleArea(T1);
    double S2 = triangleArea(T2);
    double S3 = triangleArea(T3);

    if (abs(S - (S1 + S2 + S3)) < 1e-9) {
        if (S1 < 1e-9 || S2 < 1e-9 || S3 < 1e-9)
            cout << "on the edge (Heron method)" << endl;
        else
            cout << "inside the triangle (Heron method)" << endl;
    } else {
        cout << "outside the triangle (Heron method)" << endl;
    }
}

bool onSegment(Point A, Point B, Point P) {
    return (P.x >= min(A.x, B.x) && P.x <= max(A.x, B.x) &&
            P.y >= min(A.y, B.y) && P.y <= max(A.y, B.y));
}

void Position (Point A, Point B, Point C, Point P){
    int o1 = (B.x - A.x)*(P.y - A.y) - (B.y - A.y)*(P.x - A.x);
    int o2 = (C.x - B.x)*(P.y - B.y) - (C.y - B.y)*(P.x - B.x);
    int o3 = (A.x - C.x)*(P.y - C.y) - (A.y - C.y)*(P.x - C.x);
    if (((o1>0) && (o2>0) && (o3>0)) || ((o1<0) && (o2<0) && (o3<0))) cout<<"inside the triangle"<<endl;
    else if ((o1 == 0 && onSegment(A, B, P)) ||
             (o2 == 0 && onSegment(B, C, P)) ||
             (o3 == 0 && onSegment(C, A, P))) {
        cout << "on the edge" << endl;
    }
    else cout<<"outside the triangle"<<endl;
}

double area(Point A, Point B, Point C) {
    return abs(
        A.x * (B.y - C.y) +
        B.x * (C.y - A.y) +
        C.x * (A.y - B.y)
    ) / 2.0;
}

void PositionArea(Point A, Point B, Point C, Point P){
    double S  = area(A, B, C);
    double S1 = area(P, A, B);
    double S2 = area(P, B, C);
    double S3 = area(P, C, A);

    if (abs(S - (S1 + S2 + S3)) < 1e-9) {
        if (S1 == 0 || S2 == 0 || S3 == 0)
            cout << "on the edge (area method)" << endl;
        else
            cout << "inside the triangle (area method)" << endl;
    }
    else {
        cout << "outside the triangle (area method)" << endl;
    }
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
    Point MainPoints[3] ;
    Point Additional[100];

    for (int i=0; i<3; i++){
        cout<<"Enter coordinates for "<<i+1<<" point (x,y):"<<endl;
        inputPoint(MainPoints[i]);
    
    }
    if (Degeneracy(MainPoints[0], MainPoints[1], MainPoints[2])) {
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
       inputPoint(Additional[i]);
    }

    for (int i = 0; i<amount; i++){
        cout<<"The Point "<< i+1 <<" is "<<endl;
        Position(MainPoints[0], MainPoints[1], MainPoints[2], Additional[i]);
        PositionArea(MainPoints[0], MainPoints[1], MainPoints[2], Additional[i]);

        cout << endl;
    }

    Triangle T = {MainPoints[0], MainPoints[1], MainPoints[2]};

    for (int i = 0; i < amount; i++) {
        cout<<"The Point "<< i+1 <<" is "<<endl;
        
        Position(MainPoints[0], MainPoints[1], MainPoints[2], Additional[i]);

        PositionHeron(T, Additional[i]);

        cout << endl;
    }
}