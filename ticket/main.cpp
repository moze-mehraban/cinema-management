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
	aaaa.ReadFromFile();
	aaaa.Print();
	all.readfromfile();
	all.print();
	all.writetofile();

}