#pragma once
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

