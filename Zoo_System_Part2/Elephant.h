
//  Elephant.h


#ifndef __ELEPHANT_H
#define __ELEPHANT_H

#include "Animal.h"
#include "Area.h"

class Elephant : public Animal
{

private:
    float sizeOfEars;
    float lengthOfTrunk;

	void setSizeOfEars(float sizeOfEars) throw (const string&);
	void setLengthOfTrunk(float lengthOfTrunk) throw (const string&);
    
public:
	Elephant(const string& name, float weight, int birthYear, float sizeOfEars, float lengthOfTrunk);
    
    Elephant(const Elephant& elephant) = delete;
    const Elephant& operator=(const Elephant& elephant) = delete;
    
    inline float getSizeOfEars() const;
    inline float getLengthOfTrunk() const;
    
	virtual void toOs(ostream& os) const override;
 
};

#endif /* __ELEPHANT_H */
