
//  Zoo.h

#ifndef __ZOO_H
#define __ZOO_H
#include <string>
#include "Area.h"
#include "Worker.h"
#include "Animal.h"
#include <vector>

using namespace std;

class Zoo
{
private:
	Zoo(const string& name, int maxNumOfAreas, Area& quarentineArea) throw (const string&);
    string name;
    int maxNumOfAreas;
	vector <Area*> areas;
	Area quarentineArea;

	void setName(const string& name) throw(const string&);
	void setMaxNumOfAreas(int maxNumOfAreas) throw (const string&);

	static Zoo myZoo;

public:
	static Zoo& getInstance(const string& name, int maxNumOfAreas, Area& quarentineArea) throw (const string&);

	Zoo(const Zoo& other) = delete;
	const Zoo& operator=(const Zoo& zoo) = delete;

    const string& getName() const;
    int getMaxNumOfAreas() const;
    int getNumOfAreas() const;
	const Area& getQuarentineAreaArea() const;
	void addArea(Area& area)  throw (const string&);
	void addAnimal(Animal& animal, const string& areaName)  throw (const string&);
	void removeAnimal(Animal & animal, const string & areaName) throw(const string &);
	void addWorker(Worker& worker, const string& areaName)  throw (const string&);
	
 
	const vector<Area*>& getAllAreas() const;
    void operator+(Area& area) throw (const string&);
    const Area& operator[](int index) const throw (const string&);
    friend ostream& operator<<(ostream& os, const Zoo& zoo);


};


#endif /* __ZOO_H */
