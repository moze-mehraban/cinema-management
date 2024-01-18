#include "jacinemaii.h"
#include<fstream>
void jacinemaii::addcinema(const cinema& next)
{
	allcinema.push_back(next);
}

void jacinemaii::write()
{
	ofstream out("cinema.txt");

	for (cinema c : allcinema) {
		out<<'c'<<"\t" << c.getid() << "\t" << c.getname() << "\t" << c.getcap() << endl;
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 4; j++) {
				Film f = c.getfilm(i, j);
				if (f.getID() != -1) {
					out << 'f' << "\t" << f.getID() << "\t" << f.getName() << "\t" << i << "\t" << j << endl;
					for (int k = 0; k < f.gettc(); k++) {
						ticket t = f.gettickets(k);
						out << "t\t" << t.getid() << "\t" << t.getName() << "\t" << t.getcinemaid() << "\t" << t.getfilmid();
						for (int l = 0; l < 5; l++) {
							out << "\t" << t.resereved_chairs[l];
						}
						out << endl;
					}
				}
			}
		}
	}
	out.close();
}

void jacinemaii::read()
{
	ifstream inp("cinema.txt");
	int activec=-1;
	int activefd=0;
	int activefs=0;

	while (!inp.eof()) {
		char type;
		inp >> type;
		if (type == 'c') {
			int id,cap;
			string name;
			inp >> id;
			inp >> name;
			inp >> cap;
			cinema c;
			c.setid(id);
			c.setcap(cap);
			c.setname(name);
			addcinema(c);
			activec++;

		}
		else if (type == 'f') {
			int id, day, sans;
			string name;
			inp >> id;
			inp >> name;
			inp >> day;
			inp >> sans;
			allcinema[activec].getfilm(day, sans).setID(id);
			allcinema[activec].getfilm(day, sans).setName(name);
			allcinema[activec].getfilm(day, sans).setchairs(allcinema[activec].getcap());
			activefd = day;
			activefs = sans;

			
		}
		else if (type == 't') {
			int id, cid, fid, chair;
			string name;
			inp >> id;
			inp >> name;
			inp >> cid;
			inp >> fid;
			ticket t;
			t.setname(name);
			t.set_id(id);
			t.setcinemaid(cid);
			t.setfilmid(fid);
			for (int i = 0; i < 5; i++) {
				inp >> chair;
				t.reserve(chair);
			}
			allcinema[activec].getfilm(activefd, activefs).reserve(t);
		}

	}
	inp.close();
}
