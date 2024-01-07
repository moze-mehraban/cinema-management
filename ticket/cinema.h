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
public:
	cinema();
	void setname(string);
	void setcap(int);
	string getname();
	int getcap();
	void settime(Film, int, int);
	void reserve(ticket);
};
