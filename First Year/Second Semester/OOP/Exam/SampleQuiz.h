#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_SampleQuiz.h"
#include "Controller.h"

class SampleQuiz : public QMainWindow
{
	Q_OBJECT

public:
	SampleQuiz(Player p_p, Controller& c_p, QWidget *parent = Q_NULLPTR);
//	void popList(std::vector<Question> q);


public slots:
	void update();
	void answer();
	void popList(std::vector<Question> q);

private:
	Ui::SampleQuizClass ui;
	Controller c;
	Player p; 
};
