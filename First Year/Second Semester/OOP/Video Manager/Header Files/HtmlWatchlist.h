#pragma once
#include "Watchlist.h"
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

class HtmlWatchlist : public Watchlist
{
public:
	HtmlWatchlist(string filename) : Watchlist{ filename } {}

	void writeToFile() override {
		ofstream g(this->filename);

		g << "<!DOCTYPE html>\n<html>\n<head>\n<title>Playlist</title>\n</head>\n<body>\n<table border = \"1\">\n";

		g << "<tr>\n";
		g << "<td>Title</td>\n";
		g << "<td>Presenter</td>\n";
		g << "<td>Duration</td>\n";
		g << "<td>Likes</td>\n";
		g << "<td>Link</td>\n";
		g << "</tr>\n";
		for (int i = 0; i < this->getSize(); i++) {
			Video video = this->getOnPos(i);
			{
				g << "<tr>\n";
				g << "<td>" << video.getTitle() << "</td>\n";
				g << "<td>" << video.getPresenter() << "</td>\n";
				g << "<td>" << video.getDuration() << "</td>\n";
				g << "<td>" << video.getLikes() << "</td>\n";
				g << "<td><a href='" << video.getTrailer() << "'>link</a></td>";
				g << "</tr>\n";
			}
		}
		g << "</table>\n</body>\n</html>";
	};

	void displayWatchlist() override {
		string aux = "file:///C:/Users/David/source/repos/QtGuiApplication/QtGuiApplication/" + this->filename + "\"";
		ShellExecuteA(NULL, NULL, "chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	};
};