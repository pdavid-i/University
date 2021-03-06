#pragma once
#include "Video.h"
#include <vector>
#include <cassert>

template <class TElement>

class DynamicVector {
private:
	int size;
	int capacity;

public:
	TElement * elems;
	DynamicVector(int capacity = 10);

	DynamicVector(const DynamicVector &v);
	~DynamicVector();


	DynamicVector &operator = (const DynamicVector &v);
	DynamicVector &operator - (Video &e)
	{
		this->del(e);
		return *this;
	}

	void add(const TElement &e);
	void del(const TElement &e);
	int find(const TElement &e);
	TElement getOnPos(int pos) {
		return this->elems[pos];
	}
	vector<Video> getAsVector();
	void update(const TElement &e1, const TElement &e2);
	TElement &operator [](int i);
	int like(const TElement &e);
	int getSize() const;
	TElement * getAllElems() {return this->elems;}
	void resize(double factor = 2);
};

#include "DynamicVector.h"
#include <string.h>
#include <assert.h>

template <class TElement>
vector<Video> DynamicVector<TElement>::getAsVector()
{
	vector<Video> mega_return;
	for (int i = 0; i < this->size; i++)
		mega_return.push_back(this->elems[i]);

	return mega_return;
}

template <class TElement>
DynamicVector<TElement>::DynamicVector(int capacity) {
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}

template <class TElement>
DynamicVector<TElement>::DynamicVector(const DynamicVector &v) {
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

template <class TElement>
DynamicVector<TElement>::~DynamicVector() {
	delete[] this->elems;
}

template<class TElement>
inline DynamicVector<TElement> & DynamicVector<TElement>::operator=(const DynamicVector<TElement> & v)
{
	if (this == &v)
		return *this;
	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

template <class TElement>
void DynamicVector<TElement>::add(const TElement &e) {
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

template <class TElement>
void DynamicVector<TElement>::del(const TElement &e) {
	int pos = find(e);
	int i;
	for (i = pos; i < this->size - 1; i++)
		this->elems[i] = this->elems[i + 1];
	this->size--;
}

template <class TElement>
int DynamicVector<TElement>::like(const TElement &e)
{
	int pos = DynamicVector<TElement>::find(e);
	this->elems[pos].incrementLikes();
	return 1;
}

template <class TElement>
int DynamicVector<TElement>::find(const TElement &e) {
	int i;
	for (i = 0; i < this->size; i++) {
		if (e.getTitle() == this->elems[i].getTitle())
			return i;
	}
	return -1;
}

template <class TElement>
void DynamicVector<TElement>::update(const TElement &e1, const TElement &e2) {
	int i = find(e1);
	this->elems[i] = e2;
}

template <class TElement>
void DynamicVector<TElement>::resize(double factor) {
	this->capacity *= static_cast<int>(factor);

	TElement *els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];
	delete[] this->elems;
	this->elems = els;
}

//template <class TElement>
//TElement *DynamicVector<TElement>::getAllElems()  {
	//return this->elems;
//}

template <class TElement>
int DynamicVector<TElement>::getSize() const {
	return this->size;
}

template <class TElement>
TElement &DynamicVector<TElement>::operator [](int i)
{
	return elems[i];
}

