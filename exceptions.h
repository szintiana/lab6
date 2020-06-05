#pragma once
#include<string>

using namespace std;

class Ausnahmen
{
public:
	Ausnahmen();
	~Ausnahmen();

	bool check_name(string name);
	bool check_genre(string genre);
	bool check_jahr(int jahr);
	bool check_likes(int likes);
	bool check_trailer(string trailer);

	bool check_file();

};

