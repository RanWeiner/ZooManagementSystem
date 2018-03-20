#include "AreaManager.h"


AreaManager::AreaManager(const string& name, long idNumber, int salary, int yearsOfExperience) : Worker(name, idNumber, salary)
{
	setYearsOfExperience(yearsOfExperience);
}

inline int AreaManager::getYearsOfExperience() const
{
	return this->yearsOfExperience;
}

void AreaManager::setYearsOfExperience(int yearsOfExperience) throw(const string&)
{
	if (yearsOfExperience < 0)
		throw string("years of experience must be positive number!");
	this->yearsOfExperience = yearsOfExperience;
}

void AreaManager::toOs(ostream & os) const
{
	os << "\nyears of experience: " << getYearsOfExperience() << endl;
}
