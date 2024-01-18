#include "ticket.h"
ticket::ticket() {
	for (int i = 0; i < 5; i++) {
		resereved_chairs[i] = 0;
	}
}
void ticket::setfilmid(int id) {
	film_id = id;
}
void ticket::setcinemaid(int c)
{
	cinema_id = c;
}
int ticket::getcinemaid()
{
	return cinema_id;
}
void ticket::reserve(int chairnumber) {
	resereved_chairs[chairscount] = chairnumber;
	chairscount++;
}
int ticket::getfilmid() {
	return film_id;
}
void ticket::set_id(int id) {
	ticket_id = id;
}
string ticket::getName() {
	return name;
}
int ticket::getid() {
	return ticket_id;
}
void ticket::setname(string n) {
	name = n;
}
