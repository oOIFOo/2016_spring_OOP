#include"TrainTicket.h"

void TrainTicket::inputInfo(){
	cout << "name:" << endl;
	cin >> name;
	cout << "year:" << endl;
	cin >> year;
	cout << "month:" << endl;
	cin >> month;
	cout << "day:" << endl;
	cin >> day;
}

void TrainTicket::showInfo(){
	cout << "ticket type: TrainTicket" << endl;
	cout << "name:" << name << endl;
	cout << "year:" << year << endl;
	cout << "month:" << month << endl;
	cout << "day:" << day << endl;
}