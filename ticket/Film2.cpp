#include "Film2.h"
#include <iostream>
using namespace std;
void Film::setchairs(int cap) {
	this->cap = cap;
	chairs = new bool[cap];
	reserved = new ticket[cap];
	for (int i = 0; i < cap; i++) {
		chairs[i] = false;
	}
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
void Film::reserve(ticket ticket) {
	reserved[tc] = ticket;
	for (int i = 0; i < 5; i++) {
		if (ticket.resereved_chairs[i] != 0) {
			if (chairs[ticket.resereved_chairs[i] - 1] != true) {
				chairs[ticket.resereved_chairs[i] - 1] = true;
			}
		}
	}
	tc++;
}

void Film::printchairs()
{
	for (int i = 0; i < cap; i++) {
		if (chairs[i] == true) {
			cout << i + 1 << " ";
		}
	}
	cout << "\n";
}
