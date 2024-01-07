#include <iostream>
#include <fstream>
#include "ticket.h"
#include"alltickets.h"
#include "Film2.h"
#include "cinema.h"
#include "allfilms.h"

using namespace std;

int main() {
	AllFilms aaaa(20);
	alltickets all(50);
	char name[7] = { 'd', 'a', ' l', 'g', ' h', 'a', 'k' };
	cinema c;
	ticket t;
	Film f;
	f.setID(1);
	f.setName(name);
	f.setchairs(20);
	t.setfilmid(1);
	t.setname("boooo");
	t.set_id(1);
	t.reserve(10);
	f.reserve(t);
	f.printchairs();
}