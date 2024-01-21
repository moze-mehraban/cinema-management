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
		cout << "5 : leaderboard " << endl;
		cout << "6 : save :D " << endl;
		cout << "7 : exit " << endl;


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
			leaderboard();
		}
		else if (inp == 6) {
			j.write();
		}
		else if (inp == 7) {
			return;
		}
		else {
			menu();
		}
	}
}

void ui:: reservation()
{
	int inp,cid;
	int day, sans;
	int chaircount;
	system("cls");
	j.printall();
	cout << "\n enter cinema id : ";
	cin >> cid;
	system("cls");
	j.cinema_schedule(cid);
	cout << "enter day: ";
	cin >> day;
	cout << "enter start time ([0 for 9:00][1 for 11:00][2 for 15:00][3 for 17:00]) :\n ";
	cin >> sans;
	cout << "enter chairs count(1-5) :";
	cin >> chaircount;
	if (chaircount > 5) {
		cout << "impossible !";
	}
	else if (chaircount > j.getcinema(cid).getfilm(day, sans).freecounter()) {
		cout << "over capacity ! ";
	}
	else {
		cout << "free chairs: ";
		j.getcinema(cid).getfilm(day, sans).printfreechairs();
		ticket t;
		t.set_id(idgen.GetTId());
		cout << "enter name : ";
		string tn;
		cin >> tn;
		t.setname(tn);
		t.setcinemaid(cid);
		t.setfilmid(j.getcinema(cid).getfilm(day, sans).getID());
		for (int i = 0; i < chaircount; i++) {
			int chair;
			cout << "chose a chair : ";
			cin >> chair;
			if (j.getcinema(cid).getfilm(day, sans).freecheck(chair)) {
				if (chair > 0 && chair <= j.getcinema(cid).getcap()) {
					t.reserve(chair);
				}
				else {
					cout << "out of range!!\n";
						i--;
				}
			}
			else {
				cout << "chair not free , try again \n";
				i--;
			}
			
		}
		j.reserve(t);
		cout << "enter a number to continue : ";
		cin >> inp;
		
	}
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
	cout << "enter ticket id : ";
	cin >> inp;
	j.ticket_finder(inp);
	cout << " enter sth : ";
	string inp2;
	cin >> inp2;





}

void ui::registeration()
{
	system("cls");
	int inp;
	cout << "1 : create cinema " << endl;
	cout << "2 : create or change movie" << endl;
	cout << "3 : main menu " << endl;
	cin >> inp;
	if (inp == 1) {
		system("cls");
		cinema c;
		string cinema_name;
		c.setid(idgen.GetCId());
		cout << "enter cinema name :";
		cin >> cinema_name;
		c.setname(cinema_name);
		int cap,price;
		cout << "enter cinema capacity : ";
		cin >> cap;
		c.setcap(cap);
		cout << "enter ticket price :";
		cin >> price;
		c.setprice(price);
		j.addcinema(c);
		cout << "cinema created :)"<<endl;
		cout << "enter a number to continue :";
		cin >> inp;

	}
	else if (inp == 2) {
		system("cls");
		j.printall();
		int cid;
		int day, sans;
		cout << "enter cinema id : ";
		cin >> cid;
		j.cinema_schedule(cid);
		cout << "enter day: ";
		cin >> day;
		cout << "enter start time ([0 for 9:00][1 for 11:00][2 for 15:00][3 for 17:00]) :\n ";
		cin >> sans;
		string movie_name;
		cout << "enter movie name  : ";
		cin>>movie_name;
		Film f;
		f.setName(movie_name);
		f.setID(idgen.GetFId());
		j.getcinema(cid).settime(f, day, sans);
		system("cls");
		cout << "movie set <3" << endl<<"enter a number to continue :";
		cin >> inp;
	
		
	}
	else if (inp == 3) {
		return;
	}




}

void ui::leaderboard()
{
	system("cls");
	int inp;
	cout << "1 : income by cinema " << endl;
	cout << "2 : income by movie " << endl;
	cout << "3 : most seller cinema  " << endl;
	cout << "4 : most seller movie " << endl;
	cout << "5 : most popular time of week  " << endl;


	cin >> inp;


	if (inp == 1) {
		system("cls");
		j.printall();
		cout << endl;
		cout << "enter cinema id :";
		int cid;
		cin >> cid;
		cout<<"cinema income :  " << j.income(cid) << endl;
		cout << "enter a number to return :";
		cin >> inp;
	}
	else if (inp==2) {
		system("cls");
		j.allFilm();
		cout << "enter movie name : ";
		string name;
		cin >> name;
		system("cls");
		cout << "1 : for all cinemas \n";
		cout << "2 : search with id   \n";
		cin >> inp;
		if (inp == 1) {
			cout << "movie income at all : " << j.film_income(name) << endl
				<<"enter a number to continue :";
			cin >> inp;
			
		}
		else if (inp == 2) {
			system("cls");
			j.printall();
			cout << "enter cinema id :";
			int cid;
			cin >> cid;
			cout << "income for movie " << name << " : " << j.film_income(cid, name)<<endl
				<< "enter a number to continue :";
			cin >> inp;
		}
	}
	else if(inp==3){
		system("cls");
		int mscId = j.most_seller();
		cout << " most seller is " << j.getcinema(mscId).getname() << "\ntotal income : " << j.getcinema(mscId).income() << endl;
		cout << "enter a number to continue :";
		cin >> inp;


	}
	else if(inp == 4) {
		system("cls");
		cout << "most seller movie is : " << j.mostsellermovie() << endl;
		cout << "total income :" << j.film_income(j.mostsellermovie())<<endl;
		cout << "enter a number to continue :";
		cin >> inp;
	}
	else if (inp == 5) {
		system("cls");
		j.popular();
		cout << "enter a number to continue :";
		cin >> inp;
	}
}
