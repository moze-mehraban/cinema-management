#include "cinema.h"
cinema::cinema() {

}
void cinema::settime(Film x, int day, int sans) {
	time[day][sans] = x;
	time[day][sans].setchairs(capacity);
}
void cinema::reserve(ticket t)
{
	int FilmId = t.getfilmid();
	bool run = true;
	for (int i = 0; i < 7&&run; i++) {
		for (int j = 0; j < 4&&run; j++) {
			if (time[i][j].getID() == FilmId) {
				time[i][j].reserve(t);
				time[i][j].printchairs();
				run=false;
			}
		}
	}
}
Film cinema::getfilm(int i, int j)
{
	return time[i][j];
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