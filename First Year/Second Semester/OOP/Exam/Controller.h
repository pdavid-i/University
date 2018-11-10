#pragma once
#include "Repository.h"

class Controller {
private:
	Repo& r;
public:
	Controller(Repo& r) : r{ r } {}
	~Controller() { }
	std::vector <Question> getQuestions() { return this->r.getQuestions(); };
	std::vector <Player> getPlayers() { return this->r.getPlayers(); };
	void addQuest(int id_p, std::string text_p, std::string answ_p, int score_p);

};