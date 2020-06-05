#pragma once
#include "menu_item.h"
#include "quit_exception.h"

class QuitMenuItem : public MenuItem{
public:

	QuitMenuItem(int option) :MenuItem(option, "Quit", []() {throw quitException(); }) {
	}
	
};

