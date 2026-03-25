#include "FourMomentum.h"
#include <stdexcept>
#include <string>

double throw_missing_data()
{
  std::cerr << "\033[1;31mError: FourMomentum data has been moved or "
            << "is uninitialised.\033[0m" << std::endl;
  return 0.0;
}

FourMomentum::FourMomentum()
{
  std::cout << "Calling FourMomentum default constructor" << std::endl;
  four_momentum = new std::vector<double>;
  four_momentum->push_back(1.0);
  four_momentum->push_back(0.0);
  four_momentum->push_back(0.0);
  four_momentum->push_back(0.0);
}

FourMomentum::FourMomentum(double E, double px, double py, double pz)
{
  std::cout << "Calling FourMomentum paramaterised constructor" << std::endl;
  four_momentum = new std::vector<double>;
  if(E < 0) {
    std::cerr << "\033[1;31mError: Energy cannot be negative. Received E = " << E
              << ". Using default value E = 0.0\033[0m" << std::endl;
    E = 0.0;
  }
  four_momentum->push_back(E);
  four_momentum->push_back(px);
  four_momentum->push_back(py);
  four_momentum->push_back(pz);
}

//Destructor
FourMomentum::~FourMomentum()
{
  std::cout << "Calling FourMomentum destructor" << std::endl;
  delete four_momentum;
}

// Copy constructor
FourMomentum::FourMomentum(const FourMomentum& other)
{
  std::cout << "Calling FourMomentum copy constructor" << std::endl;
  four_momentum = new std::vector<double>(*(other.four_momentum));
}
 
// Copy assignment operator
FourMomentum& FourMomentum::operator=(const FourMomentum& other)
{
  std::cout << "Calling FourMomentum copy assignment operator" << std::endl;
  if(this != &other)
  {
    delete four_momentum;
    four_momentum = new std::vector<double>(*(other.four_momentum));
  }
  return *this;
}
 
// Move constructor
FourMomentum::FourMomentum(FourMomentum&& other) noexcept
{
  std::cout << "Calling FourMomentum move constructor" << std::endl;
  four_momentum = other.four_momentum;
  other.four_momentum = nullptr;
}
 
// Move assignment operator
FourMomentum& FourMomentum::operator=(FourMomentum&& other) noexcept
{
  std::cout << "Calling FourMomentum move assignment operator" << std::endl;
  if(this != &other)
  {
    delete four_momentum;
    four_momentum = other.four_momentum;
    other.four_momentum = nullptr;
  }
  return *this;
}

double FourMomentum::get_E() const
{
  if (!four_momentum) return throw_missing_data();
  return (*four_momentum)[0];
}

double FourMomentum::get_px() const
{
  if (!four_momentum) return throw_missing_data();
  return (*four_momentum)[1];
}

double FourMomentum::get_py() const
{
  if (!four_momentum) return throw_missing_data();
  return (*four_momentum)[2];
}

double FourMomentum::get_pz() const
{
  if (!four_momentum) return throw_missing_data();
  return (*four_momentum)[3];
}

void FourMomentum::set_E(double E)
{
  // Energy cannot be negative in a four momentum
  if(E < 0)
  {
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

void FourMomentum::print_value()
{
  if(!four_momentum)
  {
    throw_missing_data();
    return;
  }
  std::cout << "(E, px, py, pz) = (" << get_E() << ", " << get_px() << ", "
            << get_py() << ", " << get_pz() << ") MeV" << std::endl;
}

FourMomentum FourMomentum::operator+(const FourMomentum& other) const
{
  // Overloaded "+" operator, sums components pairwise
  return FourMomentum(get_E() + other.get_E(), get_px() + other.get_px(),
    get_py() + other.get_py(), get_pz() + other.get_pz());
}
 
double FourMomentum::dot_product(const FourMomentum& other) const
{
  // Returns dot product of two four momentums
  return get_E()  * other.get_E() - get_px() * other.get_px()
         - get_py() * other.get_py() - get_pz() * other.get_pz();
}