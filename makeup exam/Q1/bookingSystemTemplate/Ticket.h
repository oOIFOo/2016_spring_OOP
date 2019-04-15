#ifndef __TICKET_H__
#define __TICKET_H__
#include<string>
using namespace std;

class Ticket
{
public:
	Ticket(){}
	~Ticket(){}
	virtual void inputInfo() = 0;
	virtual void showInfo() = 0;
};

#endif