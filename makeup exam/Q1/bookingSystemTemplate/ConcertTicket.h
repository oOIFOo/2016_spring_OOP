#ifndef __CTICKET_H__
#define __CTICKET_H__
#include"Ticket.h"
#include<string>
#include<iostream>
using namespace std;
class ConcertTicket : public Ticket
{
public:
	ConcertTicket(){}
	~ConcertTicket(){}
	void inputInfo();
	void showInfo();
private:
	string name;
	string seat;
};


#endif