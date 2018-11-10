#pragma once

#include "Video.h"
#include "Repo.h"

/*
Generic class for an undo action.
For each type of action (add, delete, update), a new class will be created, inheriting from this UndoAction.
*/
class UndoAction
{
public:
	virtual void executeUndo() = 0;
	// virtual destructor!
	virtual ~UndoAction() {};
};

class UndoAdd : public UndoAction
{
private:
	Video addedVideo;
	Repository& repo;	// we keep a reference to the repository to be able to undo the action
public:
	UndoAdd(Repository& _repo, const Video& v) : repo{ _repo }, addedVideo{ v } {}

	/*
	For the add operation, the reverse operation that must be executed is "remove".
	*/
	void executeUndo() override
	{
		this->repo.deleteVideo(addedVideo);
	}
};

class UndoRemove : public UndoAction
{
private:
	Video deletedVideo;
	Repository& repo;
public:
	UndoRemove(Repository& _repo, const Video& s) : repo{ _repo }, deletedVideo{ s } {}

	void executeUndo() override
	{
		this->repo.addVideo(deletedVideo);
	}
};