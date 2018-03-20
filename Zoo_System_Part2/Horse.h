
//  Donkey.h


#ifndef __HOURSE_H
#define __HOURSE_H

#include "Animal.h"

class Horse : virtual public Animal
{

private:
    float sizeOfHorseShoe;

	void setSizeOfHorseShoe(float sizeOfHorseShoe) throw (const string&);
    
public:
	Horse(const string& name, float weight, int birthYear, float sizeOfHorseShoe);
    
    Horse(const Horse& horse) = delete;
    const Horse& operator=(const Horse& horse) = delete;
    
    inline float getSizeOfHorseShoe() const;
    
	virtual void toOs(ostream& os) const override;
    
};


#endif /* __HOURSE_H */
