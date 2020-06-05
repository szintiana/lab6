#include "exceptions.h"

Ausnahmen::Ausnahmen() {};

Ausnahmen::~Ausnahmen() {};

bool Ausnahmen::check_name(string name) {
	size_t index = name.find_first_of(" ");
	if (index == 0 || index == name.size()) return false;
	else {
		bool gef = true;
		while (index != NULL && index != name.size()) {
			if (isspace(name[index - 1]) || isspace(name[index + 1])) gef = false;
			index = name.find_first_of(" ", index + 1);
		}
		return gef;
	}

}

bool Ausnahmen::check_genre(string genre) {
	if 
		(genre == "Traditional animation" || genre == "Animated series" || genre == "Stop Motion" ||
			genre == "Action" || genre == "Adventure" || genre == "Fantasy" || genre == "Horror" || genre == "SF" || genre == "Thriller" ||
			genre == "Satire" || genre == "Sitcom" ||
			genre == "Documentary" || genre == "Sports") return true;
	else return false;
}

bool Ausnahmen::check_jahr(int jahr) {
	if (jahr > 1892 && jahr <= 2020) return true;
	else return false;
}

bool Ausnahmen::check_likes(int likes) {
	if (likes >= 0) return true;
	else return false;
}

bool Ausnahmen::check_trailer(string trailer) {
	size_t index = trailer.find_first_of("https://www");
	if (index == 0) return true;
	else return false;
}