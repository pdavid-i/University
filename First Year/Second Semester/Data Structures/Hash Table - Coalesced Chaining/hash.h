#include <iostream>
#include <string>

#ifndef HASH_H
#define HASH_H

class HashTable{
private:
	static const int size=100;

	struct element
	{
		std::string name;
		int next;
	};

	element table[size];

public:
	HashTable();
	~HashTable(){};
	void free(int index);
	std::string getAtIndex(int index);
	int getNextAtIndex(int index);
	int countElements();
	int search(std:: string element);
	int remove(std::string element);
	int add(std::string element);
	int next_free(int index_param);
	int hash(std::string key);
	int getSize();
	void print();
	int getNextIndex(int start_pos);
};


#endif
