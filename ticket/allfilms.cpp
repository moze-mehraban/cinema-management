#include "allfilms.h"
#include <iostream>
#include <fstream>
using namespace std;
void AllFilms::WriteToFile() {
	ofstream out;
	out.open("film.txt");
	for (int i = 0; i < numFilm; i++) {
		out << films[i].getID() << "\t" << films[i].getName()
			<< endl;
	}
	out.close();
}
void AllFilms::Print() {
	for (int i = 0; i < numFilm; i++)
	{
		films[i].Print();
	}
}
Film AllFilms::getfilm(int id)
{
	for (int i = 0; i < numFilm; i++) {
		if (films[i].getID() == id) {
			return films[i];
		}
	}
}
AllFilms::AllFilms(int capacity) {
	this->Capacity = capacity;
	numFilm = 0;
	films = new Film[capacity];
}
void AllFilms::Add(Film f) {
	if (numFilm < Capacity) {
		films[numFilm] = f;
		numFilm++;
	}
}
void AllFilms::remove(int) {

}
void AllFilms::ReadFromFile() {
	int ID;
	char filmName[20];
	ifstream inputFile;
	inputFile.open("film.txt");
	if (inputFile.is_open() == false) {
		cout << "film is not open \n";
	}
	else
	{
		cout << "film is open \n";
		while (inputFile.eof() == false) {
			inputFile >> ID;
			inputFile >> filmName;
			Film film(ID);
			film.setName(filmName);
			Add(film);
		}
	}

	inputFile.close();
}


