#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include "nbody.h"
#include "window.h"
#include "renderer.h"
#include "particle.h"

int main( int argc, char *argv[])
{
    int n = 600;
    double radius = 1;
    char useDefault = 'N';

    do 
    {
        std::cout << "Do you want to use default variables [Y/N]: ";
        std::cin >> useDefault;
    }
    while (useDefault != 'Y' && useDefault != 'N');

    if (useDefault == 'N')
    {
        do
        {
            std::cout << "Number of particles (2-1000): ";
            std::cin >> n;
        }
        while(n < 2 || n > 200);

        do
        {
            std::cout << "particle width (1-10): ";
            std::cin >> radius;
        }
        while(radius < 1 || radius > 10);
    }

    Window window{"N-Body Physics Simulation", 800, 600};
    Renderer renderer{window};

    nbody::Nbody x{renderer, std::pow(10, 5), n, radius};

    while(!window.isClosed())
    {
        window.pollEvents();
        renderer.clearWindow();
        x.drawBodies();
        renderer.present();
        x.moveBodies();
    }

    return 0;
}