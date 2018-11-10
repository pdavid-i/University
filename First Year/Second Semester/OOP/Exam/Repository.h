#pragma once
#include "Domain.h"
#include <vector>

class Repo {
private:
	std::vector <Question> questions;
	std::vector <Player> players;

public:
	Repo();
	int addQuestion(int id_p, std::string text_p, std::string answ_p, int score_p);
	std::vector <Question> getQuestions() { return this->questions; };
	std::vector <Player> getPlayers() { return this->players; };
	int countPlayers() { return this->players.size(); };
	int countQuestions() { return this->questions.size(); };
};