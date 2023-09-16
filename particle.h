#pragma once
#include "vector.h"

namespace nbody
{
class Particle
{
public:
    Particle();
    Particle(double mass, double radius);
    Particle(double x, double y, double degrees, double speed, double mass, double radius);
    void particleInfo();
private:
    Vector position;
    Vector velocity;
    double mass;
    double radius;
};
}; 