#pragma warning(disable: 4996)
#include "Area.h"

Area::Area(const string& name, int maxNumberOfAnimals, int maxNumberOfWorkers, AreaManager * areaManager) throw (const string&)
{
	setAreaName(name);
	setMaxNumberOfAnimals(maxNumberOfAnimals);
	setMaxNumberOfWorkers(maxNumberOfWorkers);
	workers.reserve(maxNumberOfWorkers);
	setAreaManager(*areaManager);

}


inline const string& Area::getName() const
{
	return this->name;
}
inline long Area::getNumOfAnimals() const
{
	return animals.getSize();
}
inline long Area::getMaxNumberOfAnimals() const
{
	return this->maxNumberOfAnimals;
}
inline long Area::getNumOfWorkers() const
{
	return workers.size();
}
inline long Area::getMaxNumberOfWorkers() const
{
	return this->maxNumberOfWorkers;
}
inline const AreaManager* Area::getAreaManager() const
{
	return areaManager;
	
}
 AreaManager * Area::getAreaManager()
{
	return this->areaManager;
}
void Area::setAreaName(const string& name)  throw (const string&)
{
	if (name.empty())
		throw string("name string can not be empty!");
	this->name = name;

}
void Area::setMaxNumberOfAnimals(int maxNumberOfAnimals) throw(const string&)
{
	if (maxNumberOfAnimals <= 0 || maxNumberOfAnimals < getNumOfAnimals())
		throw string("max number of animals is invalid!");
	this->maxNumberOfAnimals = maxNumberOfAnimals;
}
void Area::setMaxNumberOfWorkers(int maxNumberOfWorkers) throw(const string&)
{
	if (maxNumberOfWorkers <= 0 || maxNumberOfWorkers < getNumOfWorkers())
		throw string("max number of workers is invalid!");
	this->maxNumberOfWorkers = maxNumberOfWorkers;
}
void Area::setAreaManager(AreaManager & areaManager)
{
	this->areaManager = &areaManager;
}
void Area::addAnimal(Animal & animal) throw(const string&)
{
		if (this->getNumOfAnimals() >= this->maxNumberOfAnimals)
			throw string("can not add new animal, the area is already full with animals!");

		notifyAllWorkers(animal.getId());
		animals.insertLast(&animal);
}
void Area::addWorker(Worker & worker) throw(const string&)
{
		if (this->getNumOfWorkers() >= this->maxNumberOfWorkers)
			throw string("can not add new worker, the area is already full with workers!");
		workers.push_back(&worker);
}
 const MyLinkedList<Animal*>& Area::getAllAnimals() const
{
	 return animals;
}
 const vector<Worker*>& Area::getAllworkers() const
{
	return workers;
	
}
void Area::operator+=(Animal & animal)
{
	addAnimal(animal);
}
bool Area::operator>(const Area & area) const  //compare amount of animals + workers
{
	int x =this->getNumOfAnimals() + this->getNumOfWorkers();
	int y = area.getNumOfAnimals() + area.getNumOfWorkers();
	return x ? x > y : y;
}
bool Area::operator<=(const Area & area) const
{
	return (!Area::operator>(area));	
}
bool Area::operator==(const Area & area) const    //compare num of animals
{
	return (this->getNumOfAnimals() == area.getNumOfAnimals());
}
void Area::operator-=(const Animal & animal)
{
	removeAnimal(animal);
}
void Area::removeAnimal(const Animal & animal) throw(const string&)
{
	animals.removeItem(animal.getId());
}
ostream & operator<<(ostream & os, const Area & area)
{
	vector < Worker*> allWorkers = area.getAllworkers();
	vector<Worker*>::const_iterator itr = allWorkers.begin();
	vector<Worker*>::const_iterator itrEnd = allWorkers.end();

	int AreaAnimals = area.getNumOfAnimals();
	int numOfWorkers = allWorkers.size();
	os <<"\n\n**************\tArea name: '" << area.getName() << "'\t**************\n\n" << *(area.getAreaManager())
		<<"\ncurrent number of animals: " <<
		AreaAnimals << ", out of maximum: " << area.getMaxNumberOfAnimals() << "\ncurrent number of workers: " << numOfWorkers
		<< ", out of maximum: " << area.getMaxNumberOfWorkers() << "\n\nThe ANIMALS: " << endl;
	area.getAllAnimals().print();
	os << "\n\nThe STAFF: "<< endl;

	for (;itr!=itrEnd;++itr)
	{
		os << "\n" << **itr << endl;
	}
	return os;
}
void Area::notifyAllWorkers(int animal_id) const
{
	vector<Worker*> allWorkers = getAllworkers();
	vector<Worker*> ::const_iterator itr = allWorkers.begin();
	vector<Worker*> ::const_iterator itrEnd = allWorkers.end();
	for (; itr != itrEnd; ++itr)
	{
		(*itr)->notify(animal_id);

	}
}