#include "Ticket.h"

Ticket::Ticket()
{

}

Ticket::~Ticket()
{

}

void Ticket::operator=(const Ticket& input)
{
	// copy input to this
	this->type = input.type;
	this->booking_ID = input.booking_ID;
	this->price = input.price;
	this->date.day = input.date.day;
	this->date.month = input.date.month;
	this->date.year = input.date.year;
}

void Ticket::showInfo()
{
	// show the information of this ticket 
	cout << "booking_ID is:";
	cout << booking_ID;
	cout << "price is:";
	cout << price<<endl;
	cout << "date.day is:";
	cout << date.day << endl;
	cout << "date.month  is:";
	cout << date.month << endl;
	cout << "date.year is:";
	cout << date.year << endl;
}