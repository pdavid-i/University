#pragma once
#include "Controller.h"

class UI {
private:
	Controller ctrl;
public:
	UI(const Controller &c) : ctrl(c) {}
	void run();
	void runUser();
private:
	static void printMenu();
	static void printUserMenu();
	//
	void showAllVideosPlaylist();
	void showVideosWithPresenter();
	void deleteVideoFromPlaylist();
	//
	void doUndo();
	int addVideoToRepo();
	int deleteVideoFromRepo();
	void showAllVideosRepo();
	int updateVideoFromRepo();
	bool isValid(const string &title, const string &presenter, const string &duration, const string &likes, const string &trailer);
};
