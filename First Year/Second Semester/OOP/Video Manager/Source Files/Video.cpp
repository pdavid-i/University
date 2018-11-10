#pragma once
#include "Video.h"
#include "Utils.h"
#include <string>
#include <Windows.h>
#include <iostream>
#include <shellapi.h>

using namespace std;

Video::Video() : title(""), presenter(""), duration(), likes(), trailer("") {}

Video::Video(const string &title, const string &presenter, const int duration, const int likes, const string &trailer) {
	this->title = title;
	this->presenter = presenter;
	this->duration = duration;
	this->likes = likes;
	this->trailer = trailer;
}

std::ostream& operator<<(std::ostream& stream, const Video& vid) {
	stream << vid.getTitle() << " - " << vid.getPresenter() << ", " << (vid.getDuration()/60) << "minutes, " 
		<< (vid.getDuration()%60) << "seconds" << ", " << vid.getLikes() << "likes, Link: " << vid.getTrailer() <<"\n";
	return stream;
}

istream & operator>>(istream &is,  Video &m) {
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 5)
		return is;

	m.title = tokens[0];
	m.presenter = tokens[1];
	m.likes = stoi(tokens[3]);
	m.trailer = tokens[4];
	m.duration = stoi(tokens[2]);

	return is;

}



void Video::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}