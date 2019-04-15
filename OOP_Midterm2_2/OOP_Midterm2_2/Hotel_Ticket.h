#ifndef _HOTEL_TICKET_H_
#define _HOTEL_TICKET_H_
#include "Structure.h"
#include "Ticket.h"
#include <string>

using namespace std;

class Hotel_Ticket : public Ticket
{
public:

	Hotel_Ticket();
	Hotel_Ticket(Hotel_Ticket* input);
	~Hotel_Ticket();

	void showInfo();

	void operator=(const Hotel_Ticket& input);

public:
	bool breakfast;
	bool dinner;
	int room_number;
	int type;
	int price;
};

#endif