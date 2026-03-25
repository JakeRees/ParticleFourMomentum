main:
	g++ sim.cpp Particle.cpp FourMomentum.cpp -Wall -o sim.exe -std=gnu++17

clean:
	rm main.exe