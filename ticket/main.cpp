#include <iostream>
#include <fstream>
#include "ticket.h"
#include"alltickets.h"
using namespace std;
class Film {
private:
	int ID;
	char name[30];
	bool* chairs;
public:
	Film();
	Film(int ID);
	void setName(char[]);
	void setID(int);
	char* getName();
	int getID();
	void Print();
	void setchairs(int);
};
char* Film::getName() {
	return name;
}
void Film::setchairs(int cap) {

}
int Film::getID() {
	return ID;
}
void Film::Print() {
	cout << ID << "\t" << name << endl;
}
Film::Film() {

}
void Film::setID(int id) {
	this->ID = id;
}
Film::Film(int ID) {
	this->ID = ID;
}
void Film::setName(char n[]) {
	int i = 0;
	for (i = 0; n[i] != '\0'; i++)
		name[i] = n[i];
	name[i] = '\0';
}
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


class cinema {
private:
	string name;
	int price;
	int capacity;
	Film time[7][4];
public:
	cinema();
	void setname(string);
	void setcap(int);
	string getname();
	int getcap();
	void settime(Film, int, int);
};
cinema::cinema() {
	
}
void cinema :: settime(Film x, int day, int sans) {
	time[day][sans] = x;
	time[day][sans].setchairs(capacity);
}
void cinema::setcap(int cap) {
	capacity = cap;
}
void cinema::setname(string name) {
	this->name = name;
}
int cinema::getcap() {
	return capacity;
}
string cinema::getname() {
	return name;
}
int main() {
	AllFilms aaaa(20);
	alltickets all(50);
	aaaa.ReadFromFile();
	aaaa.Print();
	all.readfromfile();
	all.print();
	all.writetofile();
	all.print();
}