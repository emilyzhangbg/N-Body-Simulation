#include <cstdlib>
#include <iostream>
#include <time.h>
#include "nbody.h"

unsigned long mix(unsigned long a, unsigned long b, unsigned long c)
{
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}

namespace nbody
{
Nbody::Nbody(const Renderer &renderer, double mass, int n, double radius)
: renderer{renderer}, mass{mass}, numOfParticles{n}, radius{radius}
{
    particles.reserve(n);
    unsigned long seed;

    for (int i = 0; i < n; ++i)
    {
        seed = mix(clock(), time(NULL), getpid());
        std::srand(seed);

        double x = std::rand() % 80000 / 100.0;
        double y = std::rand() % 60000 / 100.0;
        double degrees = std::rand() % 36000 / 100.0;
        double speed = std::rand() % 50000 / 100.0;


        Particle::State particleState {
            position: Vector{x, y},
            velocity: Vector{degrees, speed, true},
            mass: mass,
            radius: radius,
        };

        std::cout << "(" << x << ", " << y << ")" << std::endl;
        std::cout << "degrees: " << degrees << std::endl;
        std::cout << "speed " << speed << std::endl; 

        particles.push_back(Particle{renderer, particleState});
    }
}

void Nbody::particlesInfo()
{
    for (int i = 0; i < numOfParticles; ++i)
    {
        particles[i].particleInfo();
    }
}

void Nbody::drawBodies() const
{
    // std::cout << "drawing bodies" << std::endl;

    for (int i = 0; i < numOfParticles; ++i)
    {
        particles[i].draw();
    }
}

};
