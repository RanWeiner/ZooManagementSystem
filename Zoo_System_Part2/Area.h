
#ifndef __AREA_H
#define __AREA_H

#include <iostream>
#include <string>
#include "AreaManager.h"
#include "Worker.h"
#include "Animal.h"
#include "MyLinkedList.h"
#include <vector>

class Animal;
using namespace std;

class Area
{
private:
	string name;
	int maxNumberOfAnimals;
	int maxNumberOfWorkers;
	AreaManager* areaManager;
	MyLinkedList<Animal*> animals;
	vector<Worker*> workers;

	void setMaxNumberOfAnimals(int maxNumberOfAnimals) throw (const string&);
	void setMaxNumberOfWorkers(int maxNumberOfWorkers) throw (const string&);

public:
	Area(const string& name, int maxNumberOfAnimals, int maxNumberOfWorkers, AreaManager* areaManager = nullptr) throw(const string&);
	//~Area();

	Area(const Area& area) = delete;
	const Area& operator=(const Area& area) = delete;

	inline const string& getName() const;
	inline long getNumOfAnimals() const;
	inline long getMaxNumberOfAnimals() const;
	inline long getNumOfWorkers() const;
	inline long getMaxNumberOfWorkers() const;
	void setAreaName(const string& name)  throw (const string&);
	inline  const AreaManager* getAreaManager() const;
	AreaManager* getAreaManager();
	void setAreaManager( AreaManager& areaManager);
	void addAnimal(Animal& animal) throw (const string&);
	void addWorker(Worker& worker) throw (const string&);

	const MyLinkedList<Animal*>& getAllAnimals() const;
	const vector<Worker*>& getAllworkers() const;

	void operator+=(Animal& animal);
	bool operator<=(const Area& area) const;
	bool operator>(const Area& area) const;
	bool operator==(const Area& area) const;
	void operator-=(const Animal & animal);
	void removeAnimal(const Animal & animal) throw(const string &);
	void notifyAllWorkers(int animal_id) const;
	friend ostream& operator<<(ostream& os, const Area& area);

};



#endif /* __AREA_H */
