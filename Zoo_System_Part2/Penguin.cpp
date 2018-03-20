#include "Penguin.h"

enum eSeaFood { SHRIMP, CRAB, FISH, CALAMARI };
const string seaFoodStr[] = { "Shrimp", "Crab", "Fish", "Calamari"};


Penguin::Penguin(const string& name, float weight, int birthYear, eSeaFood favoriteFood) : Animal(name, weight, birthYear)
{
	setFavoriteFood(favoriteFood);
}

inline bool Penguin::setFavoriteFood(Penguin::eSeaFood favoriteFood)
{
	this->favoriteFood;
	return true;
}

inline Penguin::eSeaFood Penguin::getFavoriteFood() const
{
	return this->favoriteFood;
}

void Penguin::toOs(ostream & os) const
{
	os << "\nfavourite food: " << seaFoodStr[getFavoriteFood()] << endl;
}