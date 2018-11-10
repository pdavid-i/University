#pragma once
#include "Video.h"
#include "DynamicVector.h"
#include <vector>
#include <string>

class Repository {
private:
//	DynamicVector<Video> videos;
	std::vector<Video> videos;
	std::string filename;
public:
	Repository(const string &filename);

	int addVideo(const Video &m);
	int deleteVideo(const Video &m);
	int updateVideo(const Video &m1, const Video &m2);
	int likeVideo(const Video&m);

	std::vector<Video> getVideos() const {
		return videos;
	}
private:
	void readFromFile();
	void writeToFile();
};