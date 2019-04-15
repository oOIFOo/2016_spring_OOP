#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

#define TICKET_TRAIN 0
#define TICKET_CONCERT 1
#define TICKET_HOTEL 2

#include <iostream>
#include <string>

using namespace std;

struct Date
{
	int year;
	int month;
	int day;
	// operator overloading for =
	// operator overloading for <<
};

struct Time
{
	int hour;
	int minute;
	// operator overloading for =
	// operator overloading for <<
};


#endif