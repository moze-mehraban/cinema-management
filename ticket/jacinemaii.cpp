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
		out<<'c'<<"\t" << c.getid() << "\t" << c.getname() << "\t" << c.getcap()<<"\t" << c.getprice() << endl;
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
	out << 's';
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
			int id, cap, price;
			string name;
			inp >> id;
			inp >> name;
			inp >> cap;
			inp >> price;
			cinema c;
			c.setid(id);
			c.setcap(cap);
			c.setname(name);
			c.setprice(price);
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
		else if (type == 's') {
			break;
		}
	}
	inp.close();
}

void jacinemaii::ticket_killer(int tid)
{
	for (cinema &c : allcinema) {
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < c.getfilm(i, j).gettc(); k++) {
					if (c.getfilm(i, j).gettickets(k).getid() == tid) {
						c.getfilm(i, j).ticket_killer(k);
					}
				}
			}
		}
	}
}

void jacinemaii::cinema_killer(int cid)
{
	int index = 0;
	for (cinema &c : allcinema) {
		if (c.getid() == cid) {
			allcinema.erase(allcinema.begin() + index);
		}
		index++;
	}
}

void jacinemaii::movie_killer(string name)
{
	for ( cinema &c : allcinema) {
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 4; j++) {
				if (c.getfilm(i, j).getName() == name) {
					c.movie_killer(i, j);
				}
			}
		}
	}
}

void jacinemaii::cinema_schedule(int cid)
{
	for (cinema& c : allcinema) {
		if (c.getid() == cid) {
			c.schedule();
		}
	}
}

void jacinemaii::ticket_finder(int tid)
{
	string days[7] = { "shanbe","yek shanbe","doshanbe","seshanbe","chahar shanbe","panj shanbe","jomee" };
	string times[4] = { "09:00" ,"11:00","15:00","17:00" };
	for (cinema c : allcinema) {
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < c.getfilm(i, j).gettc(); k++) {
					if (c.getfilm(i, j).gettickets(k).getid() == tid) {
						cout <<"cinema : " << c.getname() << "\t" << "day : " << days[i] << "\t" << "start time : " 
							<<times[j]<< "\t" << "filme :" << c.getfilm(i, j).getName() << endl;
						cout << "chairs : ";
						for (int l=0 ;l<5;l++){
							if (c.getfilm(i, j).gettickets(k).resereved_chairs[l]!=0){
								cout << c.getfilm(i, j).gettickets(k).resereved_chairs[l]<<" ";
							}
						}
						cout << endl;
					}
				}
			}
		}
	}
}

void jacinemaii::reserve(ticket t)
{
	bool premission = true;
	int cid=t.getcinemaid(), fid=t.getfilmid();
	string name = t.getName();
	int day=-1, sans=-1;
	for (cinema c : allcinema) {
		if (c.getid() == cid) {
			for (int i = 0; i < 7; i++) {
				for (int j = 0; j < 4; j++) {
					if (c.getfilm(i, j).getID() == fid) {
						day = i;
						sans = j;
					
					}
				}
			}
		}
	}
	for (cinema c : allcinema) {
		for (int i = 0; i < c.getfilm(day, sans).gettc(); i++) {
			if (c.getfilm(day, sans).gettickets(i).getName() == name&&cid!=c.getid()) {
				premission = false;
				break;
			}
		}

	}
	if (premission) {
		for (cinema c : allcinema) {
			if (c.getid() == cid) {
				c.getfilm(day, sans).reserve(t);
				break;
			}
		}
		
	}
}

void jacinemaii::printall()
{
	for (cinema c : allcinema) {
		cout << c.getid() << " " << c.getname()<<endl;
	}
}

void jacinemaii::allFilm()
{
	vector<string> all;
	for (cinema c : allcinema) {
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 4; j++) {
				string name = c.getfilm(i, j).getName();
				bool prem = true;
				for (string s : all) {
					if (name == s) {
						prem = false;
					}
				}
				if (prem) {
					all.push_back(name);
				}
			}
		}
	}
	int c = 1;
	for (string s : all) {
		if (s != "")
		{
			cout << c++ << " : " << s << endl;
		}
	}
}
