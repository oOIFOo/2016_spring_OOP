#ifndef __BOOKINGSYSTEM_H__
#define __BOOKINGSYSTEM_H__
#include<iostream>
#include<vector>
#include"Ticket.h"
#include"ConcertTicket.h"
#include"TrainTicket.h"

using namespace std;
class BookingSystem
{
public:
	BookingSystem();
	~BookingSystem();

	void run();
	void bookTicket();
	void cancelTicket();
	void showAllTicket();

private:
	vector<Ticket*> ticketData;
};

#endif
