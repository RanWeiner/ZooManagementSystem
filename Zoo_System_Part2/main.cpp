
//  main.cpp

#pragma warning( disable : 4290 )
#include <iostream>
#include <string>
#include "Zoo.h"
#include "Area.h"
#include "Animal.h"
#include "Worker.h"
#include "AreaManager.h"
#include "Veterinarian.h"
#include "Keeper.h"
#include "MaintenanceWorker.h"
#include "Elephant.h"
#include "Giraffe.h"
#include "Horse.h"
#include "Lion.h"
#include "Penguin.h"
#include "Zebra.h"
#include "Zebroid.h"


using namespace std;

AreaManager** createAreaManagers(int& numOfManagers) throw(const string&);
Area** createAllAreas(AreaManager **managers, int& numOfAreas) throw(const string&);
void addAreasToZoo(Zoo& zoo, Area** areas, int& numOfAreas) throw(const string&);
Animal** createAnimals(int& numOfAnimals) throw(const string&);
void addAllAnimalsToZoo(Zoo& myZoo, Animal** animals, int &numOfAnimals) throw(const string&);
Keeper** createAllKeepers(int& numOfKeepers) throw(const string&);
void addKeepersToZoo(Zoo& myZoo, Keeper** keepers, int numOfKeepers) throw(const string&);
Veterinarian** createAllVeterinarian(int& numOfVeterinarian) throw(const string&);
void addAllVeterinarianToZoo(Zoo& myZoo, Veterinarian**vets, int numOfVeterinarian) throw(const string&);
void freeAllAreaManagers(AreaManager** areaManagers, int& numOfAreaManagers);
void freeAllAreas(Area** areas, int& numOfAreas);
void freeAllAnimals(Animal** animals, int& numOfAnimals);
void freeAllVeterinarian(Veterinarian** vets, int& numOfVeterinarian);
void freeAllKeepers(Keeper** keepers, int& numOfKeepers);
static int 	isAllocated;

void main() 
{
	int numOfManagers, numOfAreas, numOfAnimals, numOfKeepers, numOfVeterinarian;
	AreaManager** managers = nullptr;
	Area** areas = nullptr;
	Animal** animals = nullptr;
	Keeper** keepers = nullptr;
	Veterinarian** vets = nullptr;

	try
	{
		Area quarentineArea("quarentineArea", 4, 4);
		Zoo& myZoo = Zoo::getInstance("My Zoo", 10, quarentineArea);

		managers = createAreaManagers(numOfManagers);

		areas = createAllAreas(managers, numOfAreas);
		// add all areas
		addAreasToZoo(myZoo, areas, numOfAreas);

		animals = createAnimals(numOfAnimals);
		// add animals
		addAllAnimalsToZoo(myZoo, animals, numOfAnimals);

		keepers = createAllKeepers(numOfKeepers);
		// add all the keepers
		addKeepersToZoo(myZoo, keepers, numOfKeepers);

		vets = createAllVeterinarian(numOfVeterinarian);
		// add all vets
		addAllVeterinarianToZoo(myZoo, vets, numOfVeterinarian);
		
		// print the whole zoo
		cout << "\nMy Zoo: \n" << myZoo << endl;

/*
		cout << "Notifications!"<<endl;
		Animal* a = new Horse("hoooorse", 100, 1991, 9.5);
		myZoo.addAnimal(*a, "A1");

		Animal* b = new Giraffe("gifo",90,1991,70);
		*areas[0] += *b;
*/

		cout << endl;
		system("pause");
	}
	catch (const string& e)
	{
		cout << e <<endl;
		system("pause");
	}
	catch (...)
	{
		cout << "Something went wrong.."<<endl;
		system("pause");
	}

	// free all allocations
	freeAllAnimals(animals, numOfAnimals);
	freeAllAreaManagers(managers, numOfManagers);
	freeAllAreas(areas, numOfAreas);
	freeAllKeepers(keepers, numOfKeepers);
	freeAllVeterinarian(vets, numOfVeterinarian);

}

AreaManager** createAreaManagers(int& numOfManagers) throw(const string&)
{
	isAllocated = 0;
	numOfManagers = 3;
	AreaManager** managers = new AreaManager*[numOfManagers];
	managers[0] = new AreaManager("Yogev", 31235, 5000, 123);
	managers[1] = new AreaManager("Moshe", 51455, 4500, 456);
	managers[2] = new AreaManager("Roie", 84578, 4800, 789);
	isAllocated = 1;
	return managers;
}
Area** createAllAreas(AreaManager **managers, int& numOfAreas) throw(const string&)
{
	numOfAreas = 3;
	Area** areas = new Area*[numOfAreas];
	isAllocated = 0;
	areas[0] = new Area("A1", 4, 4, managers[0]);
	areas[1] = new Area("A2", 4, 4, managers[1]);
	areas[2] = new Area("A3", 4, 4, managers[2]);
	isAllocated = 1;
	return areas;
}
void addAreasToZoo(Zoo& zoo, Area** areas, int& numOfAreas) throw(const string&)
{
	for (int i = 0; i < numOfAreas; i++)
		zoo.addArea(*areas[i]);
}
Animal** createAnimals(int& numOfAnimals) throw(const string&) 
{
	numOfAnimals = 4;
	Animal** animals = new Animal*[numOfAnimals];
	isAllocated = 0;
	animals[0] = new Penguin("Pini", 1.2f, 2005, Penguin::eSeaFood::CRAB);
	animals[1] = new Elephant("Eli", 2.5f, 2003, 1.35f, 2.75f);
	animals[2] = new Horse("Horsy", 208.5f, 1998, 40.2f);
	animals[3] = new Zebroid("Zeze", 1.45f, 2010, 128, 38.6f);
	isAllocated = 1;
	return animals;
}
void addAllAnimalsToZoo(Zoo& myZoo, Animal** animals, int &numOfAnimals) throw(const string&)
{
	for (int i = 0; i < numOfAnimals - 1; i++)
		myZoo.addAnimal(*animals[i], myZoo.getAllAreas()[i]->getName());
	// another animal to the last area
	myZoo.addAnimal(*animals[3], myZoo.getAllAreas()[2]->getName());
}
Keeper** createAllKeepers(int& numOfKeepers) throw(const string&)
{
	numOfKeepers = 3;
	Keeper** keepers = new Keeper*[numOfKeepers];
	isAllocated = 0;
	keepers[0] = new Keeper("Kipi", 312542, 7500, Keeper::eAnimal::PENGUIN);
	keepers[1] = new Keeper("Keepi", 387542, 7500, Keeper::eAnimal::ELEPHANT);
	keepers[2] = new Keeper("Keepee", 955642, 7500, Keeper::eAnimal::HORSE);
	isAllocated = 1;
	return keepers;
}
void addKeepersToZoo(Zoo& myZoo, Keeper** keepers, int numOfKeepers) throw(const string&)
{
	for (int i = 0; i < numOfKeepers; i++)
		myZoo.addWorker(*keepers[i], myZoo.getAllAreas()[i]->getName());
}
Veterinarian** createAllVeterinarian(int& numOfVeterinarian) throw(const string&)
{
	numOfVeterinarian = 3;
	Veterinarian** vets = new Veterinarian*[numOfVeterinarian];
	isAllocated = 0;
	vets[0] = new Veterinarian("Vivi", 45875, 10000, 5);
	vets[1] = new Veterinarian("Vuvu", 87457, 10000, 8);
	vets[2] = new Veterinarian("Kobi", 26584, 10000, 10);
	isAllocated = 1;
	return vets;
}
void addAllVeterinarianToZoo(Zoo& myZoo, Veterinarian**vets, int numOfVeterinarian) throw(const string&)
{
	for (int i = 0; i < numOfVeterinarian; i++)
		myZoo.addWorker(*vets[i], myZoo.getAllAreas()[i]->getName());
}
void freeAllAreaManagers(AreaManager** areaManagers, int& numOfAreaManagers)
{
	if (isAllocated)
	{
		for (int i = 0; i < numOfAreaManagers; i++)
			delete areaManagers[i];
	}
	delete []areaManagers;
}
void freeAllAreas(Area** areas, int& numOfAreas)
{
	if (isAllocated)
	{
		for (int i = 0; i < numOfAreas; i++)
			delete areas[i];
	}

	delete []areas;
}
void freeAllAnimals(Animal** animals, int& numOfAnimals)
{
	if (isAllocated)
	{
		for (int i = 0; i < numOfAnimals; i++)
			delete animals[i];
	}

	delete []animals;
}
void freeAllVeterinarian(Veterinarian** vets, int& numOfVeterinarian)
{
	if (isAllocated)
	{
		for (int i = 0; i < numOfVeterinarian; i++)
			delete vets[i];
	}
	delete []vets;
}
void freeAllKeepers(Keeper** keepers, int& numOfKeepers)
{
	if (isAllocated)
	{
		for (int i = 0; i < numOfKeepers; i++)
			delete keepers[i];
	}
	delete []keepers;
}