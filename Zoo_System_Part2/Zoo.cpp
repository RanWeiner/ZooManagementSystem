#pragma warning(disable: 4996)
#include "Zoo.h"


Zoo& Zoo::getInstance(const string& name, int maxNumOfAreas, Area& quarentineArea) throw (const string&)
{
	static Zoo myZoo(name, maxNumOfAreas, quarentineArea);
	return myZoo;
}

Zoo::Zoo(const string& name, int maxNumOfAreas, Area& quarentineArea) throw (const string&) : quarentineArea(quarentineArea.getName(),
	quarentineArea.getMaxNumberOfAnimals(), quarentineArea.getMaxNumberOfWorkers(), quarentineArea.getAreaManager()) 
{
	setName(name);
	setMaxNumOfAreas(maxNumOfAreas);
	areas.reserve(maxNumOfAreas);
}

const string& Zoo::getName() const
{
	return this->name;
}
int Zoo::getMaxNumOfAreas() const
{
	return this->maxNumOfAreas;
}
int Zoo::getNumOfAreas() const
{
	return this->areas.size();
}
const Area & Zoo::getQuarentineAreaArea() const
{
	return this->quarentineArea;
}
void Zoo::setName(const string& name) throw(const string&)
{
	if (name.empty())
		throw string("name string can not be empty!");
	this->name = name;
}
void Zoo::setMaxNumOfAreas(int maxNumOfAreas) throw(const string&)
{
	if (maxNumOfAreas <= 0)
		throw string("invalid number of areas, must be positive number!");
	this->maxNumOfAreas = maxNumOfAreas;
}
void Zoo::addArea(Area & area) throw(const string&)
{
	if (this->getNumOfAreas() >= this->maxNumOfAreas)
		throw string("there is no room for another area in the zoo!");
	areas.push_back(&area);
	
}
void Zoo::addAnimal(Animal & animal, const string& areaName) throw(const string&)
{
	vector<Area*> allAreas = getAllAreas();
	vector<Area*> ::const_iterator itr = allAreas.begin();
	vector<Area*> ::const_iterator itrEnd = allAreas.end();
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName().compare(areaName) == 0)
		{
			(*itr)->addAnimal(animal);
			return;
		}
	}
	throw string("can't find the given area!");
		
}
void Zoo::removeAnimal(Animal & animal, const string& areaName) throw(const string&)
{
	vector<Area*> allAreas = getAllAreas();
	vector<Area*> ::const_iterator itr = allAreas.begin();
	vector<Area*> ::const_iterator itrEnd = allAreas.end();
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName().compare(areaName) == 0)
		{
			(*itr)->removeAnimal(animal);
			return;
		}
	}
	throw string("can't find the given area!");
}
void Zoo::addWorker(Worker & worker, const string& areaName) throw(const string&)
{
	vector<Area*> allAreas = getAllAreas();
	vector<Area*> ::const_iterator itr = allAreas.begin();
	vector<Area*> ::const_iterator itrEnd = allAreas.end();
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName().compare(areaName) == 0)
		{
			(*itr)->addWorker(worker);
			return;
		}
	}
	throw string("can't find the given area!");
}
const vector<Area*>& Zoo::getAllAreas() const
{
	return areas;
}
void Zoo::operator+(Area & area) throw (const string&)
{
	if (this->getNumOfAreas() >= this->maxNumOfAreas)
		throw string("can not add new area, the zoo is already full with areas!");
	areas.push_back(&area);
}
const Area & Zoo::operator[](int index) const throw (const string&)
{
	if (index >= this->getNumOfAreas() || index < 0)
		throw string("index out of bounds!");
	return *(areas[index]);
}
ostream & operator<<(ostream & os, const Zoo & zoo)
{
	vector<Area*> allAreas = zoo.getAllAreas();
	vector<Area*> ::const_iterator itr = allAreas.begin();
	vector<Area*> ::const_iterator itrEnd = allAreas.end();
	os << "\nname: " << zoo.name << "\nnumber of areas: " << zoo.getNumOfAreas()
		<< "\nmax number of areas:" << zoo.maxNumOfAreas << endl;

	for (; itr != itrEnd; ++itr)
	{
		os << **itr << endl;
	}
	return os;
}
