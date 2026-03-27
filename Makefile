main:
	g++ sim.cpp Particle.cpp FourMomentum.cpp -Wall -o simulation.exe -std=gnu++17

clean:
	rm simulation.exe