#include "Lion.h"


enum eManeColor { WHITE, BROWN, YELLOW, RED, ORANGE };
const string maneColorStr[] = { "White", "Brown", "Yellow", "Red", "Orange" };

Lion::Lion(const string& name, float weight, int birthYear, eManeColor maneColor) : Animal(name, weight, birthYear)
{
	setManeColor(maneColor);
}

inline bool Lion::setManeColor(Lion::eManeColor maneColor)
{
	this->maneColor;
	return true;
}

inline Lion::eManeColor Lion::getManeColor() const
{
	return this->maneColor;
}

void Lion::toOs(ostream & os) const
{
	os << "\nmane color : " << maneColorStr[getManeColor()] << endl;
}
