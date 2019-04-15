#ifndef _TICKET_H_
#define _TICKET_H_
#include "Structure.h"

using namespace std;

class Ticket
{
public:
	Ticket();
	~Ticket();

	virtual void showInfo();

	virtual void operator=(const Ticket& input);

public:
	int booking_ID;
	int type;
	int price;
	Date date;
};

#endif