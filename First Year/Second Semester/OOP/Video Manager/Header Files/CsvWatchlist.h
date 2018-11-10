#pragma once
#include <string>
#include "Watchlist.h"
#include <fstream>
#include <Windows.h>
using namespace std;

class CsvWatchlist : public Watchlist
{
public:
	CsvWatchlist(string filename) : Watchlist{ filename } {}

	void writeToFile() override {
		ofstream g(this->filename);
		g << this->getSize();
			for (int i = 0; i < this->getSize(); i++) {
				Video vid = this->getOnPos(i);
				g << vid << '\n';
			}
	};

	void displayWatchlist() override {
		string aux = "\"" + this->filename + "\"";
		ShellExecuteA(NULL, NULL, "notepad.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	};
};
