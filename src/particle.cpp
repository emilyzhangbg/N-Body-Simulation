#include "particle.h"
#include <iostream>
#include <cmath>

namespace nbody
{
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
    std::cout << "Net Force: ";
    state.netForce.vectorInfo();
    std::cout << "Acceleration: ";
    state.acceleration.vectorInfo();
    std::cout << "Current Displacement: ";
    state.curDisplacement.vectorInfo();
    std::cout << "Mass: " << state.mass << std::endl;
    std:: cout << "Radius: " << state.radius << std::endl;
    std::cout << "-----" << std::endl;
}

Particle::~Particle()
{
}

void Particle::draw() const
{
    SDL_Rect rect;

    rect.w = state.radius * 2;
    rect.h = state.radius * 2;
    rect.x = state.position.getX() - state.radius;
    rect.y = state.position.getY() - state.radius;

    SDL_SetRenderDrawColor(renderer.getHandle(), 255, 255, 255, 255);
    SDL_RenderFillRect(renderer.getHandle(), &rect);
}

double Particle::getPosX() const
{
    return state.position.getX();
}

double Particle::getPosY() const
{
    return state.position.getY();
}

double Particle::getVelX() const
{
    return state.velocity.getX();
}

double Particle::getVelY() const
{
    return state.velocity.getY();
}

const Vector& Particle::getPosition() const
{
    return state.position;
}

const Vector& Particle::getNetForce() const
{
    return state.netForce;
}

const Vector& Particle::getAcceleration() const
{
    return state.acceleration; 
}

void Particle::setNetForce(const Vector& force)
{  
    state.netForce.setVector(force);
}

void Particle::updateAcceleration()
{
    double accelerationMagnitude = state.netForce.magnitude() / state.mass;
    state.acceleration.setVector(Vector(state.netForce, accelerationMagnitude));
}

void Particle::updateDisplacement()
{
    double displacementX = state.velocity.getX() * dt + (1/2) * state.acceleration.getX() * std::pow(dt, 2); 
    double displacementY = state.velocity.getY() * dt + (1/2) * state.acceleration.getY() * std::pow(dt, 2); 

    state.curDisplacement.setVector(Vector{displacementX, displacementY});
}

void Particle::updatePosition()
{
    state.position.vecAdd(state.curDisplacement);
}

void Particle::updateVelocity()
{
    double velocityX = state.velocity.getX() + state.acceleration.getX() * dt; 
    double velocityY = state.velocity.getY() + state.acceleration.getY() * dt; 

    state.velocity.setVector(Vector{velocityX, velocityY});
}

};
