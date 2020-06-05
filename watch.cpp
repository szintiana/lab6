#include "watch.h"

using namespace std;

Watchlist::Watchlist()
{

}

void Watchlist::add_to_vector(Film film)
{
	watchlist.push_back(film);
}

void Watchlist::remove_from_vector(string title)
{
	for (unsigned int it = 0; it < watchlist.size(); it++)
	{
		if (watchlist[it].get_titel() == title)
		{
			lastremoved = watchlist[it];
			watchlist.erase(watchlist.begin() + it);
		}
	}
}

void Watchlist::update_in_vector(string title, string new_title, string new_genre, int new_year, int new_likes, string new_trailer)
{
	for (unsigned int it = 0; it < watchlist.size(); it++)
	{
		if (watchlist[it].get_titel() == title)
		{
			if (new_title != "")
				watchlist[it].set_titel(new_title);

			if (new_genre != "")
				watchlist[it].set_genre(new_genre);

			if (new_year != NULL)
				watchlist[it].set_jahr(new_year);

			if (new_likes != NULL)
				watchlist[it].set_likes(new_likes);

			if (new_trailer != "")
				watchlist[it].set_trailer(new_trailer);

		}
	}
}

void Watchlist::update_watchlist_file()
{
	fstream watchlist_file;
	watchlist_file.open("Watchlist.txt");
	for (int i = 0; i < watchlist.size(); i++)
		watchlist_file << watchlist[i].get_titel() << " " << watchlist[i].get_genre() << " " << watchlist[i].get_jahr() << " " << watchlist[i].get_likes() << " " << watchlist[i].get_trailer() << endl;
	watchlist_file.close();
}

void Watchlist::filter_by_genre(string genre)
{
	fstream aux;
	aux.open("Genre.txt");
	film_file.open("Liste.txt");
	int space1, space2;
	string line;
	while (getline(film_file, line))
	{
		space1 = 0;
		space2 = 0;
		for (int i = 0; i < line.find_first_of("\n"); i++)
		{
			if (line.substr(i) == " " && space1 != 1)
				space1++;
			if (space1 == 1)
				space1 = i;
			if (line.substr(i) == " " && space2 != 2)
				space2++;
			if (space2 == 2)
				space2 = i;
		}
		if (line.substr(space1, space2) == genre)
		{
			aux << line << endl;
		}
	}
	film_file.close();
	aux.close();
}

vector<Film> Watchlist::genre_to_vector()
{
	ifstream in;
	in.open("Genre.txt");

	if (!"Genre.txt")
		throw exception();
	
	vector<Film> genre_vector;
	Film aux;
	string titel, genre, trailer;
	int year, likes;
	while (in >> titel >> genre >> year >> likes >> trailer)
	{
		aux.set_titel(titel);
		aux.set_genre(genre);
		aux.set_jahr(year);
		aux.set_likes(likes);
		aux.set_trailer(trailer);
		genre_vector.push_back(aux);
	}

	return genre_vector;
}

Film Watchlist::get_lastremoved()
{
	return lastremoved;
}

void Watchlist_CSV::write_to_csv()
{
	csv_file.open("Watchlist.csv");

	for (auto it : watchlist)
	{
		csv_file << it.get_titel() << "," << it.get_genre() << "," << it.get_jahr() << "," << it.get_likes() << "," << it.get_trailer() << endl;
	}

	csv_file.close();
}


void Wachlist_HTML::write_to_html()
{
	html_file.open("Wachlist.html");
	
	html_file << "<!DOCTYPE html>\n<html>\n<head>\n<title>Watchliste</title>\n</head>\n<body>\n<table border='1'>\n<tr>\n<td>Titel</td>\n<td>Genre</td>\n<td>Jahr</td>\n<td>Likes</td>\n<td>Trailer</td>\n</tr>";

	for (auto it : watchlist)
	{
		html_file << "\n<tr>\n<td>%s</td>\n<td>%s</td>\n<td>%d</td>\n<td>%d</td>\n<td>%s</td>\n</tr>" << it.get_titel() << it.get_genre() << it.get_jahr() << it.get_likes() << it.get_trailer();
	}
}
