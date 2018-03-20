#include "Horse.h"

Horse::Horse(const string& name, float weight, int birthYear, float sizeOfHorseShoe) : Animal(name, weight,birthYear)
{
	setSizeOfHorseShoe(sizeOfHorseShoe);
}

void Horse::toOs(ostream & os) const
{
	os << "\nsize of horse shoe: " << sizeOfHorseShoe;
}

void Horse::setSizeOfHorseShoe(float sizeOfHorseShoe) throw(const string&)
{
	if (sizeOfHorseShoe < 0)
		throw string("horse shoe must be positive number!");
	this->sizeOfHorseShoe = sizeOfHorseShoe;
}

inline float Horse::getSizeOfHorseShoe() const
{
	return this->sizeOfHorseShoe;
}
