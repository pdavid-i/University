#include <iostream>
#include "Exceptions.h"
#include "Video.h"

class Validator {
public:
	static bool validate_presenter(std::string presenter);
	static bool validate_title(std::string title);
	static bool validate_likes(int likes);
	static bool validate_duration(int duration);
	static bool validate_link(std::string link);
	static void validate_video(const Video &m);
};