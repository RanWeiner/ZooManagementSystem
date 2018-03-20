#include "MaintenanceWorker.h"

MaintenanceWorker::MaintenanceWorker(const string& name, long idNumber, int salary, float shoeSize) : Worker(name ,idNumber, salary)
{
	setShoeSize(shoeSize);
}

void MaintenanceWorker::setShoeSize(float shoeSize) throw(const string&)
{
	if (shoeSize <= 0)
		throw string("invalid shoe size!");
	this->shoeSize = shoeSize;
}

void MaintenanceWorker::toOs(ostream & os) const
{
	os << " , shoe size: " << getShoeSize()<<endl;
}
