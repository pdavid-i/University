#include "hash.h"

HashTable::HashTable()
{
	//initialize the memory as empty
	for (int i = 0; i < size; i++)
	{
		this->table[i].name = "empty";
		this->table[i].next = -1;
	}
}

int HashTable::getSize()
{
	//a function that returns the capacity of the hash table
	return this->size;
}

int HashTable::countElements()
{
	//a function that returns the number of non-empty elements in the hash table
	int size_of_hash = 0;
	for (int i = 0; i < size; i++)
	{
		if (this->table[i].name != "empty")
			size_of_hash++;
	}
	return size_of_hash;
}

std::string HashTable::getAtIndex(int index)
{
	//function that returns the element at an index given as parameter, or an Error message if the index is outside the range
	if (index>=0 && index<this->size)
		return this->table[index].name;
	std::cout<<"Error!\n";
	return "Index Error!";
}

int HashTable::getNextAtIndex(int index)
{
	//function that returns the next field of an element given as parameter
	if (index>=0 && index<this->size)
		return this->table[index].next;
	std::cout<<"Error!";
	return -1;
}

int HashTable::add(std::string element)
{
	//function that adds an element with the value given as parameter to the bag
	//
	// Complexity: Best: O(1)
	//	       Worst: O(n)  (if all the elements are hashed to the same spot)
	//	       Average O(1)
	//
	int element_index = this->hash(element);
	if (this->table[element_index].name == "empty")
	{
		table[element_index].name = element;
		
	}
	else
	{
		while (table[element_index].next != -1)
		{
			element_index = table[element_index].next;
		}

		int previous_element_index = element_index;
		element_index = this->next_free(element_index);

		if (element_index == -1)
				return 0;

		table[previous_element_index].next = element_index;
		table[element_index].name = element;
	}
	return 1;
}

void HashTable::free(int index)
{
//description: Frees the element at a given index
	table[index].next=-1;
	table[index].name="empty";
}

int HashTable::search(std::string element)
{
        //function that searches for an element with the value given as parameter in the bag, and returns 1 if it is 
        //
        // Complexity: Best: O(1)
        //             Worst: O(n)  (if all the elements are hashed to the same spot)
        //             Average O(1)
        //

	int found = 0;
	int element_index = this->hash(element);
	while(table[element_index].name != element)
	{
		if (table[element_index].next == -1)
			return 0;
		element_index = table[element_index].next;
	}
	return 1;
}

int HashTable::remove(std::string element)
{
	        //function that searches for an element with the value given as parameter in the bag, and returns 1 if it is the element was removed, 0 otherwise 
        //
        // Complexity: Best: O(1)
        //             Worst: O(n)  (if all the elements were hashed to the same)
        //             Average O(1)
        //

	if (!this->search(element))
			return 0;
	
	int element_index = this->hash(element);
	if (table[element_index].name == element)
	{
		if(table[element_index].next == -1)
		{
			this->free(element_index);
		}
		else
		{
			int next_index = table[element_index].next;
			std::string aux_element = table[next_index].name;
			int aux_next = table[next_index].next;
			this->free(next_index);
			table[element_index].name = aux_element;
			table[element_index].next = aux_next;
		}
	}
	else
	{
		int prev_index = -1;
		while (this->table[element_index].name!=element)
		{
			prev_index = element_index;
			element_index = table[element_index].next;
		}
		table[prev_index].next = -1;
		this->free(element_index);
	}
	return 1;
}





int HashTable::next_free(int index_param)
{
	// a function that returns the index of the next free element from the bag
	int free_index = 0;
	for (int i = index_param; i<size; i++)
		if (this->table[i].name == "empty")
                        return i;

	
	for (int i = 0; i < index_param; i++)
		if (this->table[i].name == "empty")
			return i;
	return -1;
}

void HashTable::print()
{
	int is_empty = 1;
	for (int i = 0; i < size; i++)
		if (this->table[i].name != "empty")
		{
			std::cout<<"-------------\n"<<"Index "<<i<<" "<<table[i].name<<" next: "<<table[i].next<<"\n"<<"-------------\n\n";
			is_empty=0;
		}
	if (is_empty)
		std::cout<<" The bag is empty!\n";
}

int HashTable::getNextIndex(int start_pos)
{
	if (start_pos<=size)
	{
		for (int i = start_pos-1; i > 0; i--)
		   if (this->table[i].name != "empty")
                        return i;
	}
	return -1;
}

int HashTable::hash(std::string key)
{
	int index = 0;
	for(int i = 0; i<key.length();i++)
		index+=(int)key[i];

	return index%(this->size);
}
