#include<iostream>
#include<iomanip>
#include <utility>
#include "Particle.h"
#include "FourMomentum.h"

int main()
{
  FourMomentum momentum = FourMomentum(-1, 1, 1, 1);
  Particle electron = Particle("electron", 5.11e5, 1.e6);
  electron.print_data();

  return 0;
}