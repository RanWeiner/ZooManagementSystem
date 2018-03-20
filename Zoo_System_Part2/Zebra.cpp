#include "Zebra.h"

Zebra::Zebra(const string& name, float weight, int birthYear, int numOfStrips) : Animal(name,weight, birthYear)
{
	setNumOfStrips(numOfStrips);
}

inline int Zebra::getNumOfStrips() const
{
	return this->numOfStrips;
}

void Zebra::setNumOfStrips(int numOfStrips) throw(const string&)
{
	if (numOfStrips < 0)
		throw string( "number of stripes must be positive number ");
	this->numOfStrips = numOfStrips;
}

void Zebra::toOs(ostream & os) const
{
	os << "\nNum of Strips : " << numOfStrips ;
}
