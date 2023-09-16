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
Nbody::Nbody(double mass, int n, double radius)
: mass{mass}, numOfParticles{n}, radius{radius}
{
    particles = new Particle[n];

    unsigned long seed;

    for (int i = 0; i < n; ++i)
    {
        seed = mix(clock(), time(NULL), getpid());
        std::srand(seed);
        double x = std::rand() % 10000 / 100.0;
        double y = std::rand() % 10000 / 100.0;
        double degrees = std::rand() % 36000 / 100.0;
        double speed = std::rand() % 50000 / 100.0;

        std::cout << "(" << x << ", " << y << ")" << std::endl;
        std::cout << "degrees: " << degrees << std::endl;
        std::cout << "speed " << speed << std::endl; 

        particles[i] = Particle{x, y, degrees, speed, mass, radius};
    }
}

void Nbody::particlesInfo()
{
    for (int i = 0; i < numOfParticles; ++i)
    {
        particles[i].particleInfo();
    }
}

};
