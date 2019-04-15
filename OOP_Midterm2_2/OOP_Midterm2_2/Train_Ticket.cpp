#include "Train_Ticket.h"

Train_Ticket::Train_Ticket()
{
	cout << "you are booking train ticket now" << endl;
	type = 0;
	price = 100;
}

Train_Ticket::Train_Ticket(const Train_Ticket* input)
{	
	// copy input to this
	cart = input->cart;
	seat = input->seat;
	departure_time.hour = input->departure_time.hour;
	departure_time.minute = input->departure_time.minute;
	origin = input->origin;
	destination = input->destination;
	date.year = input->date.year;
	date.month = input->date.month;
	date.day = input->date.day;
}

Train_Ticket::~Train_Ticket()
{ 

}

void Train_Ticket::operator=(const Train_Ticket& input)
{
	// copy input to this
	type = input.type;
	cart = input.cart;
	seat = input.seat;
	departure_time.hour = input.departure_time.hour;
	departure_time.minute = input.departure_time.minute;
	origin = input.origin;
	destination = input.destination;
	date.year = input.date.year;
	date.month = input.date.month;
	date.day = input.date.day;
}

void Train_Ticket::showInfo()
{
	// show the information of this ticket
	cout << "type:" << endl;
	cout << type << endl;
	cout << "price:";
	cout << price << endl;
	cout << "chart number:" << endl;
	cout << cart << endl;
	cout << "seat number:" << endl;
	cout << seat << endl;
	cout << "departure time:" << endl;
	cout << departure_time.hour << ":";
	cout << departure_time.minute << endl;
	cout << "arrival time:" << endl;
	cout << arrival_time.hour << ":" << endl;
	cout << arrival_time.minute << endl;
	cout << "start station:" << endl;
	cout << origin << endl;
	cout << "destination:" << endl;
	cout << destination << endl;
	cout << "date:" << endl;
	cout << date.year << "/";
	cout << date.month << "/";
	cout << date.day << endl;
}