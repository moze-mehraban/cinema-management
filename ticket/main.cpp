#include <iostream>
#include <fstream>
#include "ticket.h"
#include"alltickets.h"
#include "Film2.h"
#include "cinema.h"
#include "allfilms.h"
#include "IdGenerator.h"
using namespace std;

int main() {
	AllFilms aaaa(20);
	alltickets all(50);
	char name[7] = { 'd', 'a', ' l', 'g', ' h', 'a', 'k' };
	cinema c;
	ticket t;
	Film f;
	IdGenerator Id;
	c.setcap(20);
	c.setname("nigga");
	f.setID(1);
	f.setName(name);
	t.setfilmid(1);
	t.setname("boooo");
	t.set_id(Id.GetTId());
	t.setcinemaid(1);
	t.reserve(11);
	t.reserve(10);
	all.addticket(t);
	c.settime(f, 1, 2);
	c.reserve(t);
	all.print();
	all.writetofile();

}