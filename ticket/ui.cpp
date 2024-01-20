#include"ui.h"
#include<cstdlib>
#include<iostream>
using namespace std;
ui::ui() {
	j.read();
	menu();
}
void ui:: menu() {
	while(true){
		system("cls");
		int inp;
		cout << "1 : reservation " << endl;
		cout << "2 : finder " << endl;
		cout << "3 : killer " << endl;
		cout << "4 : registeration" << endl;
		cout << "5 : exit " << endl;


		cin >> inp;
		if (inp == 1) {
			reservation();
		}
		else if (inp == 2) {
			finder();
		}
		else if (inp == 3) {
			killer();
		}
		else if (inp == 4) {
			registeration();
		}
		else if (inp == 5) {
			return;
		}
		else {
			menu();
		}
	}
}

void ui:: reservation()
{
	system("cls");
	
	menu();
}

void ui::killer()
{
	int inp;
	system("cls");
	cout << "1 : cinema killer \n";
	cout << "2 : movie killer \n";
	cout << "3 : ticket killer \n";
	cout << "4 : main menu \n";
	cin >> inp;
	 if (inp == 1) {
		 system("cls");
		 j.printall();
		 cout << "select number ( -1 for last menu ) : ";
		 cin >> inp;
		 if (inp == -1) {
			 return;
		 }
		 else {
			 j.cinema_killer(inp);
		 }
	}
	 else if (inp == 2) {
		system("cls");
		j.allFilm();
		string s_inp;
		cout << "enter name to remove ( 0 for return ) : ";
		cin >> s_inp;
		if (s_inp == "0") {
			killer();
		}
		else {
			j.movie_killer(s_inp);
		}


	 }
	 else if (inp == 3) {
		 system("cls");
		 int tid;
		 cout << "enter ticket id :";
		 cin >> tid;
		 j.ticket_killer(tid);
	 }
	 else if (inp == 4) {
		 return;
	 }
	 else {

	 }
	
}
void ui::finder() 
{
	system("cls");
	int inp;






}

void ui::registeration()
{
	system("cls");
	int inp;




}
