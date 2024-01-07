#pragma once
#include <iostream>
using namespace std;
class ticket {
private:
	string name;
	int ticket_id;
	int film_id;
	int chairscount = 0;
public:
	ticket();
	void set_id(int);
	void setname(string);
	int getid();
	string getName();
	int resereved_chairs[5];
	int getfilmid();
	void reserve(int chairnumber);
	void setfilmid(int);

};