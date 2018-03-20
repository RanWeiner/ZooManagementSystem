
//  Animal.h

// the animal Id is generated based their entrence order to the zoo.
//which means in the main the order they inserted to the area

#ifndef __ANIMAL_H
#define __ANIMAL_H

#include <iostream>
#include <string>
#include "Area.h"

using namespace std;

class Animal
{
    
private:
	static int counter;	
	string name;
    float weight;
    int birthYear;
    Area* area;
	int animal_id;

	void setName(const string& name) throw (const string&);
	void setArea(Area & area);
	void setWeight(float weight) throw (const string&);
	void setBirthYear(int birthYear) throw (const string&);
    
public:
	Animal(const string& name, float weight, int birthYear, Area* area = nullptr);
    virtual ~Animal();
    
    Animal(const Animal& animal) = delete;
    const Animal& operator=(const Animal& animal) = delete;

    virtual inline const string& getName() const;
	virtual inline float getWeight() const;
	virtual inline int getId() const;
	virtual inline int getBirthYear() const;
	virtual void toOs(ostream& os) const =0;
    friend ostream& operator<<(ostream& os, const Animal& animal);

};

#endif /* __ANIMAL_H */
