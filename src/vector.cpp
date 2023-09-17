#include <iostream>
#include <cmath>
#include "vector.h"

double degToRad(double degree)
{
    const double PI = 22/7;
    double radian = degree * (PI/180);
    return radian;
}

namespace nbody
{

Vector::Vector()
: x{0}, y{0}
{
}

Vector::Vector(double x, double y, bool degreeMode)
{
    if (degreeMode)
    {
        speedToVec(x, y);
    }
    else
    {
        this->x = x;
        this->y = y;
    }
}

void Vector::speedToVec(double degree, double speed)
{
    double firstQuadRad = 0;
    double x = 1;
    double y = 1;

    if (0 <= degree && degree <= 90)
    {
        firstQuadRad = degToRad(degree);
        x = std::sin(firstQuadRad) * speed;
        y = std::cos(firstQuadRad) * speed;
    } 
    else if (90 < degree && degree <= 180)
    {
        firstQuadRad = degToRad(180 - degree);
        x = std::sin(firstQuadRad) * speed;
        y = std::cos(firstQuadRad) * speed * -1;
    }
    else if (180 < degree && degree <= 270)
    {
        firstQuadRad = degToRad(degree - 180);
        x = std::sin(firstQuadRad) * speed * -1;
        y = std::cos(firstQuadRad) * speed * -1;
    }
    else if (270 < degree && degree <= 360)
    {
        firstQuadRad = degToRad(360 - degree);
        x = std::sin(firstQuadRad) * speed * -1;
        y = std::cos(firstQuadRad) * speed;
    }
    else 
    {
        std::cerr << "error" << std::endl;
        return;
    }

    this->x = x;
    this->y = y;
} 

double Vector::magnitude()
{
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}

void Vector::vectorInfo()
{
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

double Vector::getX() const
{
    return x;
}

double Vector::getY() const
{
    return y;
}

};
