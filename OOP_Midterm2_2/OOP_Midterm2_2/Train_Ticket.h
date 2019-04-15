#ifndef _TRAIN_TICKET_H_
#define _TRAIN_TICKET_H_
#include "Structure.h"
#include "Ticket.h"
#include <string>

using namespace std;

class Train_Ticket : public Ticket
{
public:

	Train_Ticket();
	Train_Ticket(const Train_Ticket* input);
	~Train_Ticket();

	void showInfo();
	
	void operator=(const Train_Ticket& input);

	friend ostream& operator<<(ostream& os, const Train_Ticket& input);

public:
	int seat;
	int cart;
	Time departure_time;
	Time arrival_time;
	string origin;
	string destination;
	Date date;
	int type;
	int price;
};


#endif