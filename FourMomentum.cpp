#include "FourMomentum.h"
#include <stdexcept>
#include <string>

void return_missing_data()
{
  std::cerr << "\033[1;31mError: FourMomentum data has been moved or is "
            << "uninitialised. Returned 0.\033[0m" << std::endl;
}

void throw_missing_data()
{
  std::cerr << "\033[1;31mError: FourMomentum data has been moved or "
            << "is uninitialised.\033[0m" << std::endl;
}

FourMomentum::FourMomentum()
{
  four_momentum = new std::vector<double>;
  four_momentum->push_back(0.0);
  four_momentum->push_back(0.0);
  four_momentum->push_back(0.0);
  four_momentum->push_back(0.0);
}

FourMomentum::FourMomentum(double E, double px, double py, double pz)
{
  four_momentum = new std::vector<double>;
  if(E < 0) {
    std::cerr << "\033[1;31mError: Energy cannot be negative. Received E = " << E
              << ". Using default value E = 0.\033[0m" << std::endl;
    E = 0.0;
  }
  four_momentum->push_back(E);
  four_momentum->push_back(px);
  four_momentum->push_back(py);
  four_momentum->push_back(pz);
}

FourMomentum::~FourMomentum()
{
  delete four_momentum;
}

double FourMomentum::get_E() const
{
  if(!four_momentum) 
  {
    return_missing_data();
    return 0.0;
  }
  return (*four_momentum)[0];
}

double FourMomentum::get_px() const
{
  if(!four_momentum)
  {
    return_missing_data();
    return 0.0;
  }
  return (*four_momentum)[1];
}

double FourMomentum::get_py() const
{
  if(!four_momentum)
  {
    return_missing_data();
    return 0.0;
  }
  return (*four_momentum)[2];
}

double FourMomentum::get_pz() const
{
  if(!four_momentum)
  {
    return_missing_data();
    return 0.0;
  }
  return (*four_momentum)[3];
}

void FourMomentum::set_E(double E)
{
  // Energy cannot be negative in a four momentum
  if(E < 0) {
    std::cerr << "\033[1;31mError: Energy cannot be negative. Received E = " << E
              << ". Keeping current value.\033[0m" << std::endl;
    return;
  }
  if(!four_momentum) 
  {
    throw_missing_data();
    return;
  }
  (*four_momentum)[0] = E;
}

void FourMomentum::set_px(double px)
{
  if(!four_momentum) 
  {
    throw_missing_data();
    return;
  }
  (*four_momentum)[1] = px;
}

void FourMomentum::set_py(double py)
{
  if(!four_momentum)
  {
    throw_missing_data();
    return;
  }
  (*four_momentum)[2] = py;
}

void FourMomentum::set_pz(double pz)
{
  if(!four_momentum) 
  {
    throw_missing_data();
    return;
  }
  (*four_momentum)[3] = pz;
}