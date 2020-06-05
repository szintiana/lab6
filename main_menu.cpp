#include "main_menu.h"

void Menu::show() const {
	for (auto i = 0; this->menuItems.size(); i++) {
		this->menuItems[i].show();
	}
}

Menu& Menu::add(const MenuItem& item) {
	this->menuItems.push_back(item);
	return *this;
}

Menu& Menu::add(string Text, function<void()> action) {
	return this->add(MenuItem(this->menuItems.size() + 1, Text, action));
}

MenuItem notFoundMenuItem(-1, "Not found", []() { cout << "\nMenu item not found.\n"; });

MenuItem& Menu::find_item(int option) {
	for (auto i = 0; i < this->menuItems.size(); i++) {
		if (this->menuItems[i].get_option() == option) {
			return this->menuItems[i];
		}
	}
	return notFoundMenuItem;
}

