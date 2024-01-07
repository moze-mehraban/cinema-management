#pragma once
#include "ticket.h"
class alltickets {
private:
	int counter = 0, capacity;
	ticket* tickets;
public:
	alltickets(int cap);
	void addticket(ticket);
	void writetofile();
	void readfromfile();
	void print();
};
