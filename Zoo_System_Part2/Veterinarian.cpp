#include "Veterinarian.h"


Veterinarian::Veterinarian(const string& name, long idNumber, int salary, int licenseNumber) : Worker(name, idNumber, salary)
{
	setLicenseNumber(licenseNumber);
}

inline int Veterinarian::getLicenseNumber() const
{
	return this->licenseNumber;
}

void Veterinarian::setLicenseNumber(int licenseNumber) throw(const string&)
{
	if (licenseNumber < 0)
		throw string("license number must be positive number!");
	this->licenseNumber = licenseNumber;
}


void Veterinarian::toOs(ostream & os) const
{
	os << "\nlicense number: " << getLicenseNumber()<<endl;
}
