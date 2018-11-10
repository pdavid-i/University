#include "UI.h"
#include <string>
#include <stdio.h>


using namespace std;

void UI::printMenu() {
	cout << "1- Add a video\n";
	cout << "2- Display all\n";
	cout << "3- Delete a video\n";
	cout << "4- Update a video\n";
	cout << "0- Exit\n";
}

int UI::addVideoToRepo() {
	cout << "Enter the title: ";
	string title;
	getline(cin, title);
	cout << "Enter the presenter: ";
	string presenter;
	getline(cin, presenter);
	cout << "Enter the trailer link: ";
	string trailer;
	getline(cin, trailer);
	cout << "Enter the duration (in seconds): ";
	int duration;
	cin >> duration;
	cout << "Enter the likes: ";
	int likes;
	cin >> likes;

	return this->ctrl.addVideoToRepo(title, presenter, duration, likes, trailer);
}

int UI::deleteVideoFromRepo() {
	cout << "Enter the title: ";
	string title;
	getline(cin, title);
	return this->ctrl.deleteVideoFromRepo(title);

}
//
void UI::showAllVideosPlaylist() {

	DynamicVector<Video> v = this->ctrl.getPlaylist().getVideos();
	Video *videos = v.getAllElems();
	if (videos == NULL)
		return;
	if (v.getSize() == 0) {
		cout << "There are no videos in the playlist" << endl;
		return;
	}
	for (int i = 0; i < v.getSize(); i++) {
		Video m = videos[i];
		cout << m.getTitle() << ", Presenter " << m.getPresenter() << ", Duration- " << m.getDuration() << ", Likes- " << m.getLikes() << ", Trailer- " << m.getTrailer() << endl;
	}
}


void UI::showVideosWithPresenter() {
	string presenter;
	cout << "Enter the presenter: ";
	getline(cin, presenter);

	std::vector<Video> v = this->ctrl.getRepo().getVideos();

	if (v.size() == 0) {
		cout << "There are no videos in the playlist" << endl;
		return;
	}
	int ok = 0;
	for (int i = 0; i < v.size(); i++)
	{
		Video m = v[i];
	
		if (strcmp(presenter.c_str(), m.getPresenter().c_str()) == 0)
		{
			ok = 1;
		//cout << m.getTitle() << ", Presenter " << m.getPresenter() << ", Duration- " << m.getDuration() << ", Likes- " << m.getLikes() << ", Trailer- " << m.getTrailer() << endl;
			cout << m.getTitle() << ", Presenter: " << m.getPresenter() << ", Minutes: " << m.getDuration() / 60 << "Seconds: " << (m.getDuration()) % 60 << endl << "\t\t Likes- " << m.getLikes() << ", Trailer- " << m.getTrailer() << endl;
			m.play();
			string answer;
			cout << "Do you want to add this to the playlist? (yes/no/exit)";
			cin >> answer;
			if (answer == "yes")
			{
				cout << "adding";
				this->ctrl.addVideoToPlaylist(m);
			}
			if (answer == "exit")
				break;
		}
		if (i == (v.size() - 1))
			i = 0;
	}
	if (ok == 0)
		cout << "There are no videos that fit the criteria\n";
}

void UI::deleteVideoFromPlaylist() {
	string title;
	cout << "Enter the title of the video you wish to delete:";
	getline(cin, title);
	int res = this->ctrl.deleteVideoFromPlaylist(title);
	if (res == 1)
	{
		cout << "Succesfully deleted! Did you like the video? (yes/no) ";
		string answer;
		getline(cin, answer);
		
		
		if (answer == "yes")
		{
			cout << "in\n";
			this->ctrl.likeVideoFromRepo(title);
		}
	}
	else
	{
		cout<< "Video could not be deleted. Perhaps it is not in the playlist?";
	}
}

//
void UI::showAllVideosRepo() {
	std::vector<Video> v = this->ctrl.getRepo().getVideos();
	
	if (v.size() == 0) {
		cout << "There are no videos in the repo" << endl;
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		Video m = v[i];
		cout << m.getTitle() << ", Presenter: " << m.getPresenter() << ", Minutes: " << m.getDuration()/60 << "Seconds: " << (m.getDuration())%60 << endl <<"\t\t Likes- " << m.getLikes() << ", Trailer- " << m.getTrailer() << endl;
	}
}

int UI::updateVideoFromRepo() {
	cout << "Enter the title of the video you want to update: ";
	string title1;
	getline(cin, title1);
	cout << "Enter the title: ";
	string title;
	getline(cin, title);
	cout << "Enter the presenter: ";
	string presenter;
	getline(cin, presenter);
	cout << "Enter the trailer link: ";
	string trailer;
	getline(cin, trailer);
	cout << "Enter the duration: ";
	int duration;
	cin >> duration;
	cout << "Enter the likes: ";
	int likes;
	cin >> likes;
	return this->ctrl.updateVideoFromRepo(title1, title, presenter, duration, likes, trailer);
}

void UI::printUserMenu()
{
	cout << "0.Exit\n";
	cout << "1.List all the videos in the database with a given presenter:\n";
	cout << "2.List all the videos in the playlist\n";
	cout << "3.Delete a video from the playlist\n";
	cout << "4.List all the videos from the database\n";
	cout << "5.See watchlist\n";
}


void UI::runUser()
{
	int cmd = 0;
	while (true) 
	{

		this->printUserMenu();
		cout << ">> ";
		cin >> cmd;
		cin.ignore();
		if (cmd == 0)
			break;
		if (cmd == 1)
			UI::showVideosWithPresenter();
		if (cmd == 2)
			UI::showAllVideosPlaylist();
		if (cmd == 3)
			UI::deleteVideoFromPlaylist();
		if (cmd == 4)
			UI::showAllVideosRepo();
		if (cmd == 5)
			this->ctrl.seeWatchlistController();
	}
}

void UI::run() {
	while (true) {
		UI::printMenu();
		int cmd{ 0 };
		cout << ">> ";
		cin >> cmd;
		cin.ignore();
		if (cmd == 0)
			break;
		if (cmd == 1) {
			int res = this->addVideoToRepo();
			if (res == 1)
				cout << "Video was added\n";
			else
				cout << "Video was not added\n";
		}
		if (cmd == 2)
			this->showAllVideosRepo();
		if (cmd == 3) {
			int res = this->deleteVideoFromRepo();
			if (res == 1)
				cout << "Video was deleted\n";
			else
				cout << "Video was not deleted\n";
		}
		if (cmd == 4) {
			int res = this->updateVideoFromRepo();
			if (res == 1)
				cout << "Video was updated\n";
			else
				cout << "Video was not updated\n";
		}
	}
}

