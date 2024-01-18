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
				out << 'f' << "\t" << f.getID() << "\t" << f.getName() << "\t" << i << "\t" << j<<endl;
			}
		}
	}
}

void jacinemaii::read()
{
}
