#pragma warning(disable: 4996)
#include "Worker.h"




Worker::Worker(const string& name, long idNumber, int salary, Area * area) throw (const string&)
{
	setName(name);
	setIdNumber(idNumber);
	setSalary(salary);
	setArea(*area);
}

//Worker::~Worker(){}

inline const string& Worker::getName() const
{
	return this->name;
}

inline long Worker::getIdNumber() const
{
	return this->idNumber;
}

inline int Worker::getSalary() const
{
	return this->salary;
}

void Worker::setName(const string& name) throw (const string&)
{
	if (name.empty())
		throw string("name string can not be empty!");
	this->name = name;
}

void Worker::setIdNumber(long idNumber) throw(const string&)
{
	if (idNumber <= 0)
		throw string("id Number must be positive number!");
	this->idNumber = idNumber;
}

void Worker::setSalary(int salary) throw(const string&)
{
	if (salary < 0)
		throw string("salary must be positive number!");
	this->salary = salary;
}

inline const Area * Worker::getArea() const
{
	return this->area;
}

void Worker::setArea( Area & area)
{
	if (&area)
		this->area = &area;
	
}

void Worker::notify(int animal_id) const
{
	cout << "Dear " << this->getName() << ", you have a new animal in your area. the animal id: " << animal_id<<endl;
}

ostream & operator<<(ostream & os, const Worker & worker)
{
	os << (typeid(worker).name() + 6) << "\nname : " << worker.getName() << "\nid: " << worker.getIdNumber() << "\nsalary: " << worker.getSalary();
	worker.toOs(os);
	return os;
}
