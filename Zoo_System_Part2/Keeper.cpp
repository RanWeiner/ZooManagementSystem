#include "Keeper.h"


enum eAnimal { LION, PENGUIN, ELEPHANT, GIRAFFE, ZEBRA, HORSE, ZEBROID };
const string specialtyStr[] = { "Lion", "Penguin", "Elephent", "Giraffe", "Zebra", "Horse","Zebroid" };


Keeper::Keeper(const string& name, long idNumber, int salary, eAnimal keeperSpecialty) : Worker(name, idNumber,salary)
{
	setKeeperSpecialty(keeperSpecialty);
}

inline Keeper::eAnimal Keeper::getKeeperSpecialty() const
{
	return this->keeperSpecialty;
}


inline bool Keeper::setKeeperSpecialty(Keeper::eAnimal keeperSpecialty)
{
	this->keeperSpecialty;
	return true;
}


void Keeper::toOs(ostream& os) const
{
	os << "\nkeeper's specialty: " << specialtyStr[getKeeperSpecialty()] << endl;
}

