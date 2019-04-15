#include "Concert_Ticket.h"

Concert_Ticket::Concert_Ticket()
{
	cout << "you are booking  Concert ticket now" << endl;
	type = 1;
	price = 200;
}

Concert_Ticket::Concert_Ticket(Concert_Ticket* input)
{
	// copy input to this
	zone = input->zone;
	seat = input->seat;
	date.year = input->date.year;
	date.month = input->date.month;
	date.day = input->date.day;
}

Concert_Ticket::~Concert_Ticket()
{

}

void Concert_Ticket::operator=(const Concert_Ticket& input)
{
	// copy input to this
	type = input.type;
	zone = input.zone;
	seat = input.seat;
	date.year = input.date.year;
	date.month = input.date.month;
	date.day = input.date.day;
}

void Concert_Ticket::showInfo()
{
	// show the information of this ticket 
	cout << "type:" << endl;
	cout << type << endl;
	cout << "price:";
	cout << price << endl;
	cout << "chart number:" << endl;
	cout << zone << endl;
	cout << "seat number:" << endl;
	cout << seat << endl;
	cout << "start_time" << endl;
	cout << start_time.hour << ":";
	cout << start_time.minute << endl;
	cout << "date:" << endl;
	cout << date.year << "/";
	cout << date.month << "/";
	cout << date.day << endl;
}