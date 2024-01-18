#pragma once
#include "ticket.h"
class Film {
private:
	int ID=-1;
	string name;
	bool* chairs;
	int cap;
	ticket *reserved;
	int tc=0;
public:
	Film();
	Film(int ID);
	void setName(string n) { name = n; }
	void setID(int);
	string getName() { return name; }
	int getID();
	void Print();
	void setchairs(int);
	int getcap() { return cap; }
	void reserve(ticket ticket);
	void printchairs();
	int gettc() { return tc; }
	ticket gettickets(int tn) { return reserved[tn]; }
};

