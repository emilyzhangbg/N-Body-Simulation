# N-Body-Simulation

<img width="628" alt="image" src="https://github.com/emilyzhangbg/N-Body-Simulation/assets/57567096/456049dd-d296-4cb6-9383-ccaca525a267">

## Inspiration 
Simulation inspired by the sci-fi novel "The Three-Bodied Problem" by Liu Cixin to visualize the chance of survival of a civilization on a planet surrounded by n suns. Only by predicting the trajectory of the sun will the "people" there know whether they will be faced with scorching heat, an ice age, or a period that their civilization can develop.

## Physics
The simluation generates n bodies of the same mass in 2D space and calculates the net force on each body using Newton's law of universal gravitation. 

$$F = GMm/r^2$$

Using this force, the displacement, velocity and acceleration the simluation is then able to determine the path of the particle using the kinematic equations:

$$d=v_it + 1/2 at^2$$

$$v_f=v_i+at$$

where $t$ is taken as 1 second.

## Building the Simulation
The simluation is created using C++ which is good for high-performance graphics applications, allowing the simulation to run smoothly even with large value of N. The particles are rendered using the C library, SDL2 and the SDL_Window and SDL_Renderer are abstracted away using classes. The collection of N particle, each particle and the 2D vectors for position, velocity, acceleration, displacement are all encapsulated in theire own classes.

## What I Learned
This project was a great review of C++, object-oriented concepts, and kinematic concepts. I'm also really happy that I was able to learn SDL from scratch in a short span of time and bring the numbers computed within the C++ code to life. 

## Next steps
- Allow the simluation to represent the movement of the particle using a more realistic time, speed and mass scale to represent the movement of celitial celestial
- Add in a 3D aespect by generating particles of various opacities
- Improve the realism of the motion of the particles, especially the motion of particles during collisions
- Recreate the simulation, representing the particles as 3D sphere space using Unreal Engine
