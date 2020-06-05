#pragma once
#include <iostream>
#include <string>
#include <functional>
#include <vector>

using namespace std;

class MenuItem
{
private:
	string Text;
	int option;
	function<void()> action;

public:
	MenuItem(int option, string Text, function<void()> action) {
		this->option = option;
		this->Text = Text;
		this->action = action;
	}

	int get_option() const;

	virtual void show() const;

	void execute();
};

