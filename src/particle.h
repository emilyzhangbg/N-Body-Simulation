#pragma once
#include "vector.h"
#include "renderer.h"

namespace nbody
{
class Particle
{
public:
    struct State
    {
        Vector position;
        Vector velocity;
        double mass;
        double radius;
    };
    // Particle();
    // Particle(double mass, double radius);
    Particle(const Renderer &renderer, const State& initialState);
    void particleInfo();
    void draw() const;

private:
    State state;
    const Renderer& renderer;
};
}; 