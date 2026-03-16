#include<iostream>
#include <cmath>
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
  type = new_type;
}

void Particle::set_mass(double new_mass)
{
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