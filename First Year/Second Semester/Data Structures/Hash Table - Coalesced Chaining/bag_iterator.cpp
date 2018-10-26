#include "bag_iterator.h"


//Constructor for the class
BagIterator::BagIterator()
{
	this->current_position = this->container.getContainer().getNextIndex(this->current_position);
}

//Constructor for the class with existing bag
BagIterator::BagIterator(Bag *bag)
{
	this->container = *bag;
	this->current_position = this->container.getContainer().getNextIndex(0);
}
//Returns the current element
std::string BagIterator::getCurrent()
{
	return this->container.getContainer().getAtIndex(this->current_position);
}

//Checks if the current element is a valid one
//	     
// Returns: True - if its is valid
//          False - otherwise
bool BagIterator::isValid()
{
	return (this->current_position >=0 && this->current_position <= this->container.size() && this->getCurrent() != "empty");
}

//Current element is set to the next one
void BagIterator::next()
{
	this->current_position = this->container.getContainer().getNextIndex(this->current_position);
}

