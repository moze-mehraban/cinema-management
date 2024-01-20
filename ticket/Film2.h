#pragma once
#include "ticket.h"
#include <vector>
class Film {
private:
	int ID=-1;
	string name;
	bool* chairs;
	int cap;
	vector<ticket> reserved;
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
	int gettc() { return reserved.size(); }
	ticket gettickets(int tn) { return reserved[tn]; }
	void ticket_killer(int);
	int freecounter();
	void printfreechairs();
	bool freecheck(int);
};

