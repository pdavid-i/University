#include "Repo.h"
#include <string>
#include "Exceptions.h"
#include <algorithm>
#include <fstream>
#include "Utils.h"

using namespace std;

Repository::Repository(const string& filename) {
	//A function that reads a repository from a text file
	this->filename = filename;
	this->readFromFile();
}

int Repository::addVideo(const Video &m) {
	// A function that takes a Video as a parameter and adds it to the repo, having written it to the text file
	//input: Video m
	//output: 1 - if it was succesfully added
	//	    : 0 - if any error were thrown
	if(std::find(this->videos.begin(), this->videos.end(), m) == this->videos.end()) {
		this->videos.push_back(m);
		this->writeToFile();
		return 1;
	}
	throw RepoException(" Video already in repository!\n");
	return 0;
}

int Repository::deleteVideo(const Video &m) {
	// A function that takes a Video as a parameter and deletes it from the repo, having written it to the text file
	//input: Video m
	//output: 1 - if it was succesfully added
	//	    : 0 - if any error were thrown
	if (std::find(this->videos.begin(), this->videos.end(), m) != this->videos.end()) {
		this->videos.erase(std::find(this->videos.begin(), this->videos.end(), m));
		this->writeToFile();
		return 1;
	}
	throw RepoException(" Element to be deleted does not exist!!\n");
	return 0;
}

int Repository::likeVideo(const Video &m)
{
	// A function that takes a Video as a parameter and increments it in the repo, having written it to the text file
	//input: Video m
	//output: 1 - if it was succesfully added
	//	    : 0 - if any error were thrown
	int position = distance(this->videos.begin(),std::find(this->videos.begin(), this->videos.end(), m));
	if (std::find(this->videos.begin(), this->videos.end(), m) != this->videos.end()) {
		this->videos[position].incrementLikes();
		return (1);
	}
	throw RepoException(" Video does not exist!\n");
	return (0);
}

int Repository::updateVideo(const Video &m1, const Video &m2) {
	// A function that takes a Video as a parameter and updates its value, having written it to the text file
	//input: Video m
	//output: 1 - if it was succesfully added
	//	    : 0 - if any error were thrown
	int position = distance(this->videos.begin(), std::find(this->videos.begin(), this->videos.end(), m1));
	if (position >= 0) {
		std::replace(this->videos.begin(), this->videos.end(), m1, m2);
		this->writeToFile();
		return 1;
	}
	throw RepoException(" Video does not exist!\n");
	return (0);
}

void Repository::readFromFile() {
	ifstream file(this->filename);

	if (!file.is_open())
		return;
	Video m;
	while (file >> m)
		this->videos.push_back(m);

	file.close();
}

void Repository::writeToFile() {
	ofstream file(this->filename);
	if (!file.is_open())
		return;
	for (auto m : this->videos) {
		file << m;
	}
	file.close();
}