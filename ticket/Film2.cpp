#include "Film2.h"
#include <iostream>
using namespace std;
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