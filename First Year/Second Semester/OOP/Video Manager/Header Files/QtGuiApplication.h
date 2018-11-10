#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <qcombobox.h>
#include "Controller.h"


using namespace std;

class QtGuiApplication1 : public QWidget
{
	Q_OBJECT

public:
	QtGuiApplication1(Controller &c, QWidget *parent = Q_NULLPTR);
	int watchlistIndex;

private:
	Controller & ctrl;
	vector<Video> currentVideosInRepo;

	QComboBox *comboBox;
	QListWidget *repoList;
	QLineEdit *titleEdit;
	QLineEdit *presenterEdit;
	QLineEdit *durationEdit;
	QLineEdit *likesEdit;
	QLineEdit *trailerEdit;
	QPushButton *playButton;
	QPushButton *nextButton;
	QPushButton *addButton;
	QPushButton *deleteButton;
	QPushButton *moveOneVideoButton;
	QPushButton *htmlButton;
	QPushButton *moveAllVideosButton;
	QListWidget *watchList;

	void populateRepoListShort();
	void populateWatchlistShort();
	void initGUI();
	void populateRepoList();
	void populateWatchlist();
	int getRepoListSelectedIndex();
	void connect();
	void listItemChanged();

	public slots:
	void openHtml();
	void nextVideo();
	void addNewVideo();
	void deleteVideo();
	void playVideo();
	void moveVideoToWatchlist();
	void moveAllVideos();
	void eventTextChanged(const QString&);
};
