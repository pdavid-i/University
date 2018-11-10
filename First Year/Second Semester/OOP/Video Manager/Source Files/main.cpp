#include "QtGuiApplication.h"
#include <QtWidgets/QApplication>

// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"

#include "CsvWatchlist.h"
#include "HtmlWatchlist.h"
#include "Video.h"
#include "UI.h"
#include "Tests.h"
#include "Validator.h"
#include <string>
#include <vector>



void init(Repository &repo)
{
	Video m1{ "Ayahuasca", "Vancouver Sleep Clinic", 508, 3000, "https://www.youtube.com/watch?v=db97HUw3ToA&list=LLsDMCMqW-TYazmSoC7VFKcA&index=7" };
	Video m2{ "Silent Movies", "Aquilo", 203, 3200, "https://www.youtube.com/watch?v=3eaKSRJfTT8&list=LLsDMCMqW-TYazmSoC7VFKcA&index=8" };
	Video m3{ "Mystery of Love", "Sufjan Stevens", 250, 38000, "https://www.youtube.com/watch?v=4WTt69YO2VI&list=LLsDMCMqW-TYazmSoC7VFKcA&index=6&t=0s" };
	Video m4{ "Your mess is mine", "Vance Joy", 234, 120000, "https://www.youtube.com/watch?v=1C816p-KTNk" };
	Video m5{ "Riptide" , "Vance Joy", 204, 1100000, "https://www.youtube.com/watch?v=uJ_1HMAGb4k" };
	Video m6{ "All I've ever known", "Bahamas", 370, 13000, "https://www.youtube.com/watch?v=gPjqWwkAymg" };
	repo.addVideo(m1);
	repo.addVideo(m2);
	repo.addVideo(m3);
	repo.addVideo(m4);
	repo.addVideo(m5);
	repo.addVideo(m6);

}

string getFileType()
{
	string cmd = "";
	while (cmd != "1" && cmd != "2")
	{
		cout << "1. CSV\n";
		cout << "2. HTML\n";
		cout << ">>";

		cin >> cmd;
	}
	return cmd;
}

int user(Repository &repo) {
	Watchlist* file = NULL;
	string cmd = getFileType();
	if (cmd == "1")
	{
		file = new CsvWatchlist{ "Watchlist.csv" };
	}
	else
	{
		file = new HtmlWatchlist{ "Watchlist.html" };
	}
	Controller ctrl{ repo , file };
	UI ui{ ctrl };
	ui.runUser();
	return (0);
}

int admin(Repository repo) {

	Controller ctrl{ repo };
	UI ui{ ctrl };
	ui.run();

	return 0;
}

int main_consolle()
{

	Repository aux{ "repo.txt" };
	Repository* repo = &aux;
	//	init(*repo);
	//	Test t{};
	//	t.testAll();
	string str;
	cout << "Enter mode: (user/admin)";
	cin >> str;
	if (str == "admin")
		admin(*repo);
	if (str == "user")
	{
		user(*repo);
	}
	else
		cout << "Invalid choice!";
	return (0);

}

int main_gui(int argc, char *argv[])
{
	Watchlist *file = NULL;
	QApplication a(argc, argv);
	Repository repo{ "repo.txt" };
	file = new HtmlWatchlist{ "Watchlist.html" };
	Controller ctrl{ repo, file};
	QtGuiApplication1 w{ ctrl };
	w.showMaximized();
	return a.exec();
}

int main(int argc, char *argv[])
{
	main_gui(argc, argv);
	
	return (0);
}
