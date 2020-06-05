#pragma once
#include <exception>
using namespace std;

class quitException : exception {
public:
	quitException(const char* const message = nullptr)
		:exception(message == nullptr ? "Quit the application" : message) {};
};

