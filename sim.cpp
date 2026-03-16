#include<iostream>
#include<iomanip>
#include "Particle.h"

int main()
{
  Particle electron = Particle("Electron", 5.11e5, 1.e6);

  electron.print_data();

  return 0;
}