#pragma once
#include "Film2.h"
class AllFilms {
private:
	Film* films;
	int Capacity;
	int numFilm;
public:
	AllFilms(int capacity);
	void Add(Film);
	void remove(int);
	void ReadFromFile();
	void WriteToFile();
	void Print();
};
