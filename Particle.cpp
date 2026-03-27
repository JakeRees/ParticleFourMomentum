#include<iostream>
#include <cmath>
#include <algorithm>
#include "Particle.h"

const std::string VALID_TYPES[6] = {"electron", "muon", "tau", "antielectron",
                                    "antimuon" , "antitau"};
 
Particle::Particle(const std::string& particle_type, double E, double px, double py, double pz)
  : four_momentum{E, px, py, pz}
{
  std::cout << "Calling Particle parameterised constructor" << std::endl;
  set_type(particle_type);
}

// Destructor
Particle::~Particle()
{
  std::cout << "Calling Particle destructor" << std::endl;
}

// Copy constructor
Particle::Particle(const Particle& other)
  : type{other.type}, four_momentum{other.four_momentum}
{
  std::cout << "Calling Particle copy constructor" << std::endl;
}
 
// Copy assignment operator
Particle& Particle::operator=(const Particle& other)
{
  std::cout << "Calling Particle copy assignment operator" << std::endl;
  if(this != &other)
  {
    type = other.type;
    four_momentum = other.four_momentum;
  }
  return *this;
}
 
// Move constructor
Particle::Particle(Particle&& other) noexcept
  : type{std::move(other.type)}, four_momentum{std::move(other.four_momentum)}
{
  std::cout << "Calling Particle move constructor" << std::endl;
}
 
// Move assignment operator
Particle& Particle::operator=(Particle&& other) noexcept
{
  std::cout << "Calling Particle move assignment operator" << std::endl;
  if(this != &other)
  {
    type = std::move(other.type);
    four_momentum = std::move(other.four_momentum);
  }
  return *this;
}

std::string Particle::get_type() const
{
 return type;
}

const FourMomentum& Particle::get_four_momentum() const
{ 
  return four_momentum; 
}

double Particle::get_invariant_mass() const
{ 
  return std::sqrt(four_momentum.dot_product(four_momentum)); 
}

void Particle::set_type(const std::string& new_type)
{
  // Make sure this works regardless of capitilisation
  std::string lower_type = new_type;
  std::transform(lower_type.begin(), lower_type.end(), lower_type.begin(), ::tolower);

  // Only allows specificied valid particles
  for (std::string check : VALID_TYPES)
  {
    if (lower_type == check)
    {
      type = lower_type;
      return;
    }
  }
  
  std::cout << "\033[1;31mError: " << new_type << " is not a valid particle type"
            << " please select either 'electron', 'muon' or 'tau' \033[0m" << std::endl;
}

void Particle::set_four_momentum(double E, double px, double py, double pz)
{
  four_momentum.set_E(E);
  four_momentum.set_px(px);
  four_momentum.set_py(py);
  four_momentum.set_pz(pz);
}

void Particle::print_data() const
{
  std::cout << "Particle: " << type << " | ";
  four_momentum.print_value();
  std::cout << " | Invariant Mass = " << get_invariant_mass() << "\n";
}

FourMomentum Particle::operator+(const Particle& other) const
{
  // Overloaded "+" operator, sums components of FourMomentum pairwise
  return four_momentum + other.four_momentum;
}
 
double Particle::dot_product(const Particle& other) const
{
  // Returns dot product of two four momentums of each particle
  return four_momentum.dot_product(other.four_momentum);
}