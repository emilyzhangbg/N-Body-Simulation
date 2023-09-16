#include <iostream>
#include "particle.h"

namespace nbody
{
Particle::Particle()
: position{Vector{0,0}}, velocity{Vector{0, 0, true}}, mass{1}, radius{1}
{
}

Particle::Particle(double mass, double radius)
: position{Vector{0, 0}}, velocity{Vector{0, 0, true}}, mass{mass}, radius{radius}
{
}

Particle::Particle(double x, double y, double degrees, double speed, double mass, double radius)
: position{Vector{x, y}}, velocity{Vector{degrees, speed, true}}, mass{mass}, radius{radius}
{
}

void Particle::particleInfo()
{
    std::cout << "Position: ";
    position.vectorInfo();
    std::cout << "Velocity: ";
    velocity.vectorInfo();
    std::cout << "Mass: " << mass << std::endl;
    std:: cout << "Radius: " << radius << std::endl;
}

};
