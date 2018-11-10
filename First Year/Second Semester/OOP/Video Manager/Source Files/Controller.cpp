#include "Controller.h"
#include "Validator.h"
#pragma once

using namespace std;

//

void Controller::addVideoToPlaylist(const Video& video) {
	try
	{
		Validator::validate_video(video);
	}
	catch (const ValidatorException& ex)
	{
		cout << "An error occured at validation. Error: " + ex.getMessage() + " \n";
	}
	try
	{
		this->playlist.add(video);
		this->watchlist->add(video);
		this->watchlist->writeToFile();
	}
	catch (const RepoException& repo_exception)
	{
		cout << "Repository Exception! Error: " + repo_exception.getMessage() + " \n";
	}
}

int Controller::deleteVideoFromPlaylist(const string &str)
{
	Video m{ str, "presenter", 300, 1 , "www.youtube.com/wow" };
	try
	{
		Validator::validate_video(m);
	}
	catch (const ValidatorException& ex)
	{
		cout << "An error occured at validation. Error: " + ex.getMessage() + " \n";
	}
	try
	{
		return this->playlist.remove(m);
	}
	catch (const RepoException& repo_exception)
	{
		cout << "Repository Exception!. Error: " + repo_exception.getMessage() + " \n";
	}
	return (0);
}

//

int Controller::addVideoToRepo(const string &title, const string &presenter, const int duration, const int likes, const string &trailer) {
	Video m{ title, presenter, duration, likes, trailer };


	try
	{
		Validator::validate_video(m);
	}
	catch (const ValidatorException& ex)
	{
		cout << "An error occured at validation. Error: " + ex.getMessage() + " \n";
	}
	try
	{
		return this->repo.addVideo(m);
	}
	catch (const RepoException& repo_exception)
	{
		cout << "Repository Exception! Error: " + repo_exception.getMessage() + " \n";
	}
	return 0;
}

int Controller::likeVideoFromRepo(const string &title)
{
	Video m{ title, "presenter", 1, 1, "www.youtube.com/wow" };
	try
	{
		Validator::validate_video(m);
	}
	catch (const ValidatorException& exception)
	{
		cout << "An error occured at validation. Error: " + exception.getMessage() + " \n";
	}
	try
	{
		return this->repo.likeVideo(m);
	}
	catch (const RepoException& exception)
	{
		cout << "Repository Exception! Error " + exception.getMessage() + " \n";
	}
	return (0);
}

int Controller::deleteVideoFromRepo(const string &title) {
	Video m{ title,"presetere",1,1,"www.youtube.com/wow" };

	try
	{
		Validator::validate_video(m);
	}
	catch (const ValidatorException& exception)
	{
		cout << "An error occured at validation. Error: " + exception.getMessage() + " \n";
	}
	try
	{
		return this->repo.deleteVideo(m);
	}
	catch (const RepoException& exception)
	{
		cout << "Repository Exception! Error " + exception.getMessage() + " \n";
	}
	return (0);
}

int Controller::updateVideoFromRepo(const string &title1, const string &title2, const string &genre2, const int year2, const int likes2, const string &trailer2) {

	Video m1{ title1,"adassda",1,1,"www.youtube.com/wow" };
	Video m2{ title2, genre2, year2, likes2, trailer2 };

	try
	{
		Validator::validate_video(m1);
	}
	catch (const ValidatorException& exception)
	{
		cout << "An error occured at validation. Error: " + exception.getMessage() + " \n";
	}
	try
	{
		Validator::validate_video(m2);
	}
	catch (const ValidatorException& exception)
	{
		cout << "An error occured at validation. Error: " + exception.getMessage() + " \n";
	}
	try
	{
		return this->repo.updateVideo(m1, m2);
	}
	catch (const RepoException& exception)
	{
		cout << "Repository Exception! Error " + exception.getMessage() + " \n";
	}
	return (0);
}

void Controller::seeWatchlistController()
{
	this->watchlist->writeToFile();
	this->watchlist->displayWatchlist();
}
