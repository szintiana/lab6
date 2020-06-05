#include "ctrl.h"
#include "quit_menu_item.h"

void Controller::CreateMenu()
{
	this->menu.add("Log in as admin", [this]() {this->CreateMenuAdmin(); });
	this->menu.add("Log in as admin", [this]() {this->CreateMenuClient(); });
	this->menu.add(QuitMenuItem(3));
}

void Controller::CreateMenuAdmin() {
	this->menu.add("Add Film", [this]() {this->add_film_liste(); });
	this->menu.add("Remove Film", [this]() {this->remove_film_liste(); });
	this->menu.add("Update Film", [this]() {this->update(); });
	this->menu.add(QuitMenuItem(4));

}

void Controller::CreateMenuClient()
{
	this->menu.add("View films by genre", [this]() {this->filter_by_genre(); });
	this->menu.add("Remove film from watchlist", [this]() {this->remove_from_watchlist(); });
	this->menu.add("Update watchlist", [this]() {this->update_watchlist(); });
	this->menu.add("Open watchlist as csv", [this]() {this->open_csv(); });
	this->menu.add("Open watchlist as html", [this]() {this->open_html(); });
	this->menu.add(QuitMenuItem(6));
}

void Controller::add_film_liste() {
	string titel, genre, trailer; int jahr, likes;
	cout << "Titel\n";
	cin >> titel;
	cout << "Genre\n";
	cin >> genre;
	cout << "Jahr\n";
	cin >> jahr;
	cout << "Likes\n";
	cin >> likes;
	cout << "Trailer\n";
	cin >> trailer;
	Film x(titel, genre, jahr, likes, trailer);
	repo.add_liste(x);
};

void Controller::remove_film_liste() {
	cout << "titel: ";
	string titel;
	cin >> titel;
	repo.remove_liste(titel);
};

void Controller::update() {
	cout << "titel: ";
	string old_titel;
	cin >> old_titel;
	string new_titel, genre, trailer; int jahr, likes;
	cout << "Titel\n";
	cin >> new_titel;
	cout << "Genre\n";
	cin >> genre;
	cout << "Jahr\n";
	cin >> jahr;
	cout << "Likes\n";
	cin >> likes;
	cout << "Trailer\n";
	cin >> trailer;
	Film x(new_titel, genre, jahr, likes, trailer);
	repo.update(old_titel, x);
}

void Controller::remove_from_watchlist()
{
	string auxtitle, opinion;
	Film last;
	cout << "titel: ";
	cin >> auxtitle;
	
	to_watch.remove_from_vector(auxtitle);

	last = to_watch.get_lastremoved();

	cout << "y = like\nn = dislike\n";
	cin >> opinion;

	repo.rate_movie(auxtitle, opinion, last);

	to_watch.update_watchlist_file();
}

void Controller::update_watchlist()
{
	string title, newtitle, newgenre, newtrailer;
	int newyear, newlikes;

	cout << "Which movie would you like to update?\n";
	cin >> title;
	cout << "new title: ";
	cin >> newtitle;
	cout << "\nnew genre: ";
	cin >> newgenre;
	cout << "\nnew year: ";
	cin >> newyear;
	cout << "\nnew likes: ";
	cin >> newlikes;
	cout << "\nnew trailer: ";
	cin >> newtrailer;

	to_watch.update_in_vector(title, newtitle, newgenre, newyear, newlikes, newtrailer);
	to_watch.update_watchlist_file();
}

void Controller::filter_by_genre()
{
	int it = 0;
	vector<Film> temp;
	string genre, option = "Y", addfilm;
	cout << "genre: ";
	cin >> genre;
	to_watch.filter_by_genre(genre);
	temp = to_watch.genre_to_vector();
	
	while (option == "Y" && it < temp.size() || option == "y" && it < temp.size())
	{
		play_trailer(temp[it].get_trailer());

		cout << "\ntype 'y' to add movie to watchlist\n";
		cin >> addfilm;

		if (addfilm == "Y" || addfilm == "y")
			to_watch.add_to_vector(temp[it]);

		cout << "\ntype 'y' to play the trailer\n";
		cin >> option;

		it++;
	}

	to_watch.update_watchlist_file();
}

void Controller::open_csv()
{
	system("notepad.exe Watchlist.csv");
}

void Controller::open_html()
{
	string helpfile = "Watchlist.html";
	wstring helpfile2(helpfile.begin(), helpfile.end());
	LPCTSTR htmlfile = helpfile2.c_str();

	string alpha = "open";
	wstring alph(alpha.begin(), alpha.end());
	LPCWSTR status = alph.c_str();

	ShellExecute(NULL, status, htmlfile, NULL, NULL, SW_SHOWNORMAL);
	system("PAUSE");
}

void Controller::play_trailer(string trailer)
{
	wstring beta(trailer.begin(), trailer.end());
	LPCWSTR aux = beta.c_str();
	string alpha = "open";
	wstring alph(alpha.begin(), alpha.end());
	LPCWSTR status = alph.c_str();
	ShellExecute(NULL, status, aux, NULL, NULL, SW_SHOWNORMAL);
}

void Controller::Run_Admin() {
	this->CreateMenuAdmin();

	try {
		while (true) {
			this->menu.show();
			int option;
			cin >> option;

			auto menuItem = this->menu.find_item(option);
			menuItem.execute();
		}
	}
	catch (quitException qex) {
	}
	catch (exception ex) {
		cout << "exception: " << ex.what() << endl;
	}
}

void Controller::Run_Client() {
	this->CreateMenuClient();

	try {
		while (true) {
			this->menu.show();
			int option;
			cin >> option;

			auto menuItem = this->menu.find_item(option);
			menuItem.execute();
		}
	}
	catch (quitException qex) {
	}
	catch (exception ex) {
		cout << "exception: " << ex.what() << endl;
	}
}
