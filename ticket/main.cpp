#include <iostream>
#include <fstream>
#include "ticket.h"
#include"alltickets.h"
#include "Film2.h"
#include "cinema.h"
#include "allfilms.h"
#include "IdGenerator.h"
#include "jacinemaii.h"
using namespace std;

int main() {
	/*AllFilms aaaa(20);
	alltickets all(50);
	cinema c;
	ticket t;
	Film f;
	IdGenerator Id;
	c.setcap(20);
	c.setname("nigga");
	c.setid(Id.GetCId());
	f.setID(1);
	f.setName("dalghak");
	t.setfilmid(1);
	t.setname("boooo");
	t.set_id(Id.GetTId());
	t.setcinemaid(1);
	t.reserve(11);
	t.reserve(10);
	all.addticket(t);
	c.settime(f, 1, 2);
	c.reserve(t);
	j.addcinema(c);
	j.write();
	all.print();
	all.writetofile();
	cout<<f.getName();*/
	
	jacinemaii j;
	j.read();
}