#include "menu_item.h"

int MenuItem::get_option() const {

	return this->option;
}

void MenuItem::show() const {
	cout << this->option << "." << this->Text << "\n";
}

void MenuItem::execute() {
	this->action();
}