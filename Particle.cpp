#include<iostream>
#include <cmath>
#include <algorithm>
#include "Particle.h"

std::string Particle::get_type()
{
 return type;
}

double Particle::get_mass()
{
  return mass;
}

double Particle::get_momentum()
{
  return momentum;
}

double Particle::get_energy_ev()
{
  return sqrt(mass * mass + momentum * momentum);
}

void Particle::set_type(std::string new_type)
{
  std::transform(new_type.begin(), new_type.end(), new_type.begin(), ::tolower);
  std::string valid_types[3] = {"electron", "muon", "tau"};
  for (std::string type : valid_types)
  {
    if (new_type == type)
    {
      type = new_type;
      return;
    }
  }
  
  std::cout << "\033[1;31mError: " << new_type << " is not a valid particle type"
            << " please select either 'electron', 'muon' or 'tau' \033[0m" << std::endl;
}

void Particle::set_mass(double new_mass)
{
  if (new_mass < 0)
  {
    std::cout << "\033[1;31mError: Particle mass must be positive\033[0m" << std::endl;
    return;
  }

  mass = new_mass;
}

void Particle::set_momentum(double new_momentum)
{
  momentum = new_momentum;
}

void Particle::print_data()
{
  std::cout.precision(3);
  std::cout<<"Particle: [type,m,p,E] = ["<<type<<","<< mass
	   <<","<<momentum<<","<<get_energy_ev()<<"]"<<std::endl;
  return;
}

double Particle::gamma()
{
  return get_energy_ev()/mass;
}