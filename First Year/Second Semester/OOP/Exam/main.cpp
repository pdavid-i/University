#include "SampleQuiz.h"
#include "Presenter.h"
#include "Tester.h"
#include <QtWidgets/QApplication>
#include "Controller.h"

int main(int argc, char *argv[])
{
//	Tester t;
//	t.test_all();
	QApplication a(argc, argv);
	Repo r;
	Controller c{ r };
	std::vector <SampleQuiz*> windows;
	Presenter* p = new Presenter{ c };
	p->popList(r.getQuestions());
	p->show();
	for (auto x : r.getPlayers()) {
		SampleQuiz* win = new SampleQuiz(x, c);
		win->popList(r.getQuestions());
		windows.push_back(win);
		win->show();
	}
	return a.exec();
}
