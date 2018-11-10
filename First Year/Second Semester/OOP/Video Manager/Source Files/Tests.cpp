#include "Tests.h"
#include "Controller.h"
#include "Comparator.h"
#include <iostream>
#include <string>

using namespace std;


template <class TElement>
void sortit(DynamicVector<TElement>& v, ComparatorAscendingByDuration comp)
{
	int size = v.getSize();
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size - 1; j++)
		{
			if (comp.compare(v[j], v[j + 1]))
			{
				string v1_title = v[j].getTitle();
				string v2_title = v[j + 1].getTitle();
				string v1_presenter = v[j].getPresenter();
				string v2_presenter = v[j + 1].getPresenter();
				string v1_trailer = v[j].getTrailer();
				string v2_trailer = v[j + 1].getTrailer();
				int v1_duration = v[j].getDuration();
				int v2_duration = v[j + 1].getDuration();
				int v1_likes = v[j].getLikes();
				int v2_likes = v[j + 1].getLikes();

				v[j].setLikes(v2_likes);
				v[j].setTitle(v2_title);
				v[j].setPresenter(v2_presenter);
				v[j].setDuration(v2_duration);
				v[j].setTrailer(v2_trailer);

				v[j + 1].setLikes(v1_likes);
				v[j + 1].setTitle(v1_title);
				v[j + 1].setPresenter(v1_presenter);
				v[j + 1].setDuration(v1_duration);
				v[j + 1].setTrailer(v1_trailer);

			}
		}
	}
}


template <class TElement>
void sort(DynamicVector<TElement>& v, ComparatorDescendingByLikes comp)
{
	int size = v.getSize();
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size - 1; j++)
		{
			if (comp.compare(v[j], v[j + 1]))
			{
				string v1_title = v[j].getTitle();
				string v2_title = v[j + 1].getTitle();
				string v1_presenter = v[j].getPresenter();
				string v2_presenter = v[j + 1].getPresenter();
				string v1_trailer = v[j].getTrailer();
				string v2_trailer = v[j + 1].getTrailer();
				int v1_duration = v[j].getDuration();
				int v2_duration = v[j + 1].getDuration();
				int v1_likes = v[j].getLikes();
				int v2_likes = v[j + 1].getLikes();

				v[j].setLikes(v2_likes);
				v[j].setTitle(v2_title);
				v[j].setPresenter(v2_presenter);
				v[j].setDuration(v2_duration);
				v[j].setTrailer(v2_trailer);

				v[j + 1].setLikes(v1_likes);
				v[j + 1].setTitle(v1_title);
				v[j + 1].setPresenter(v1_presenter);
				v[j + 1].setDuration(v1_duration);
				v[j + 1].setTrailer(v1_trailer);

			}
		}
	}
}


void Test::testComparator()
{
	ComparatorDescendingByLikes comp;
	ComparatorAscendingByDuration compAsc;
	DynamicVector<Video> v;
	assert(v.getSize() == 0);
	Video m1{ "first" , "first", 43, 34, "https://www.youtube.com/watch?v=uJ_1HMAGb4k" };
	Video m2{ "second", "second", 164, 546, "https://www.youtube.com/watch?v=gPjqWwkAymg" };
	Video m3{ "three", "three", 342, 7676, "https://www.youtube.com/watch?v=gPjqWwkAymg" };
	Video m4{ "four" , "four",868, 7657, "https://www.youtube.com/watch?v=uJ_1HMAGb4k" };
	Video m5{ "five", "five", 22, 12, "https://www.youtube.com/watch?v=gPjqWwkAymg" };
	Video m6{ "six", "six", 186, 451, "https://www.youtube.com/watch?v=gPjqWwkAymg" };
	v.add(m6);
	v.add(m5);
	v.add(m4);
	v.add(m3);
	v.add(m1);
	v.add(m2);

	assert(v.getSize() == 6);
	assert(v[5].getTitle() == "second");
	assert(v[4].getTitle() == "first");
	assert(v[3].getTitle() == "three");
	assert(v[2].getTitle() == "four");
	assert(v[0].getTitle() == "six");
	assert(v[1].getTitle() == "five");

	cout << v[0].getTitle() << "likes: " << v[0].getLikes() << '\n';
	cout << v[1].getTitle() << "likes: " << v[1].getLikes() << '\n';
	cout << v[2].getTitle() << "likes: " << v[2].getLikes() << '\n';
	cout << v[3].getTitle() << "likes: " << v[3].getLikes() << '\n';
	cout << v[4].getTitle() << "likes: " << v[4].getLikes() <<'\n';
	cout << v[5].getTitle() << "likes: " << v[5].getLikes() << '\n' << '\n';

	sort(v, comp);

	cout << v[0].getTitle() << "likes: " << v[0].getLikes() <<'\n';
	cout << v[1].getTitle() << "likes: " << v[1].getLikes() << '\n';
	cout << v[2].getTitle() << "likes: " << v[2].getLikes() << '\n';
	cout << v[3].getTitle() << "likes: " << v[3].getLikes() << '\n';
	cout << v[4].getTitle() << "likes: " << v[4].getLikes() << '\n';
	cout << v[5].getTitle() << "likes: " << v[5].getLikes() << '\n' << '\n';
	
	assert(v[0].getTitle() == "five");
	assert(v[1].getTitle() == "first");
	assert(v[2].getTitle() == "six");
	assert(v[3].getTitle() == "second");
	assert(v[4].getTitle() == "four");
	assert(v[5].getTitle() == "three");


	cout << v[0].getTitle() << " duration: " << v[0].getDuration() << '\n';
	cout << v[1].getTitle() << " duration: " << v[1].getDuration() << '\n';
	cout << v[2].getTitle() << " duration: " << v[2].getDuration() << '\n';
	cout << v[3].getTitle() << " duration: " << v[3].getDuration() << '\n';
	cout << v[4].getTitle() << " duration: " << v[4].getDuration() << '\n';
	cout << v[4].getTitle() << " duration: " << v[5].getDuration() << '\n' << '\n';


	sortit(v, compAsc);
	
	cout << v[0].getTitle() << " duration: " << v[0].getDuration() << '\n';
	cout << v[1].getTitle() << " duration: " << v[1].getDuration() << '\n';
	cout << v[2].getTitle() << " duration: " << v[2].getDuration() << '\n';
	cout << v[3].getTitle() << " duration: " << v[3].getDuration() << '\n';
	cout << v[4].getTitle() << " duration: " << v[4].getDuration() << '\n';
	cout << v[4].getTitle() << " duration: " << v[5].getDuration() << '\n' << '\n';

}





void Test::testVideo()
{
	Video m1{ "Ayahuasca", "Vancouver Sleep Clinic", 508, 3000, "https://www.youtube.com/watch?v=db97HUw3ToA&list=LLsDMCMqW-TYazmSoC7VFKcA&index=7" };
	assert(m1.getTitle() == "Ayahuasca");
	assert(m1.getPresenter() == "Vancouver Sleep Clinic");
	assert(m1.getDuration() == 508);
	assert(m1.getLikes() == 3000);
	assert(m1.getTrailer() == "https://www.youtube.com/watch?v=db97HUw3ToA&list=LLsDMCMqW-TYazmSoC7VFKcA&index=7");
	m1.incrementLikes();
	assert(m1.getLikes() == 3001);
	cout << "Tests were run\n";
}

void Test::testDynamicVectorAdd() {
	DynamicVector<Video> v(3);
	assert(v.getSize() == 0);
	v.add(Video("1", "1", 2000, 150, "http://www.imdb.com/title/tt0109830/"));
	v.add(Video("2", "1", 2000, 150, "http://www.imdb.com/title/tt0109830/"));
	v.add(Video("3", "1", 2000, 150, "http://www.imdb.com/title/tt0109830/"));
	assert(v.getSize() == 3);
	assert(v[0].getTitle() == "1");
	assert(v[1].getLikes() == 150);
}

void Test::testDynamicVectorDel() {
	DynamicVector<Video> v(3);
	assert(v.getSize() == 0);
	Video m = Video("1", "1", 2000, 150, "http://www.imdb.com/title/tt0109830/");
	v.add(Video("1", "1", 2000, 150, "http://www.imdb.com/title/tt0109830/"));
	v.add(Video("2", "1", 2000, 150, "http://www.imdb.com/title/tt0109830/"));
	v.add(Video("3", "1", 2000, 150, "http://www.imdb.com/title/tt0109830/"));
	v.del(m);
	assert(v.getSize() == 2);
}


void Test::testDynamicVectorUpdate() {
	DynamicVector<Video> v(3);
	Video m = Video("1", "1", 2000, 150, "http://www.imdb.com/title/tt0109830/");
	Video n = Video("Cocat", "Drama", 1994, 200, "http://www.imdb.com/title/tt0109830/");
	v.add(Video("1", "1", 2000, 150, "http://www.imdb.com/title/tt0109830/"));
	v.update(m, n);
	assert(v[0].getTitle() == "Cocat");
	assert(v[0].getPresenter() == "Drama");
	assert(v[0].getDuration() == 1994);
	v.getAllElems();
	v.resize();
}



void Test::testDynamicVector() {
	Test::testDynamicVectorAdd();
	Test::testDynamicVectorUpdate();
	Test::testDynamicVectorDel();
}


void Test::testRepository() {
	Repository repo{"repo.txt"};
	Video m1{ "Riptide" , "Vance Joy", 204, 1100000, "https://www.youtube.com/watch?v=uJ_1HMAGb4k" };
	Video m2{ "All I've ever known", "Bahamas", 370, 13000, "https://www.youtube.com/watch?v=gPjqWwkAymg" };
	m2.play();
	repo.addVideo(m1);
	repo.addVideo(m1);
	repo.likeVideo(m1);
	repo.deleteVideo(m2);
	repo.updateVideo(m2, m1);
	std::vector<Video> movies = repo.getVideos();
	assert(movies.size() == 1);
	assert(movies[0].getTitle() == "Riptide");
	movies[0].incrementLikes();
	assert(movies[0].getLikes() == 1100002);
	repo.updateVideo(m1, m2);
	repo.deleteVideo(m2);

}


void Test::testPlaylist() {
	Playlist watchlist{};
	watchlist.start();
	Video m1{ "Riptide" , "Vance Joy", 204, 1100000, "https://www.youtube.com/watch?v=uJ_1HMAGb4k" };
	Video m2{ "All I've ever known", "Bahamas", 370, 13000, "https://www.youtube.com/watch?v=gPjqWwkAymg" };
	watchlist.remove(m1);
	watchlist.add(m1);
	watchlist.add(m2);
	watchlist.getCurrentVideo();
	watchlist.next();
	assert(watchlist.isEmpty() == false);
	watchlist.remove(m1);
	watchlist.getVideos();
	watchlist.start();
	watchlist.remove(m2);
	assert(watchlist.isEmpty() == true);
}


void Test::testOverload()
{
	Video v1{ "music", "artist", 1, 1, "www" };
	Video v2{ "music", "qwqwqwq", 9, 9, "xas" };
	Video v3{ "title", "artist", 1, 1, "www" };
	assert(v1 == v2);
	assert((v2 == v3) == false);
	DynamicVector<Video> dyn_v;
	assert(dyn_v.getSize() == 0);
	dyn_v.add(v1);
	assert(dyn_v.getSize() == 1);
	assert((dyn_v - v1).getSize() == 0);
}


void Test::testController() {
	Repository repo{"repo.txt"};
	Controller ctrl{ repo };
	ctrl.addVideoToRepo("Un", "Doi", 2000, 100, "www.1.com");
	ctrl.addVideoToRepo("Trei", "4", 2000, 100, "www.2.com");
//	assert(ctrl.getRepo().getVideos().getSize() == 2);
	ctrl.deleteVideoFromRepo("Un");
	ctrl.likeVideoFromRepo("Trei");
	ctrl.updateVideoFromRepo("Trei", "zmei", "lei", 10, 10, "www");
	Video m{ "Cinqo","Crestele",2000,100,"www.3.com" };
	Video m2{ "Cinqo","Crestele",2000,100,"www.3.com" };
	ctrl.addVideoToPlaylist(m);
	ctrl.addVideoToPlaylist(m2);
	Playlist watchlist = ctrl.getPlaylist();
	ctrl.deleteVideoFromPlaylist("Cinqo");
	assert(watchlist.isEmpty() == false);
}

void Test::testAll() {
	//Test::testOverload();
	//Test::testVideo();
	//Test::testDynamicVector();
	//Test::testRepository();
//	Test::testPlaylist();
//	Test::testController();
	Test::testComparator();
}
