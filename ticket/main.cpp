#include <iostream>
#include <fstream>
#include "ticket.h"
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
class alltickets {
private:
	int counter = 0, capacity;
	ticket* tickets;
public:
	alltickets(int cap);
	void addticket(ticket);
	void writetofile();
	void readfromfile();
	void print();
};
alltickets::alltickets(int cap) {
	capacity = cap;
	tickets = new ticket[cap];
}
void alltickets::addticket(ticket nex) {
	tickets [counter] = nex;
	counter++;
}
void alltickets::writetofile() {
	ofstream out;
	out.open("ticket.txt");
	for (int i = 0; i < counter; i++) {
		out << tickets[i].getid() << "\t" << tickets[i].getName()<<"\t"<<tickets[i].getfilmid()<<"\t";
		for (int j = 0; j < 5; j++) {
			out << tickets[i].resereved_chairs[j];
			if (j != 4) {
				out << "\t";
			}
		}
		if (i < (counter - 1)) {
			out << "\n";
		}
	}
	out.close();
}
void alltickets::readfromfile() {
	int ID;
	string Name;
	int film_id;
	ifstream inputFile;
	inputFile.open("ticket.txt");
	if (inputFile.is_open() == false) {
		cout << "ticket is not open \n";
	}
	else
	{
		cout << "ticket is open \n";
		while (inputFile.eof() == false) {
			inputFile >> ID;
			inputFile >>Name;
			inputFile >> film_id;
			int temp;
			ticket t;
			t.setname(Name);
			t.set_id(ID);
			t.setfilmid(film_id);
			for (int c = 0; c < 5; c++) {
				inputFile >> temp;
				if (temp != 0) {
					t.reserve(temp);
				}
			}
			addticket(t);
		}
	}
	
	inputFile.close();
}
void alltickets::print() {
	for (int i = 0; i < counter; i++) {
		cout << tickets[i].getid() << "\t" << tickets[i].getName() << "\t" << tickets[i].getfilmid() << "\t";
		for (int j = 0; j < 5; j++) {
			cout << tickets[i].resereved_chairs[j] << "\t";
		}
		if (i < (counter - 1)) {
			cout << "\n";
		}
	}
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