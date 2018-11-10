#pragma once
#include "Repo.h"
#include "Playlist.h"
#include "Watchlist.h"

using namespace std;

class Controller {
private:
	Repository repo;
	Playlist playlist;
	Watchlist* watchlist;
public:
	Controller(const Repository &r) : repo{ r } {}
	Controller(const Repository& r, Watchlist* adoption) : repo(r), watchlist(adoption) {}
	Playlist getPlaylist() const { return playlist; }

	Repository getRepo() const {
		return repo;
	}

	//
	Video getWatchlistPosition(int pos)
	{
		return this->watchlist->getVideo(pos);
	}
	vector<Video> getVideosFromWatchlist()
	{
		return this->watchlist->getVideos();
	}
	void addVideoToPlaylist(const Video &video);
	int deleteVideoFromPlaylist(const string &str);
	void seeWatchlistController();


	//
	int likeVideoFromRepo(const string &title);
	int addVideoToRepo(const string &title, const string &presenter, const int duration, const int likes, const string &trailer);
	int deleteVideoFromRepo(const string &title);
	int updateVideoFromRepo(const string &title1, const string &title2, const string &presenter2, const int duration2, const int likes2, const string &trailer2);
};













