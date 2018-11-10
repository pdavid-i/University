#pragma once
#include "DynamicVector.h"
#include "Video.h"

class Playlist
{
private:
	DynamicVector<Video> videos;
	int current;

public:
	Playlist();

	// Adds a song to the playlist.
	void add(const Video& video);

	// Returns the song that is currently playing.
	Video getCurrentVideo();

	// Starts the playlist - plays the first song.
	void start();
	//
	int remove(const Video& video);

	// Plays the next song in the playlist.
	void next();

	//Returns all videos in the playlist
	DynamicVector<Video> getVideos();

	// Checks if the playlist is empty.
	bool isEmpty();
};

