#include<iostream>
#include<iomanip>
#include <utility>
#include "Particle.h"
#include "FourMomentum.h"

int main()
{
  Particle electron = Particle("electron", 0.511, 43.0, 21.0, 45.0);
  Particle muon = Particle("electron", 105.66, 22.0, 35.0, 12.0);

  FourMomentum momentum_sum = electron.get_four_momentum() + muon.get_four_momentum();
  double momentum_product = electron.get_four_momentum().dot_product(muon.get_four_momentum());

  std::cout << "\nMomentum sum: ";
  momentum_sum.print_value();
  std::cout << "Momentum dot product: " << momentum_product << "\n";

  electron.print_data();
  std::cout << "\n";

  return 0;
}