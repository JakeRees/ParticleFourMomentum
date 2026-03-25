// FourMomentum.h
// Interface for the FourMomentum class
// Stores P = (E, px, py, pz) in natural units (MeV, c=1)
// Internally uses a pointer to a dynamically allocated std::vector<double>

#ifndef FOURMOMENTUM_H
#define FOURMOMENTUM_H

#include <vector>
#include <iostream>

class FourMomentum
{
private:
  std::vector<double>* four_momentum;
  

public:

  FourMomentum();

  FourMomentum(double E, double px, double py, double pz);

  ~FourMomentum();     

  FourMomentum(const FourMomentum& other);
  FourMomentum& operator=(const FourMomentum& other);
  FourMomentum(FourMomentum&& other) noexcept;
  FourMomentum& operator=(FourMomentum&& other) noexcept;

  double get_E() const;
  double get_px() const;
  double get_py() const;
  double get_pz() const;

  void set_E(double E);
  void set_px(double px);
  void set_py(double py);
  void set_pz(double pz);

  void print_value() const;
};

#endif