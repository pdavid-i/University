#include "solver.h"

void printMenu()
{	
	std::cout<<"0. Exit\n";
	std::cout<<"1. Add element\n";
	std::cout<<"2. Delete element\n";
	std::cout<<"3. See hash table\n";
	std::cout<<"4. Search item\n";

}

void run()
{
	int command;
	HashTable a{};
	while(1)
	{
		printMenu();
		std::cout<<"Enter command: ";
		std::cin>>command;
		std::string str_elem;
		switch(command)
		{
		case 1: std::cout<<"Enter element to be added: ";
			std::cin>>str_elem;
			a.add(str_elem);
			break;
		case 2: std::cout<<"Enter element to be removed: ";
			std::cin>>str_elem;
			a.remove(str_elem);
			break;
		case 3: a.print();
			break;
		case 4:	std::cout<<"Enter element to be searched: ";
			std::cin>>str_elem;
			std::cout<<a.search(str_elem)<<"\n";
			break;
		case 0:
			return;
		}
	}
}


int main()
{
	Solver s;
	Tester tester;
	tester.run();
	s.solve();
	return 0;
}
