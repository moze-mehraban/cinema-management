#include <iostream>
#include <fstream>
using namespace std;
class ticket {
private:
	string name;
	int ticket_id;
public:
	ticket();
	void set_id(int );
	void setname(string);
};
ticket::ticket() {

}
void ticket::set_id(int id) {
	ticket_id = id;
}
void ticket::setname(string n) {
	name = n;
}
class alltickets {
private:
	int counter = 0, capacity;
	ticket* tickets;
public:
	alltickets(int cap);
	void addticket(ticket);
	void writetofile();
	
};
alltickets::alltickets(int cap) {
	capacity = cap;
	tickets = new ticket[cap];
}
void alltickets::addticket(ticket nex) {
	tickets [counter] = nex;
	counter++;
}
void alltickets::writetofile() {
	
}
void main() {
	alltickets all(50);
	ticket t1;
	t1.setname("mamad");
	t1.set_id(1);
	all.addticket(t1);
}
