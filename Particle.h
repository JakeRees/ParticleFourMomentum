#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<string>
#include<cmath>
#include "FourMomentum.h"
class Particle
{
private:
  std::string type {"electron"};
  FourMomentum four_momentum = {FourMomentum(1, 0, 0, 0)};
  
public:

  Particle() = default;

  Particle(const std::string& particle_type, double E, double px, double py, double pz);

  ~Particle();

  Particle(const Particle& other);
  Particle& operator=(const Particle& other);
  Particle(Particle&& other) noexcept;
  Particle& operator=(Particle&& other) noexcept;

  std::string get_type() const;
  const FourMomentum& get_four_momentum() const;
  double get_invariant_mass() const;

  void set_type(const std::string& new_type);
  void set_four_momentum(double E, double px, double py, double pz);

  void print_data() const;
};

#endif