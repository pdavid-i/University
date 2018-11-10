#pragma once
#include <string>
#include <iostream>

class Question {
private:
	int id;
	std::string text;
	std::string answer;
	int score;


public:
	Question() {};
	Question(int id_p, std::string text_p, std::string answer_p, int score_p) : id{ id_p }, text{ text_p }, answer{ answer_p }, score{score_p} {}
	int getId() { return this->id; };
	std::string getText() { return this->text; };
	std::string getAnswer() { return this->answer; };
	int getScore() { return this->score; };
	std::string toString() { return std::to_string(id) + " " + text + " " + answer + " " + std::to_string(score); };
	friend std::istream& operator>>(std::istream& is, Question& q);
};

class Player {
private:
	std::string name;
	int score;

public:
	Player() {};
	Player(std::string name_p, int score_p) : name{ name_p }, score{score_p} {}
	std::string getName() { return this->name; };
	int getScore() { return this->score; };
	void answer(std::string answer, std::string correct, int points)
	{
		if (answer == correct)
			this->score += points;
	};
	friend std::istream& operator>>(std::istream& is, Player& p);
};

