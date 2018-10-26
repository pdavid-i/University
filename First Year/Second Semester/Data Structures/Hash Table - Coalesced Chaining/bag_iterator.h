#include "bag.h"

class BagIterator
{
private:
	Bag container;
	int current_position;

public:
	BagIterator();
	BagIterator(Bag* bag);
	~BagIterator(){};
	std::string getCurrent();
	bool isValid();
	void next();
};
