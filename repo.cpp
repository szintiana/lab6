#include "repo.h"

void Repository::add_liste(Film film) {

	bool gef = true;
	
	film_file.open("Liste.txt");

	string line;
	while (getline(film_file, line)) {
		string titel = line.substr(0, line.find_first_of(" "));
		if (titel == film.get_titel()) gef = false;
	}

	if (gef) film_file << "\n%s %s %d %d \n%s" << 
		film.get_titel() << film.get_genre() << film.get_jahr() << film.get_likes() << film.get_trailer();

	film_file.close();
};

void Repository::remove_liste(string film) {
	fstream temp;
	temp.open("temp.txt");

	film_file.open("Liste.txt");
	string line1, line2;
	while (getline(film_file, line1) && getline(film_file, line2)) {
		string titel = line1.substr(0, line1.find_first_of(" "));
		if (titel == film);
		else temp << "\n" << line1 << "\n" << line2;
	}
	film_file.close();

	temp.close();

	remove("Liste.txt");

	rename("temp.txt" , "Liste.txt");

};

void Repository::update(string titel, Film film) {
	fstream temp;
	temp.open("temp.txt");

	film_file.open("Liste.txt");
	string line1, line2;
	while (getline(film_file, line1) && getline(film_file, line2)) {
		string name = line1.substr(0, line1.find_first_of(" "));
		if (name == titel) temp << "\n%s %s %d %d \n%s" <<
			film.get_titel() << film.get_genre() << film.get_jahr() << film.get_likes() << film.get_trailer();
		else temp << "\n" << line1 << "\n" << line2;
	}
	film_file.close();

	temp.close();

	remove("Liste.txt");
	rename("temp.txt", "Liste.txt");	
}

void Repository::rate_movie(string title, string rating, Film film)
{
	fstream aux;
	aux.open("aux.txt");

	film_file.open("Liste.txt");

	string line;

	while (getline(film_file, line))
	{

		if (line.substr(0, line.find_first_of(" ")) == title)
		{
			if (rating == "Y" || rating == "y")
				aux << film.get_titel() << " " << film.get_genre() << " " << film.get_jahr() << " " << film.get_likes() + 1 << " " << film.get_trailer() << endl;
			else
				if (rating == "N" || rating == "n")
					aux << film.get_titel() << " " << film.get_genre() << " " << film.get_jahr() << " " << film.get_likes() - 1 << " " << film.get_trailer() << endl;
				else
					aux << line << endl;
		}
		else
			aux << line << endl;
	}

	film_file.close();

	aux.close();

	remove("Liste.txt");
	rename("aux.txt", "Liste.txt");
}


