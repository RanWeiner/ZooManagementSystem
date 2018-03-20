#pragma warning(disable: 4290)
//  Worker.h

#ifndef __WORKER_H
#define __WORKER_H

#include <iostream>
#include <string>
#include "NewAnimalObserver.h"

using namespace std;

class Area;

class Worker : public NewAnimalObserver
{
    
private:
    string name;
    long idNumber;
    int salary;
	Area* area;

	void setName(const string& name) throw (const string&);
	void setIdNumber(long idNumber) throw (const string&);
    
public:
	Worker(const string& name, long idNumber, int salary, Area* area = nullptr) throw (const string&);
    //virtual ~Worker();
    
    Worker(const Worker& worker) = delete;
    const Worker& operator=(const Worker& worker) = delete;
    
    inline const string& getName() const;
    
    inline long getIdNumber() const;
    
    inline int getSalary() const;
    void setSalary(int salary) throw (const string&);
    
    inline const Area* getArea() const;
    void setArea( Area& area);
    
	virtual void toOs(ostream& os) const =0;
    friend ostream& operator<<(ostream& os, const Worker& worker);

	virtual void notify(int animal_id) const;
    
};

#endif /* __WORKER_H */
