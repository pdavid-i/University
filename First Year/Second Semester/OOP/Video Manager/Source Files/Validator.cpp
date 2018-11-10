#include "Validator.h"

bool Validator::validate_link(std::string link)
{
	/*int length = link.length();
	if (length <= 11)
		return false;
	std::string prefix = link.substr(0, 11);
	if (prefix != "www.youtube")
		return false;
	*/
	return true;
}

bool Validator::validate_presenter(std::string presenter)
{
	int size = presenter.length();
	if (size)
		return true;
	return false;
}

bool Validator::validate_title(std::string title)
{
	int size = title.length();
	if (size)
		return true;
	return false;
}

bool Validator::validate_likes(int nr)
{
	return (nr >= 0);
}

bool Validator::validate_duration(int nr)
{
	return (nr >= 1);
}

void Validator::validate_video(const Video &a)
{
	string errorMsg = "";
	if (!Validator::validate_title(a.getTitle())) {
		errorMsg += "invalid name\n";
	}
	if (!Validator::validate_presenter(a.getPresenter())) {
		errorMsg += "invalid presenter\n";
	}
	if (!Validator::validate_likes(a.getLikes())) {
		errorMsg += "invalid number of likes\n";
	}
	if (!Validator::validate_duration(a.getDuration())) {
		errorMsg += "invalid duration\n";
	}
	if (!Validator::validate_link(a.getTrailer())) {
		errorMsg += "invalid link\n";
	}
	if (errorMsg.size() > 0)
		throw ValidatorException{ errorMsg };
}