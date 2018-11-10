#include "Presenter.h"

Presenter::Presenter(Controller& c_p, QWidget *parent)
	: QWidget(parent), c{c_p}
{
	ui.setupUi(this);
	QObject::connect(ui.add_button, SIGNAL(clicked()), this, SLOT(add()));
}

Presenter::~Presenter()
{

}

void Presenter::popList(std::vector<Question> q)
{
	int i, j;
	Question aux;
	for (i = 0; i < q.size() - 1; i++)
		for (j = i + 1; j < q.size(); j++)
			if (q[i].getId() > q[j].getId()) {
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

void Presenter::add()
{
		int id = std::stoi(ui.id_entry->text().toStdString());
		std::string text = ui.text_entry->text().toStdString();
		std::string answer = ui.answer_entry->text().toStdString();
		int points = std::stoi(ui.points_entry->text().toStdString());
		this->c.addQuest(id, text, answer, points);
		this->popList(this->c.getQuestions());
}