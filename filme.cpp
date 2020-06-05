#include "filme.h"
Film::Film() {
	this->Titel = "";
	this->Genre = "";
	this->Jahr = 0;
	this->Likes = 0;
	this->Trailer = "";
};

Film::Film(string titel, string genre, int jahr, int likes, string trailer) {
	this->Titel = titel;
	this->Genre = genre;
	this->Jahr = jahr;
	this->Likes = likes;
	this->Trailer = trailer;
};

string Film::get_titel() {
	return this->Titel;
};

string Film::get_genre() {
	return this->Genre;
};

int Film::get_jahr() {
	return this->Jahr;
};

int Film::get_likes() {
	return this->Likes;
};

string Film::get_trailer() {
	return this->Trailer;
}

void Film::set_titel(string titel) {
	this->Titel = titel;
};

void Film::set_genre(string genre) {
	this->Genre = genre;
};

void Film::set_jahr(int jahr) {
	this->Jahr = jahr;
};

void Film::set_likes(int likes) {
	this->Likes = likes;
};

void Film::set_trailer(string trailer) {
	this->Trailer = trailer;
};

Film::~Film() {};