# ParticleFourMomentum

## 🌟 Highlights

- Create particle objects with associated four momentums
- Includes input checks
- Call basic operations for particle four momentums

## ⌛ Development Timeline

### Disclosure of Delegation to Generative AI:

No generative AI was used in the writing of or debugging of this code, all code was written and debugged by me with the use of the internet.

### Description of development

**Note: Assignment didn't require physics checks on four momentum - so this hasn't been included, only a check to ensure positive E.**

First created a skeleton Particle and FourMomentum class. I created the four momentum class before creating all the constructors and assignment operators to do memory management all at once instead of adding it in after. The four momentum within the FourMomentum class has been stored as a pointer to a vector of doubles. I decided to use a raw pointer instead of a smart pointer to better show the need for proper memory management (as a smart pointer will just delete itself when it goes out of scope).

I added input validation to the setter methods for each source, and decided to make all getter functions const to ensure there is no possible way to accidentally overide data. As required by the assignment, the FourMomentum class uses get_x() and set_x() for each component instead of for the entire four momentum at once. I then added the required dot product and + operators to the fourmomentum class.

I then created the tests in main which simply utilises each move and copy operator to demonstrate they work as intended. 

## 🚀 Usage Instructions

This program can be compiled using the following compilation command:  
`g++ sim.cpp Particle.cpp FourMomentum.cpp -Wall -o simulation.exe -std=gnu++17`  
Or alternatively by using the included MakeFile.

This program instantiates 8 particle objects and demonstrates each constructor/destructor/operators type given by the rule of 5.

### Class Documentation

<ins>Particle:</ins>
This class is a blueprint for leptons of the standard model.

**Attributes:**
- string type: The name/type of particle.
- FourMomentum four_momentum: FourMomentum object which contains energy and momentum data for the particle

**Methods:**
- void print_data(): Prints out all relevant information about the particle.

<ins>FourMomentum:</ins>
This class is a blueprint for FourMomentum objects which contain a vector holding data on energy and momentum for use in relativity calculations.

**Attributes:**
- vector<double>* four_momentum: Contains energy and momentum components.

**Methods:**
- void print_value(): Prints out the the values of each component.
- FourMomentum operator+(const FourMomentum& other): Sums two FourMomentums using + (Overloads the default + operator).
- double dot_product(const FourMomentum& other): Returns the dot product of the two given FourMomentum objects.

### How the main() function works

Instantiates 8 particle objects and stores these as a vector. Then for various particles in the list it performs either move or copy operators to demonstrate each works as intended and memory is managed appropriately. It also demonstrates input validation at the end to show input is correctly validated.