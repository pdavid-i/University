#include "solver.h"
#include <fstream>

int Solver::loop_through(std::string filename)
{
	std::ifstream f(filename);	
	std::string present;
	int result = 1;
	while(present!="end")
	{	
		f>>present;
		if (present!="end")
			result = this->interpret(present);
		if (result!=1)
			return 0;
	}	
	return 1;
}

int Solver::interpret(std::string present)
{
	int result;
	if (present[0] == '+')
		result = this->santa_bag.add(present.substr(1));
	else
		result = this->santa_bag.remove(present.substr(1));
	return result;
}

void Solver::solve()
{
	int result = this->loop_through("santas_plan.txt");
	if (result)
		std::cout<<"Santa is able to complete his journey! Hooray!\n";
	else
		std::cout<<"Santa needs to look over his plan and make a few tweaks! Good luck, Santa!\n";
}
