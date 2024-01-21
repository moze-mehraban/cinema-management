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
Film &cinema::getfilm(int i, int j)
{
	return time[i][j];
}
void cinema::schedule()
{
	int timetable[4] = { 9,11,15,17 };
	for (int i = 0; i < 7; i++) {
		cout << "day: " << i<<"\t";
		for (int j = 0; j < 4; j++) {
			cout << timetable[j] << ":00 ";
			if (time[i][j].getID()!=-1) {
				cout << time[i][j].getName() << " : " << time[i][j].freecounter() << "\t\t";
			}
			else {
				cout << "\t\t";
			}
		}
		cout << endl;
	}
}
int cinema::income()
{
	int income=0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 4; j++) {
			if (getfilm(i,j).getID()!=-1) {
				income += (capacity - getfilm(i, j).freecounter()) * price;
			}
		}
	}
	return income;
}
int cinema::film_income(string name)
{
	int income = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 4; j++) {
			if (getfilm(i, j).getName()==name) {
				income += (capacity - getfilm(i, j).freecounter()) * price;
			}
		}
	}
	return income;
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