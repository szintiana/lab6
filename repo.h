#pragma once
#include "filme.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Repository
{
private:
	fstream film_file;

public:

	void add_liste(Film film);
	void remove_liste(string titel);
	void update(string titel, Film film);
	void rate_movie(string title, string rating, Film film);
};

