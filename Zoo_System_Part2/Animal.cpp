#pragma warning(disable: 4996)
#include "Animal.h"

int Animal::counter = 0;


Animal::Animal(const string& name, float weight, int birthYear, Area * area)
{
	setName(name);
	setWeight(weight);
	setBirthYear(birthYear);
	setArea(*area);
	animal_id = ++counter;
}

Animal::~Animal()
{
}

inline const string& Animal::getName() const
{
	return this->name;
}

inline float Animal::getWeight() const
{
	return this->weight;
}

inline int Animal::getId() const
{
	return this->animal_id;
}

inline int Animal::getBirthYear() const
{
	return this->birthYear;
}

ostream & operator<<(ostream & os, const Animal & animal)
{
	os  <<(typeid(animal).name() + 6) << "\nname :" << animal.getName() << "\nid:" << animal.getId()<< "\nweight: " << animal.getWeight() << "\nbirth year : " << animal.getBirthYear();
	animal.toOs(os);
	return os;
}


void Animal::setName(const string& name) throw(const string&)
{
	if (name.empty())
		throw string("name string can not be empty!");
	this->name = name;
}

void Animal::setArea(Area& area) 
{
		this->area = &area;
}

void Animal::setWeight(float weight) throw(const string&)
{
	if (weight < 0)
		throw string("weight must be positive number!");
	this->weight = weight;
}

void Animal::setBirthYear(int birthYear) throw(const string&)
{
	if (birthYear <= 0)
		throw string("birth year must be positive and bigger the zero!");
	this->birthYear = birthYear;
}
