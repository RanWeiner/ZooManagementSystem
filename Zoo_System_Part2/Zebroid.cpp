
#include "Zebroid.h"

Zebroid::Zebroid(const string& name, float weight, int birthYear, int numOfStrips, float sizeOfHorseShoe) : Animal(name,weight,birthYear), Zebra(name, weight,birthYear,numOfStrips),Horse(name,weight,birthYear,sizeOfHorseShoe)
{
}



inline const string& Zebroid::getName() const
{
	return Animal::getName();
}

inline float Zebroid::getWeight() const
{
	return Animal::getWeight();
}

inline int Zebroid::getBirthYear() const
{
	return Animal::getBirthYear();
}

void Zebroid::toOs(ostream & os) const
{
	Zebra::toOs(os);
	Horse::toOs(os);
}
