#pragma once
#include <string>
#include <iostream>

using namespace std;

class Video {
private:
	string title;
	string presenter;
	int duration;
	int likes;
	string trailer;
	
public:
	Video();
	Video(const string &title, const string &genre, const int duration, const int likes, const string &trailer);

	friend ostream& operator<<(ostream& os, const Video& vid);

	friend istream& operator>>(istream& is, Video& vid);


	bool operator==(Video const &v)
	{
		return this->getTitle() == v.getTitle() ;
	}

	string getTitle() const {
		return title;
	}
	string getPresenter() const {
		return presenter;
	}
	int getDuration() const {
		return duration;
	}
	int getLikes() const {
		return likes;
	}
	string getTrailer() const {
		return trailer;
	}
	void incrementLikes()
	{
		this->likes += 1;
	}

	void setTitle(string new_title) {
		this->title = new_title;
	}
	
	void setPresenter(string new_presenter) {
		this->presenter = new_presenter;
	}

	void setDuration(int new_duration)
	{
		this->duration = new_duration;
	}

	void setLikes(int new_likes)
	{
		this->likes = new_likes;
	}

	void setTrailer(string new_trailer)
	{
		this->trailer = new_trailer;
	}

	void printIt()
	{
		std::cout << "Title: " << this->title << " Presenter: " << this->presenter << " Duration: " << this->duration << " Likes: " << this->likes << " Link: " << this->trailer;
	}
	void play();
	//bool operator(Movie &m);
};

