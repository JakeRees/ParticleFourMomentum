#include<iostream>
#include<iomanip>
#include <utility>
#include "Particle.h"
#include "FourMomentum.h"

int main()
{
  Particle electron = Particle("electron", 1.0, 0.0, 0.0, 0.0);
  electron.print_data();

  return 0;
}