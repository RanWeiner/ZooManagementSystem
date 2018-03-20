
//  Giraffe.h


#ifndef __GIRAFFE_H
#define __GIRAFFE_H

#include "Animal.h"

class Giraffe : public Animal
{

private:
    float lengthOfNeck;

	void setLengthOfNeck(float lengthOfNeck) throw (const string&);
    
public:
	Giraffe(const string& name, float weight, int birthYear, float lengthOfNeck);
    
    Giraffe(const Giraffe& giraffe) = delete;
    const Giraffe& operator=(const Giraffe& giraffe) = delete;
    
    inline float getLengthOfNeck() const;
    
	virtual void toOs(ostream& os) const override;
    
};

#endif /* __GIRAFFE_H */
