#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include "menu_item.h"

using namespace std;

class Menu : MenuItem {

private:
	vector<MenuItem> menuItems;

public:
	Menu()
		:MenuItem(0, "Menu", nullptr) {};

	Menu(int option, string Text) : MenuItem(option, Text, nullptr) {};

	virtual void show() const override;

	Menu& add(const MenuItem& item);

	Menu& add(string Text, function<void()> action);

	MenuItem& find_item(int option);
	
};

