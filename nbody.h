#pragma once
#include "particle.h"

namespace nbody
{
class Nbody{
public:
    Nbody(double mass, int n, double radius);
    void particlesInfo();

private:
    Particle* particles;
    double mass;
    int numOfParticles;
    double radius;
};
};