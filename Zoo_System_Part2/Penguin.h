
//  Penguin.h


#ifndef __PENGUIN_H
#define __PENGUIN_H

#include "Animal.h"

class Penguin : public Animal
{

public:
	enum eSeaFood { SHRIMP, CRAB, FISH, CALAMARI };
	
    
	Penguin(const string&name, float weight, int birthYear, eSeaFood favoriteFood);
    
    Penguin(const Penguin& penguin) = delete;
    const Penguin& operator=(const Penguin& penguin) = delete;
    
	bool setFavoriteFood(Penguin::eSeaFood favoriteFood);

	inline eSeaFood getFavoriteFood() const;
    
	virtual void toOs(ostream& os) const override;
  
private:
	eSeaFood favoriteFood;

};


#endif /* __PENGUIN_H */
