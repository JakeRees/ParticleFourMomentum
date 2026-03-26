#include<iostream>
#include<iomanip>
#include <utility>
#include "Particle.h"
#include "FourMomentum.h"

int main()
{

  std::vector<Particle> particles;
  // Similar particles should have the same invariant mass, regardless of momentums
  particles.push_back(Particle("electron", 3.7764, 1.0, 2.0, 3.0));
  particles.push_back(Particle("electron", 3.3558, -1.0, 3.0, 1.0));
  particles.push_back(Particle("muon", 121.0952, 50.0, 30.0, 10.0));
  particles.push_back(Particle("muon", 129.4760, -40.0, 20.0, 60.0));
  particles.push_back(Particle("antimuon", 113.5299, 10.0, -5.0, 40.0));
  particles.push_back(Particle("antimuon", 112.6456, 20.0, 15.0, -30.0));
  particles.push_back(Particle("tau", 1791.5723, 100.0, 50.0, 200.0));
  particles.push_back(Particle("antitau", 1785.9819, -80.0, 60.0, 150.0));

  std::cout << "\n Particle List: \n";
  for(auto& particle : particles) 
  {
    particle.print_data();
    std::cout << "\n";
  }
  std::cout << "\n";

  // Testing required by assignment instructions
  FourMomentum electron_sum = particles[0].get_four_momentum() + particles[1].get_four_momentum();
  std::cout << "\n\nElectron four momentum sum:";
  electron_sum.print_value();
  std::cout << "\n\n";

  // four momentum is private, hence the get_four_momentum() instead of 
  // direct particle addition
  double muon_dot = particles[2].get_four_momentum().dot_product(particles[3].get_four_momentum());
  std::cout << "\nMuon dot product: " << muon_dot << " MeV^2\n\n";

  Particle electron_copy;
  electron_copy = particles[0];
  std::cout << "\nCopied electron data: ";
  electron_copy.print_data();
  std::cout << "\n\n";

  Particle muon_copy(particles[2]);
  std::cout << "\nCopied muon data: ";
  muon_copy.print_data();
  std::cout << "\n\n";

  // Move operator here

  std::cout << "Before move: ";
  particles[4].print_data();
  std::cout << "\n\n";
  Particle moved_antimuon;
  moved_antimuon = std::move(particles[4]);
  std::cout << "\nAfter move (new object): ";
  moved_antimuon.print_data();
  std::cout << "\n\n";

  return 0;
}