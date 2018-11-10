#pragma once

#include <QWidget>
#include "ui_Presenter.h"
#include "Controller.h"


class Presenter : public QWidget
{
	Q_OBJECT

public:
	Presenter(Controller& c_p, QWidget *parent = Q_NULLPTR);
	~Presenter();
	void popList(std::vector<Question> q);

public slots:
	void add();


private:
	Ui::Presenter ui;
	Controller c;
};
