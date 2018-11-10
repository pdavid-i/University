#include "SampleQuiz.h"
#include <string>
#include <assert.h>
#include <qlistwidget.h>

SampleQuiz::SampleQuiz(Player p_p, Controller& c_p, QWidget *parent)
	: QMainWindow(parent), c{ c_p }, p{ p_p }
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(p.getName()));
	QObject::connect(ui.answerButton, SIGNAL(clicked()), this, SLOT(answer()));
	QObject::connect(ui.updateButton, SIGNAL(clicked()), this, SLOT(update()));
}

void SampleQuiz::popList(std::vector<Question> q)
{
	int i, j;
	Question aux;
	for (i = 0; i < q.size() - 1; i++)
		for (j = i + 1; j < q.size(); j++)
			if (q[i].getScore() > q[j].getScore()) {
				aux = q[i];
				q[i] = q[j];
				q[j] = aux;
			}
	
	ui.listWidget->clear();
	for (auto t : q) {
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(t.toString()));
		ui.listWidget->addItem(item);
	}
}

void SampleQuiz::update()
{
	std::vector<Question> q = this->c.getQuestions();
	int i, j;
	Question aux;
	for (i = 0; i < q.size() - 1; i++)
		for (j = i + 1; j < q.size(); j++)
			if (q[i].getScore() > q[j].getScore()) {
				aux = q[i];
				q[i] = q[j];
				q[j] = aux;
			}

	ui.listWidget->clear();
	for (auto t : q) {
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(t.toString()));
		ui.listWidget->addItem(item);
	}
}

void SampleQuiz::answer()
{
	int index = ui.listWidget->currentRow();
	std::string answ = ui.answer_entry->text().toStdString();
	Question q = this->c.getQuestions()[index];
	this->p.answer(answ, q.getAnswer(), q.getScore());
	ui.label->setText(QString::fromStdString(std::to_string(this->p.getScore())));
}