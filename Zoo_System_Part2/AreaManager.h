
//  Area_Manager.h


#ifndef __AREA_MANAGER_H
#define __AREA_MANAGER_H

#include "Worker.h"

class AreaManager : public Worker
{
private:
	int yearsOfExperience;
	void setYearsOfExperience(int yearsOfExperience) throw (const string&);

public:
	AreaManager(const string& name, long idNumber, int salary, int yearsOfExperience);
    AreaManager(const AreaManager& areaManager) = delete;
    const AreaManager& operator=(const AreaManager& areaManager) = delete;
	inline int getYearsOfExperience() const;
	virtual void toOs(ostream& os) const override;
    
};


#endif /* __AREA_MANAGER_H */
