#include "cinema.h"
cinema::cinema() {

}
void cinema::settime(Film x, int day, int sans) {
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