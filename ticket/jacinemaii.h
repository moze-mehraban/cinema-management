#pragma once
#include<vector>
#include "cinema.h"
#include "film2.h"
using namespace std;
class jacinemaii
{
private:
	vector<cinema> allcinema;
	
public:
	void addcinema(const cinema &next);
	void write();
	void read();

};

