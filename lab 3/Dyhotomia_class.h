#ifndef DYHOTOMIA_CLASS_H
#define DYHOTOMIA_CLASS_H

class Dyhotomia_class
{
private: 
    double a;
    double b;
    double eps;
    double df(double x); 

public:
    Dyhotomia_class(void);
    ~Dyhotomia_class(void);

    void setVolumes (double vol_a, double vol_b);
    void setTolerance (double vol_eps);  
    double f(double x);
    double Dyhotomia(); 
    double Newton();
};

void result();

#endif