#include"alltickets.h"
#include <fstream>
alltickets::alltickets(int cap) {
	capacity = cap;
	tickets = new ticket[cap];
}
void alltickets::addticket(ticket nex) {
	tickets[counter] = nex;
	counter++;
}
void alltickets::writetofile() {
	ofstream out;
	out.open("ticket.txt");
	for (int i = 0; i < counter; i++) {
		out << tickets[i].getid() << "\t" << tickets[i].getName() << "\t" << tickets[i].getfilmid() << "\t";
		for (int j = 0; j < 5; j++) {
			out << tickets[i].resereved_chairs[j];
			if (j != 4) {
				out << "\t";
			}
		}
		if (i < (counter - 1)) {
			out << "\n";
		}
	}
	out.close();
}
void alltickets::readfromfile() {
	int ID;
	string Name;
	int film_id;
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
			inputFile >> Name;
			inputFile >> film_id;
			int temp;
			ticket t;
			t.setname(Name);
			t.set_id(ID);
			t.setfilmid(film_id);
			for (int c = 0; c < 5; c++) {
				inputFile >> temp;
				if (temp != 0) {
					t.reserve(temp);
				}
			}
			addticket(t);
		}
	}

	inputFile.close();
}
void alltickets::print() {
	for (int i = 0; i < counter; i++) {
		cout << tickets[i].getid() << "\t" << tickets[i].getName() << "\t" << tickets[i].getfilmid() << "\t";
		for (int j = 0; j < 5; j++) {
			cout << tickets[i].resereved_chairs[j] << "\t";
		}
		if (i < (counter - 1)) {
			cout << "\n";
		}
	}
}

ticket alltickets::getticket(int index)
{
	return tickets[index];
}
