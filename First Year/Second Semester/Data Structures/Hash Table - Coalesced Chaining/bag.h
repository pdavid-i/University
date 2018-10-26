#pragma once
#include "hash.h"

class Bag{
private:
	HashTable hash_table;
	HashTable* getContainerPointer();

public:
	Bag(){};
	~Bag(){};
	HashTable getContainer();
	int add(std::string elem);
	int remove(std::string elem);
	int search(std::string elem);
	void print();
	int countElements();
	void run();
	int size();
//	HashTable* getContainerPointer();
};
