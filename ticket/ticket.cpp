#include <iostream>
#include <fstream>
using namespace std;
class ticket {
private:
	string name;
	int ticket_id;
	int film_id;
	int resereved_chairs[5];
public:
	ticket();
	void set_id(int );
	void setname(string);
	int getid();
	string getName();
};
ticket::ticket(){
	for (int i = 0; i < 5; i++) {
		resereved_chairs[i] = 0;
	}
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
	void readfromfile();
	void print();
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
		out << tickets[i].getid() << "\t" << tickets[i].getName();
		if (i < (counter - 1)) {
			out << "\n";
		}
	}
	out.close();
}
void alltickets::readfromfile() {
	int ID;
	string Name;
	ifstream inputFile;
	inputFile.open("ticket.txt");
	if (inputFile.is_open() == false) {
		cout << "ticket is not open \n";
	}
	else
	{
		cout << "ticket is open \n";
		while (inputFile.eof() == false) {
			inputFile >> ID;
			inputFile >>Name;
			ticket t;
			t.setname(Name);
			t.set_id(ID);
			addticket(t);
		}
	}
	
	inputFile.close();
}
void alltickets::print() {
	for (int i = 0; i < counter; i++) {
		cout << tickets[i].getid() << "\t" << tickets[i].getName() << endl;
	}
}
int main() {
	alltickets all(50);
	all.readfromfile();
	all.print();
	all.writetofile();
}
