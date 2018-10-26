#include "bag.h"
//Since most of the work is done at the implementation of the hash table, those functions are pretty straight forward

HashTable* Bag::getContainerPointer()
{
	return &hash_table;
}

HashTable Bag::getContainer()
{
	return this->hash_table;
}

int Bag::countElements()
{
	return this->hash_table.countElements();
}

int Bag::size()
{
	return this->hash_table.getSize();
}


int Bag::add(std::string elem)
{
	return this->hash_table.add(elem);
}

int Bag::remove(std::string elem)
{
	return this->hash_table.remove(elem);
}

int Bag::search(std::string elem)
{
	return this->hash_table.search(elem);
}

void Bag::run()
{
	int command;
	while (1)
	{
		std::cout<<"\tEnter command: ";
		std::cin>>command;
		std::string elem;
		int result=0;
		switch(command)
		{	
			case 0: return;
			case 1:	std::cout<<"\tEnter the element you wish to search for: ";
				std::cin>>elem;
				result = this->search(elem);
				if (result)
					std::cout<<"\tThe element is in the bag!\n";
				else
					std::cout<<"\tThe element is not in the bag!\n";
				break;
			
			case 2:	std::cout<<"\tEnter the element you wish to add: \n";
				std::cin>>elem;
				result = this->add(elem);
				if (result)
					std::cout<<"\tElement was succesfully added!\n";
				else
					std::cout<<"\tError, the bag is full! Element was not added!\n";
				break;
			case 3:	std::cout<<"\tEnter the element you wish to delete: \n";
				std::cin>>elem;
				result = this->remove(elem);
				if (result)
					std::cout << "\tElement was succesfully deleted!\n";
				else
					std::cout << "\tError! The element is not present in the bag!\n";
				break;
			case 4:	std::cout<<"\tNumber of ellements is: "<<this->size()<<"\n";
				break;
			case 5:	this->print();
				break;
		}
	}
}

void Bag::print()
{
	this->hash_table.print();
}
