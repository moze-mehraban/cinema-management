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
	int getid();
	string getName();
};
ticket::ticket() {

}
void ticket::set_id(int id) {
	ticket_id = id;
}
string ticket::getName(){
	return name;
}
int ticket::getid() {
	return ticket_id;
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
	ofstream out;
	out.open("ticket.txt");
	for (int i = 0; i < counter; i++) {
		out << tickets[i].getid() << "\t" << tickets[i].getName()
			<< endl;
	}
	out.close();
}
void main() {
	alltickets all(50);
	ticket t1;
	t1.setname("mamad");
	t1.set_id(1);
	all.addticket(t1);
	all.writetofile();
}
