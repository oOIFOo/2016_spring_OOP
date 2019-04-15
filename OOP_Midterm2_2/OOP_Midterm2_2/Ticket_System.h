#ifndef _TICKET_SYSTEM_H_
#define _TICKET_SYSTEM_H_
#include <iostream>
#include <sstream>
//#include <vector>
#include "Train_Ticket.h"
#include "Concert_Ticket.h"
#include "Hotel_Ticket.h"
#include "Ticket_Database.h"

using namespace std;

class Ticket_System
{
public:

	Ticket_System();
	~Ticket_System();

	void Initialize();

	// select the option
	void run(); 

	// operation one: booking the ticket
	void start_booking();
	
	int choose_type();
	void book_ticket(int ticket_type);
	bool enter_information(Train_Ticket *src);
	bool enter_information(Concert_Ticket *src);
	bool enter_information(Hotel_Ticket *src);
	int generate_booking_ID();

	// operation two: cancel the booking
	void cancel_booking();

	// operation three: search the booking
	void search_booking();
	void show_ticket_information(int index);
	void copy_booking(int ID);
	
	// operation four: print the booking that saved in local device
	void print_booking();


public:
	// ticket information that saved in personal device
	Concert_Ticket *c_ticket;
	Train_Ticket *t_ticket;
	Hotel_Ticket *h_ticket;

	// ticket information that saved in the ticket database
	Ticket_Database<Ticket*> m_database;
	int train;
	int hotel;
	int concert;
	
	// ticket's booking id list
	Ticket_Database<int> booking_ID_list;
	int id;
};

#endif