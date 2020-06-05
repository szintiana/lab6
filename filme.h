#pragma once
#include <string>
using namespace std;

class Film
{
private:
	string Titel;
	string Genre;
	int Jahr;
	int Likes;
	string Trailer;
public:
	Film();
	Film(string titel, string genre, int jahr, int likes, string Trailer);
	~Film();

	string get_titel();
	string get_genre();
	int get_jahr();
	int get_likes();
	string get_trailer();
	void set_titel(string titel);
	void set_genre(string genre);
	void set_jahr(int jahr);
	void set_likes(int jahr);
	void set_trailer(string trailer);
};

