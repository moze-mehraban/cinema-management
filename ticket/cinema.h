#pragma once
#include<iostream>
#include "Film2.h"

using namespace std;

class cinema {
private:
	string name;
	int price;
	int capacity;
	Film time[7][4];
	int id;
public:
	cinema();
	void setname(string);
	void setcap(int);
	string getname();
	int getcap();
	void settime(Film, int, int);
	void reserve(ticket);
	void setid(int i) { id = i; }
	int getid() { return id; }
	Film &getfilm(int, int);
	void setprice(int p) { price = p; }
	int getprice() { return price; }
	void movie_killer(int day, int sans) { time[day][sans] = Film() ; }
	void schedule();
	int income();
	int film_income(string);
};
