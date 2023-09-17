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
        Vector netForce;
        Vector acceleration;
        Vector curDisplacement;
    };
    
    Particle(const Renderer &renderer, const State& initialState);
    void particleInfo();
    void draw() const;
    double getPosX() const;
    double getPosY() const;
    double getVelX() const;
    double getVelY() const;
    const Vector& getPosition() const;
    const Vector& getNetForce() const;
    const Vector& getAcceleration() const;
    void setNetForce(const Vector& force);
    void updateAcceleration();
    void updateDisplacement();
    void updatePosition();
    void updateVelocity();

private:
    State state;
    const Renderer& renderer;
    double dt = 1;
};
}; 