#pragma once

namespace nbody
{
class Vector
{
public: 
    Vector();
    Vector(double x, double y, bool degreeMode=false);
    double magnitude();
    void vectorInfo();
    double getX() const;
    double getY() const;

private:
    double x;
    double y;
    void speedToVec(double degree, double speed);
};
};