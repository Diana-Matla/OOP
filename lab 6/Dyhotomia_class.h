#ifndef DYHOTOMIA_CLASS_H
#define DYHOTOMIA_CLASS_H

class Dyhotomia_class {
private:
    double a, b, eps;

public:
    Dyhotomia_class();
    ~Dyhotomia_class();

    void setVolumes(double vol_a, double vol_b);
    void setTolerance(double vol_eps);

    double Dyhotomia();
    double Newton();
};

void quadratic(double a, double b, double c);

#endif