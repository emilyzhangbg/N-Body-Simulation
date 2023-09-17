#include <iostream>
#include "particle.h"

namespace nbody
{
// Particle::Particle()
// : position{Vector{0,0}}, velocity{Vector{0, 0, true}}, mass{1}, radius{1}
// {
// }

// Particle::Particle(double mass, double radius)
// : position{Vector{0, 0}}, velocity{Vector{0, 0, true}}, mass{mass}, radius{radius}
// {
// }

Particle::Particle(const Renderer &renderer, const State& state)
: renderer{renderer}, state{state}
{
}

void Particle::particleInfo()
{
    std::cout << "Position: ";
    state.position.vectorInfo();
    std::cout << "Velocity: ";
    state.velocity.vectorInfo();
    std::cout << "Mass: " << state.mass << std::endl;
    std:: cout << "Radius: " << state.radius << std::endl;
}

void Particle::draw() const
{
    // std::cout << "drawing" << std::endl;
    SDL_Rect rect;

    rect.w = state.radius * 2;
    rect.h = state.radius * 2;
    rect.x = state.position.getX() - state.radius;
    rect.y = state.position.getY() - state.radius;

    SDL_SetRenderDrawColor(renderer.getHandle(), 0, 0, 0, 255);
    SDL_RenderFillRect(renderer.getHandle(), &rect);
}

};
