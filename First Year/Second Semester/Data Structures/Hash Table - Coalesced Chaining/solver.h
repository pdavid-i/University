#pragma once
#include "tester.h"

class Solver
{
	private:
		Bag santa_bag;
	public:
		Solver(){};
		int interpret(std::string present);
		int loop_through(std::string filename);
		void solve();
};
