#pragma once
#include <string>
#include "DynamicVector.h"
using namespace std;


class Watchlist : public DynamicVector<Video>
{
private:
	vector<Video> videos;
protected:
	string filename;

public:
	Watchlist(string file) : filename(file) {};
	virtual ~Watchlist() { }
	vector<Video> getVideos(){ return this->getAsVector();}
	Video getVideo(int pos) { return this->getAsVector()[pos]; }
	virtual void writeToFile() = 0;
	virtual void displayWatchlist() = 0;
};