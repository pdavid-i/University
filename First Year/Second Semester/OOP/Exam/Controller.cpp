#include "Controller.h"

void Controller::addQuest(int id_p, std::string text_p, std::string answ_p, int score_p)
{
	this->r.addQuestion(id_p, text_p, answ_p, score_p);
}