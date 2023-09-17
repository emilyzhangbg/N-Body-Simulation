all:
	g++ -I src/include -L src/lib -o bin/main src/main.cpp src/window.cpp src/renderer.cpp src/nbody.cpp src/particle.cpp src/vector.cpp -lmingw32 -lSDL2main -lSDL2