#pragma once
#include "ticket.h"
class Film {
private:
	int ID;
	char name[30];
	bool* chairs;
	int cap;
	ticket *reserved;
	int tc=0;
public:
	Film();
	Film(int ID);
	void setName(char[]);
	void setID(int);
	char* getName();
	int getID();
	void Print();
	void setchairs(int);
	int getcap() { return cap; }
	void reserve(ticket ticket);
	void printchairs();
};

