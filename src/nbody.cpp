#include "nbody.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <cmath>

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
        double speed = 0;


        Particle::State particleState {
            position: Vector{x, y},
            velocity: Vector{degrees, speed, true},
            mass: mass,
            radius: radius,
        };

        std::cout << "(" << x << ", " << y << ")" << std::endl;
        std::cout << "degrees: " << degrees << std::endl;
        std::cout << "speed " << speed << std::endl; 
        std::cout << "-----" << std::endl; 

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
    for (int i = 0; i < numOfParticles; ++i)
    {
        particles[i].draw();
    }
}

void Nbody::calcNetForce()
{
    const double G = 6.67430 * std::pow(10, -11);

    for (int particle_i = 0; particle_i < numOfParticles; ++particle_i)
    {
        for (int particle_j = particle_i + 1; particle_j < numOfParticles; ++particle_j)
        {
            Vector path_i = Vector{0,0};
            path_i.vecAdd(particles[particle_j].getPosition());
            path_i.vecSub(particles[particle_i].getPosition());

            Vector path_j = Vector{0,0};
            path_j.vecAdd(particles[particle_i].getPosition());
            path_j.vecSub(particles[particle_j].getPosition());
    

            double distance = path_i.magnitude();
            double mutualForceMagnitude = (G * mass * mass)/std::pow(distance, 2);

            Vector forceOn_i = Vector{path_i, mutualForceMagnitude};
            Vector forceOn_j = Vector{path_j, mutualForceMagnitude};

            Vector prevNetForce_i = particles[particle_i].getNetForce();
            Vector prevNetForce_j = particles[particle_j].getNetForce();

            Vector curNetForce_i = Vector{0,0};
            curNetForce_i.vecAdd(prevNetForce_i);
            curNetForce_i.vecAdd(forceOn_i);

            Vector curNetForce_j = Vector{0,0};
            curNetForce_j.vecAdd(prevNetForce_j);
            curNetForce_j.vecAdd(forceOn_j);


            particles[particle_i].setNetForce(curNetForce_i);
            particles[particle_j].setNetForce(curNetForce_j);

            particles[particle_i].updateAcceleration();
            particles[particle_j].updateAcceleration();   

            particles[particle_i].updateDisplacement();
            particles[particle_j].updateDisplacement();   

            particles[particle_i].updatePosition();
            particles[particle_j].updatePosition();

            particles[particle_i].updateVelocity();
            particles[particle_j].updateVelocity();
        }
    }
}
};
