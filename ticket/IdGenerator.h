#pragma once
#include <fstream>
using namespace std;
class IdGenerator
{
private:
	int Tid;
	int Fid ;
	int Cid ;
public:
	int GetTId() { return Tid++; }
	int GetFId() { return Fid++; }
	int GetCId() { return Cid++; }
	~IdGenerator() {
		ofstream out;
		out.open("IDs.txt");
		out << Tid << "\t" << Fid << "\t" << Cid;
		out.close();
	}
	IdGenerator() {
		ifstream inputFile;
		inputFile.open("IDs.txt");
		if (inputFile.is_open() == false) {
			cout << "ID gen is not open \n";
		}
		else
		{
			cout << "ID gen is open \n";
			inputFile >> Tid;
			inputFile >> Fid;
			inputFile >> Cid;
			
		}

		inputFile.close();
	}
};


