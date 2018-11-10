#pragma once
#include "Domain.h"
#include "Repository.h"
#include <assert.h>

class Tester {
public:
	void test_domain();
	void test_repo();
	void test_all() {
		test_domain();
		test_repo();
	}
};

void Tester::test_domain()
{
	Player p{ "dave", 0 };
	assert(p.getName() == "dave");
	assert(p.getScore() == 0);
	p.answer("cuc", "cuc", 3);
	p.answer("bei", "be1", 5);
	assert(p.getScore() == 3);

	Question q{ 1, "what is", "wow", 10 };
	assert(q.getId() == 1);
	assert(q.getText() == "what is");
	assert(q.getAnswer() == "wow");
	assert(q.getScore() == 10);
	assert(q.toString() == "1 what is wow 10");
}

void Tester::test_repo()
{
	Repo r;
	assert(r.countQuestions() == 5);
	assert(r.countPlayers() == 3);
	r.addQuestion(6, "i need", "help", 56);
	assert(r.countQuestions() == 6);
}