#pragma once
#include <vector>
#include "particle.h"
#include "renderer.h"

namespace nbody
{
class Nbody{
public:
    Nbody(const Renderer &renderer, double mass, int n, double radius);
    void particlesInfo();
    void drawBodies() const;
    void moveBodies();

private:
    std::vector<Particle> particles;
    double mass;
    int numOfParticles;
    double radius;
    const Renderer& renderer;
};
};