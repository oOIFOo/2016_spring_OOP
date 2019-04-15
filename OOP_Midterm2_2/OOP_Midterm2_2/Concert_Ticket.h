#ifndef _CONCERT_TICKET_H_
#define _CONCERT_TICKET_H_
#include "Structure.h"
#include "Ticket.h"
#include <string>

using namespace std;

class Concert_Ticket : public Ticket
{
public:

	Concert_Ticket();
	Concert_Ticket(Concert_Ticket* input);
	~Concert_Ticket();

	void showInfo();

	void operator=(const Concert_Ticket& input);

public:
	int zone;
	int seat;
	Time start_time;
	int type;
	Date date;
	int price;
};

#endif