#include "Playlist.h"


Playlist::Playlist()
{
	this->current = 0;
}

DynamicVector<Video> Playlist::getVideos() {
	return this->videos;
}

void Playlist::add(const Video& Video)
{
	this->videos.add(Video);
}

int Playlist::remove(const Video &m) {
	int pos = this->videos.find(m);
	if (pos >= 0) {
		this->videos.del(m);
		return 1;
	}
	return 0;
}

Video Playlist::getCurrentVideo()
{
	if (this->current == this->videos.getSize())
		this->current = 0;
	return this->videos[this->current];
}

void Playlist::start()
{
	if (this->videos.getSize() == 0)
		return;
	this->current = 0;
	Video currentVideo = this->getCurrentVideo();
	currentVideo.play();
}

void Playlist::next()
{
	if (this->videos.getSize() == 0)
		return;
	this->current++;
	Video currentVideo = this->getCurrentVideo();
	currentVideo.play();
}

bool Playlist::isEmpty()
{
	return this->videos.getSize() == 0;
}