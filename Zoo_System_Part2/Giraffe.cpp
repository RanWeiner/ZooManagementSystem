#include "Giraffe.h"

Giraffe::Giraffe(const string& name, float weight, int birthYear, float lengthOfNeck) : Animal(name , weight, birthYear)
{
	setLengthOfNeck(lengthOfNeck);
}

inline float Giraffe::getLengthOfNeck() const
{
	return this->lengthOfNeck;
}

void Giraffe::toOs(ostream & os) const
{
	os << "\nlength of neck : " << lengthOfNeck << endl;
}

void Giraffe::setLengthOfNeck(float lengthOfNeck) throw(const string&)
{
	if (lengthOfNeck <= 0)
		throw string("length of neck must be positive number");
	this->lengthOfNeck = lengthOfNeck;
}
