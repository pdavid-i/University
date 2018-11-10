#pragma once
#include <string>

class ValidatorException {
	//A class that validates the input for a video object
private:
	std::string message;
public:
	ValidatorException(const std::string& msg) :message{ msg } {};
	const std::string& getMessage() const
	{
		return this->message;
	}
};

class RepoException {
	//A class that validates the repository operations
private:
	std::string message;
public:
	RepoException(const std::string& msg) :message{ msg } {};
	const std::string& getMessage() const{
			return this->message;
		}
};
