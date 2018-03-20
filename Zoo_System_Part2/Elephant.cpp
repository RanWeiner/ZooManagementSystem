#include "Elephant.h"

Elephant::Elephant(const string& name, float weight, int birthYear, float sizeOfEars, float lengthOfTrunk): Animal(name, weight, birthYear)
{
	setSizeOfEars(sizeOfEars);
	setLengthOfTrunk(lengthOfTrunk);
}

inline float Elephant::getSizeOfEars() const
{
	return this->sizeOfEars;
}

inline float Elephant::getLengthOfTrunk() const
{
	return this->lengthOfTrunk;
}

void Elephant::setSizeOfEars(float sizeOfEars) throw(const string&)
{
	if (sizeOfEars <= 0)
		throw string("size of ears must be positive number!");
	this->sizeOfEars = sizeOfEars;
}

void Elephant::setLengthOfTrunk(float lengthOfTrunk) throw(const string&)
{
	if (lengthOfTrunk <= 0)
		throw string("length of Trunk must be positive number!");
	this->lengthOfTrunk = lengthOfTrunk;
}

void Elephant::toOs(ostream & os) const
{
	os << "\nsize of ears : " << sizeOfEars << "\nlength of trunk: " << lengthOfTrunk << endl;
}
