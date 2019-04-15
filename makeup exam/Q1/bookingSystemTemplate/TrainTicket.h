#ifndef __TTICKET_H__
#define __TTICKET_H__

#include<iostream>
#include"Ticket.h"
using namespace std;

class TrainTicket : public Ticket
{
public:
	TrainTicket(){}
	~TrainTicket(){}
	void inputInfo();
	void showInfo();
private:
	string name;
	int year;
	int month;
	int day;
};

#endif