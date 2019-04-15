#include "Hotel_Ticket.h"

Hotel_Ticket::Hotel_Ticket()
{
	cout << "you are booking Hotel ticket now" << endl;
	type = 2;
	price = 300;
}

Hotel_Ticket::Hotel_Ticket(Hotel_Ticket* input)
{
	// copy input to this
	breakfast = input->breakfast;
	dinner = input->dinner;
	room_number = input->room_number;
}

Hotel_Ticket::~Hotel_Ticket()
{

}

void Hotel_Ticket::operator=(const Hotel_Ticket& input)
{
	// copy input to this
	type = input.type;
	breakfast = input.breakfast;
	dinner = input.dinner;
	room_number = input.room_number;
}

void Hotel_Ticket::showInfo()
{
	// show the information of this ticket 
	cout << "type:" << endl;
	cout << type << endl;
	cout << "price:";
	cout << price << endl;
	cout << "breakfast:" << endl;
	if (breakfast == true){
		cout << "yes" << endl;
	}
	else{
		cout << "no" << endl;
	}
	cout << "dinner:" << endl;
	if (dinner == true){
		cout << "yes" << endl;
	}
	else{
		cout << "no" << endl;
	}
	cout << "room_number:" << endl;
	cout << room_number << endl;
}