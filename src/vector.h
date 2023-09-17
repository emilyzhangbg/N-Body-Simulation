#pragma once

namespace nbody
{
class Vector
{
public: 
    Vector();
    Vector(double x, double y, bool degreeMode=false);
    Vector(const Vector& direction, double magnitude);
    double magnitude() const;
    void vectorInfo() const;
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
    void vecSub(const Vector& other);
    void vecAdd(const Vector& other);
    void setVector(const Vector& vec);

private:
    double x;
    double y;
    void speedToVec(double degree, double speed);
};
};