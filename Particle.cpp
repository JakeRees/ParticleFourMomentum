#include<iostream>
#include <cmath>
#include <algorithm>
#include "Particle.h"

const std::string VALID_TYPES[3] = {"electron", "muon", "tau"};
 
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

std::string Particle::get_type()
{
 return type;
}

FourMomentum Particle::get_four_momentum() 
{ 
  return four_momentum; 
}

void Particle::set_type(std::string new_type)
{
  // Make sure this works regardless of capitilisation
  std::transform(new_type.begin(), new_type.end(), new_type.begin(), ::tolower);
  // Only allows specific valid particles
  for (std::string check : VALID_TYPES)
  {
    if (new_type == check)
    {
      type = new_type;
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

void Particle::print_data()
{
  std::cout << "Particle: " << type << " | ";
  four_momentum.print_value();
}