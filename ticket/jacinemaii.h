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
	void ticket_killer(int tid);
	void cinema_killer(int cid);
	void movie_killer(string name);
	void cinema_schedule(int cid);
	void ticket_finder(int tid);
	void reserve(ticket t);
	void printall();
	void allFilm();
	cinema& getcinema(int cid);
	int income(int cid);
	int film_income(string);
	int film_income(int , string);
	int most_seller();
	string mostsellermovie();
	void popular();
};

