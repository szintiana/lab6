#pragma once
#include "filme.h"
#include "repo.h"
#include "watch.h"
#include "main_menu.h"

#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <shellapi.h>
#include <vector>


using namespace std;

class Controller {

private:
	Repository repo;
	Menu menu;
	Watchlist_CSV csv;
	Wachlist_HTML html;
	Watchlist to_watch;

	void CreateMenu();
	void CreateMenuAdmin();
	void CreateMenuClient();

public:
	
	void add_film_liste();
	void remove_film_liste();
	void update();
	void remove_from_watchlist();
	void update_watchlist();
	void filter_by_genre();
	void open_csv();
	void open_html();
	void play_trailer(string trailer);
	void Run_Admin();
	void Run_Client();
};

