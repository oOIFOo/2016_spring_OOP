#include "BookingSystem.h"

BookingSystem::BookingSystem(){
	cout << "welcome!\n";
}
BookingSystem::~BookingSystem(){
	
}
void BookingSystem::bookTicket(){
	TrainTicket *train;
	ConcertTicket *concert;
	train = new TrainTicket;
	concert = new ConcertTicket;
	int x;
	cout << "1.train ticket   2.concert ticket" << endl;
	cin >> x;
	switch (x)
	{
	case 1:
		train->inputInfo();
		ticketData.push_back(train);
		break;
	case 2:
		concert->inputInfo();
		ticketData.push_back(concert);
		break;
	default:
		break;
	}
}
void BookingSystem::cancelTicket(){
	int x;
	cout << "input the delete data" << endl;
	cin >> x;
	if (x >= ticketData.size()){
		cout << "out of range" << endl;
		return;
	}
	if (ticketData[x] == NULL){
		cout << "out of range" << endl;
		return;
	}
	ticketData.erase(ticketData.begin() + x);
	cout << "success" << endl;
}
void BookingSystem::showAllTicket(){
	int size;
	size = ticketData.size();
	for (int i = 0; i < size; i++){
		cout << "index:" << i << endl;
		ticketData[i]->showInfo();
	}
}
void BookingSystem::run(){
	int selection=0;
	while (selection!=4)
	{
		cout << "1. booking\n";
		cout << "2. show all tickets\n";
		cout << "3. delete\n";
		cout << "4. exit\n";
		cin >> selection;
		if (selection == 1)
			bookTicket();
		if (selection == 2)
			showAllTicket();
		if (selection == 3)
			cancelTicket();
	}
}
