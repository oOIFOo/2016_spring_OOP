#include"ConcertTicket.h"

void ConcertTicket::inputInfo(){
	cout << "name:" << endl;
	cin >> name;
	cout << "seat:" << endl;
	cin >> seat;
}

void ConcertTicket::showInfo(){
	cout << "ticket type: ConcertTicket" << endl;
	cout << "name:" << name << endl;
	cout << "seat:" << seat <<endl;
}