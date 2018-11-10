#include "Repository.h"
#include <fstream>


int Repo::addQuestion(int id_p, std::string text_p, std::string answ_p, int score_p)
{
	Question q{ id_p, text_p, answ_p, score_p };
	this->questions.push_back(q);
	return 0;
}

Repo::Repo()
{
	std::ifstream g("Players.txt");
	Player p;
	while (g >> p) {
		this->players.push_back(p);
	}
	std::ifstream f("Questions.txt");
	Question  q;
	while (f >> q) {
		this->questions.push_back(q);
	}

	int i, j;
	Question qst;
	for (i = 0; i < this->questions.size() - 1; i++)
		for (j = i + 1; j < this->questions.size(); j++)
			if (this->questions[i].getId() > this->questions[j].getId()) {
				qst = this->questions[i];
				this->questions[i] = this->questions[j];
				this->questions[j] = qst;
			}
}