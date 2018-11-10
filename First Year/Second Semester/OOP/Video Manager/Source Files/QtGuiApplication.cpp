#include "QtGuiApplication.h"
#include <vector>
#include "Video.h"
#include "Utils.h"
#include "Exceptions.h"
#include <QMessageBox>

QtGuiApplication1::QtGuiApplication1(Controller &c, QWidget *parent)
	: ctrl{ c }, QWidget(parent)
{
	this->initGUI();
	this->currentVideosInRepo = this->ctrl.getRepo().getVideos();
	this->populateRepoList();
	//this->connect();
}

void QtGuiApplication1::initGUI() {
	QHBoxLayout *layout = new QHBoxLayout{ this };
	//QLabel *x = new QLabel{ "" };
	//layout->addWidget(x);


	QWidget *leftWidget = new QWidget{};
	QVBoxLayout *leftSide = new QVBoxLayout{ leftWidget };

	comboBox = new QComboBox{ this };
	comboBox->addItem("Detailed");
	comboBox->addItem("Short");
	comboBox->setGeometry(QRect(220,0,150,30));

	

	this->repoList = new QListWidget{};
	this->repoList->setSelectionMode(QAbstractItemView::SingleSelection);

	QWidget *VideoDataWidget = new QWidget{};
	QFormLayout *formLayout = new QFormLayout{ VideoDataWidget };
	this->titleEdit = new QLineEdit{};
	this->presenterEdit = new QLineEdit{};
	this->likesEdit = new QLineEdit{};
	this->durationEdit = new QLineEdit{};
	this->trailerEdit = new QLineEdit{};
	formLayout->addRow("&Title:", titleEdit);
	formLayout->addRow("&Presenter:", presenterEdit);
	formLayout->addRow("&Likes:", likesEdit);
	formLayout->addRow("&Duration:", durationEdit);
	formLayout->addRow("&Trailer:", trailerEdit);

	QWidget *buttonsWidget = new QWidget{};
	QGridLayout *gridLayout = new QGridLayout{ buttonsWidget };
	this->addButton = new QPushButton("Add");
	this->deleteButton = new QPushButton("Delete");
	
	this->watchlistIndex = 0;

	gridLayout->addWidget(addButton, 0, 0);
	gridLayout->addWidget(deleteButton, 0, 1);

	leftSide->addWidget(new QLabel{ "All Videos" });
	leftSide->addWidget(repoList);
	leftSide->addWidget(VideoDataWidget);
	leftSide->addWidget(buttonsWidget);
	

	QWidget* middleWidget = new QWidget{};
	QVBoxLayout* vLayoutMiddle = new QVBoxLayout{ middleWidget };
	this->moveOneVideoButton = new QPushButton{ ">> Move one Video" };
	this->moveAllVideosButton = new QPushButton{ ">> Move all Videos" };
	this->htmlButton = new QPushButton{ " HTML Playlist " };
	QWidget* upperPart = new QWidget{};
	QWidget* lowerPart = new QWidget{};
	QVBoxLayout* vLayoutUpperPart = new QVBoxLayout{ upperPart };
	vLayoutUpperPart->addWidget(this->moveOneVideoButton);
	vLayoutUpperPart->addWidget(this->moveAllVideosButton);
	vLayoutUpperPart->addWidget(this->htmlButton);
	
	vLayoutMiddle->addWidget(upperPart);
	vLayoutMiddle->addWidget(lowerPart);

	QWidget *rightWidget = new QWidget{};
	QVBoxLayout *rightSide = new QVBoxLayout{ rightWidget };

	watchList = new QListWidget{};

	QWidget *watchlistButtonWidget = new QWidget{};
	QHBoxLayout *watchlistButtonLayout = new QHBoxLayout{ watchlistButtonWidget };
	this->playButton = new QPushButton{ "&Play" };
	this->nextButton = new QPushButton{ "&Next" };
	watchlistButtonLayout->addWidget(this->playButton);
	watchlistButtonLayout->addWidget(this->nextButton);

	rightSide->addWidget(new QLabel{ "Playlist" });
	rightSide->addWidget(watchList);
	rightSide->addWidget(watchlistButtonWidget);

	layout->addWidget(leftWidget);
	layout->addWidget(middleWidget);
	layout->addWidget(rightWidget);

	this->connect();
}

void QtGuiApplication1::openHtml()
{
	this->ctrl.seeWatchlistController();
}

void QtGuiApplication1::connect() {
	QObject::connect(this->repoList, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));

	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addNewVideo()));
	QObject::connect(this->playButton, SIGNAL(clicked()), this, SLOT(playVideo()));
	QObject::connect(this->deleteButton, SIGNAL(clicked()), this, SLOT(deleteVideo()));
	QObject::connect(this->nextButton, SIGNAL(clicked()), this, SLOT(nextVideo()));

	QObject::connect(this->htmlButton, SIGNAL(clicked()), this, SLOT(openHtml()));
	QObject::connect(this->moveOneVideoButton, SIGNAL(clicked()), this, SLOT(moveVideoToWatchlist()));
	QObject::connect(this->moveAllVideosButton, SIGNAL(clicked()), this, SLOT(moveAllVideos()));
	QObject::connect(this->comboBox, SIGNAL(currentTextChanged(const QString&)), this, SLOT(eventTextChanged(const QString&)));
}


void QtGuiApplication1::eventTextChanged(const QString& text)
{
	if (text == "Short")
		this->populateRepoListShort();
	else
		this->populateRepoList();
}



void QtGuiApplication1::populateRepoList() {
	if (this->repoList->count() > 0)
		this->repoList->clear();
	for (auto m : this->currentVideosInRepo) {
		QString itemInList = QString::fromStdString((m.getTitle()+" - "+m.getPresenter()+",  "+ std::to_string(m.getDuration()/60)+" minutes and " + 
			" " +std::to_string(m.getDuration() / 60) + "seconds, " +std::to_string(m.getLikes())+" likes, Link: "+m.getTrailer()));
		QListWidgetItem *item3 = new QListWidgetItem(itemInList);	
		this->repoList->addItem(item3);
	}

	if (this->currentVideosInRepo.size() > 0)
		this->repoList->setCurrentRow(0);
}

void QtGuiApplication1::populateRepoListShort() {
	if (this->repoList->count() > 0)
		this->repoList->clear();
	for (auto m : this->currentVideosInRepo) {
		QString itemInList = QString::fromStdString((m.getTitle()));
		QListWidgetItem *item3 = new QListWidgetItem(itemInList);
		this->repoList->addItem(item3);
	}

	if (this->currentVideosInRepo.size() > 0)
		this->repoList->setCurrentRow(0);
}

void QtGuiApplication1::populateWatchlist() {
	if (this->watchList->count() > 0)
		this->watchList->clear();

	for (auto m : this->ctrl.getVideosFromWatchlist()) {
		QString itemInList = QString::fromStdString((m.getTitle() + " " + m.getPresenter() + " " + std::to_string(m.getDuration()) + " " + std::to_string(m.getLikes()) + " " + m.getTrailer()));
		this->watchList->addItem(itemInList);
	}
}

void QtGuiApplication1::populateWatchlistShort() {
	if (this->watchList->count() > 0)
		this->watchList->clear();

	for (auto m : this->ctrl.getVideosFromWatchlist()) {
		QString itemInList = QString::fromStdString((m.getTitle()));
		this->watchList->addItem(itemInList);
	}
}

int QtGuiApplication1::getRepoListSelectedIndex() {
	if (this->repoList->count() == 0)
		return -1;
	QModelIndexList index = this->repoList->selectionModel()->selectedIndexes();
	if (index.size() == 0) {
		this->titleEdit->clear();
		this->presenterEdit->clear();
		this->durationEdit->clear();
		this->likesEdit->clear();
		this->trailerEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void QtGuiApplication1::listItemChanged() {
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1)
		return;

	vector<Video> videos = this->currentVideosInRepo;

	if (idx >= videos.size())
		return;
	Video m = videos[idx];

	this->titleEdit->setText(QString::fromStdString(m.getTitle()));
	this->presenterEdit->setText(QString::fromStdString(m.getPresenter()));
	this->likesEdit->setText(QString::fromStdString(to_string(m.getLikes())));
	this->durationEdit->setText(QString::fromStdString(to_string(m.getDuration())));
	this->trailerEdit->setText(QString::fromStdString(m.getTrailer()));

}


void QtGuiApplication1::playVideo()
{
		Video v =this->ctrl.getWatchlistPosition(this->watchlistIndex);
	    v.play();
}

void QtGuiApplication1::nextVideo()
{
	this->watchlistIndex += 1;
	if (this->watchlistIndex >= this->watchList->count())
		this->watchlistIndex %= this->watchList->count();
	this->watchList->setCurrentRow(this->watchlistIndex);
}

void QtGuiApplication1::addNewVideo() {
	string title = this->titleEdit->text().toStdString();
	string presenter = this->presenterEdit->text().toStdString();
	string likes = this->likesEdit->text().toStdString();
	string trailer = this->trailerEdit->text().toStdString();
	string duration = this->durationEdit->text().toStdString();

	try {
		this->ctrl.addVideoToRepo(title, presenter, stoi(duration), stoi(likes), trailer);
		this->currentVideosInRepo = this->ctrl.getRepo().getVideos();
		this->populateRepoList();
	}
	catch (RepoException &e) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getMessage()));
	}

}

void QtGuiApplication1::deleteVideo() {
	string title = this->titleEdit->text().toStdString();
	try {
		this->ctrl.deleteVideoFromRepo(title);
		this->currentVideosInRepo = this->ctrl.getRepo().getVideos();
		this->populateRepoList();
	}
	catch (RepoException &e) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getMessage()));
	}
}

void QtGuiApplication1::moveVideoToWatchlist() {
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1 || idx >= this->currentVideosInRepo.size())
		return;
	const Video &m = this->currentVideosInRepo[idx];
	this->ctrl.addVideoToPlaylist(m);
	this->populateWatchlist();
}

void QtGuiApplication1::moveAllVideos() {
	for (auto m : this->currentVideosInRepo) {
		this->ctrl.addVideoToPlaylist(m);
	}
	this->populateWatchlist();
}