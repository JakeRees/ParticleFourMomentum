#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<string>
#include<cmath>
class Particle
{
private:
  std::string type {"None"};
  double mass {1000.0};
  double momentum {0.0};

public:

  Particle() = default ;

  Particle(std::string particle_type, double particle_mass, double particle_momentum)
  {
    set_type(particle_type);
    set_mass(particle_mass);
    set_momentum(particle_momentum);
  }

  ~Particle(){}
  double gamma();
  void print_data();

  std::string get_type();
  double get_mass();
  double get_momentum();
  double get_energy_ev();

  void set_type(std::string new_type);
  void set_mass(double new_mass);
  void set_momentum(double new_momentum);
};

#endif