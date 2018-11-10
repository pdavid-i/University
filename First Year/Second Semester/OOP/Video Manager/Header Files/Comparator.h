
#pragma once
#include "DynamicVector.h"
#include "Video.h"
#include <string>

class Comparator {
public:
	virtual bool compare(Video t1, Video t2) = 0;

};

class ComparatorDescendingByLikes : public Comparator {

public:
	bool compare(Video v1, Video v2) override {
		if (v1.getLikes() > v2.getLikes())
			return true;
		return false;
	};
};

class ComparatorAscendingByDuration : public Comparator {

public:
	bool compare(Video v1, Video v2) override {
		if (v1.getDuration() < v2.getDuration())
			return true;
		return false;
	};
};