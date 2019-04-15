#include "Ticket_System.h"

Ticket_System::Ticket_System()
{
	// welcome message and call initialization
	//cout << "************************";
	cout << "welcome to the booking system" << endl;
	cout << "0 = book ticket , 1 = cancel booking , 2 = search booking , 3 = print booking , quit = exit" << endl;
	id = -1;
	Initialize();
	train = -1;
	hotel = -1;
	concert = -1;
}

void Ticket_System::Initialize()
{
	// initialize some parameters if necessary
}

Ticket_System::~Ticket_System()
{
	// goodbye message 
}

void Ticket_System::run()
{
	// main iteration - ask user to input the operation
	// Choose Option:
	// 0 = Book Ticket, 1 = Cancel Booking, 2 = Search Booking, 3 = Print Booking, quit = exit
	char key;
	bool quit = false;
	while (cin >> key && quit == false){
		switch (key)
		{
		case'0':
			cout << "please select the tick type" << endl;
			cout << "0 = train ticket , 1 = concert ticket , 2 = hotel ticket" << endl;
			start_booking();
			cout << "welcome to the booking system" << endl;
			cout << "0 = book ticket , 1 = cancel booking , 2 = search booking , 3 = print booking , quit = exit" << endl;
			break;
		case'1':
			cancel_booking();
			cout << "welcome to the booking system" << endl;
			cout << "0 = book ticket , 1 = cancel booking , 2 = search booking , 3 = print booking , quit = exit" << endl;
			break;
		case'2':
			search_booking();
			cout << "welcome to the booking system" << endl;
			cout << "0 = book ticket , 1 = cancel booking , 2 = search booking , 3 = print booking , quit = exit" << endl;
			break;
		case'3':
			print_booking();
			cout << "welcome to the booking system" << endl;
			cout << "0 = book ticket , 1 = cancel booking , 2 = search booking , 3 = print booking , quit = exit" << endl;
			break;
		case'q':
			cout << "goodby and have a nice day"<<endl;
			quit = true;
			break;
		default:
			break;
		}
	}
}

void Ticket_System::start_booking()
{
	// call the choose_type() and pass the ticket_type get from it to book_ticket()
	choose_type();
}

int Ticket_System::choose_type()
{
	// ask user to input the ticket type and return it
	int a;
	cin >> a;
	book_ticket(a);
	return a;
}

void Ticket_System::book_ticket(int ticket_type)
{
	// call the enter_information() according to different ticket_type
	Concert_Ticket *c;
	Train_Ticket *t;
	Hotel_Ticket *h;
	switch (ticket_type){
	case 0:
		t = new Train_Ticket();
		enter_information(t);
		break;
	case 1:
		c = new Concert_Ticket();
		enter_information(c);
		break;
	case 2:
		h = new Hotel_Ticket();
		enter_information(h);
		break;
	default:
		break;
	}
}

bool Ticket_System::enter_information(Train_Ticket *src)
{
	// ask user to enter the information for Train_Ticket
	// after enetering all the information, call generate_booking_ID()
	// return true that this booking is succeed
		char g;
		char a;
		cout << "enter the chart number:" << endl;
		cin >> src->cart;
		cout << "enter the seat number:" << endl;
		cin >> src->seat;
		cout << "enter the departure time:" << endl;
		cin >> src->departure_time.hour >> g >> src->departure_time.minute;
		cout << "enter the arrival time:" << endl;
		cin >> src->arrival_time.hour >> g >> src->arrival_time.minute;
		cout << "enter the start station:" << endl;
		cin >> src->origin;
		cout << "enter the destination:" << endl;
		cin >> src->destination;
		cout << "enter the date:" << endl;
		cin >> src->date.year >> g >> src->date.month >> g >> src->date.day;
		cout << "confirm for booking?";
		cin >> a;
		if (a == 'y' || a == 'Y'){
			cout << "your bookid is " << generate_booking_ID() << endl;
			cout << "book ticket success" << endl;
			m_database.push_back(src);
			return true;
		}
		else{
			return false;
		}
}

bool Ticket_System::enter_information(Concert_Ticket *src)
{
	// ask user to enter the information for Concert_Ticket
	// after enetering all the information, call generate_booking_ID()
	// return true that this booking is succeed
	char g;
	char a;
	cout << "enter the chart number:" << endl;
	cin >> src->zone;
	cout << "enter the seat number:" << endl;
	cin >> src->seat;
	cout << "enter the start_time:" << endl;
	cin >> src->start_time.hour >> g >> src->start_time.minute;
	cout << "enter the date:" << endl;
	cin >> src->date.year >> g >> src->date.month >> g >> src->date.day;
	cout << "confirm for booking?";
	cin >> a;
	if (a == 'y' || a == 'Y'){
		cout << "your bookid is " << generate_booking_ID() << endl;
		cout << "book ticket success" << endl;
		m_database.push_back(src);
		return true;
	}
	else{
		return false;
	}
}

bool Ticket_System::enter_information(Hotel_Ticket *src)
{
	// ask user to enter the information for Hotel_Ticket
	// after enetering all the information, call generate_booking_ID()
	// return true that this booking is succeed
	char g;
	char a;
	cout << "WANT breakfast:(yes for 1 , no for 0)" << endl;
	cin >> src->breakfast;
	cout << "WANT dinner:(yes for 1 , no for 0)" << endl;
	cin >> src->dinner;
	cout << "enter the room number:" << endl;
	cin >> src->room_number;
	cout << "confirm for booking?";
	cin >> a;
	if (a == 'y' || a == 'Y'){
		cout << "your bookid is " << generate_booking_ID() << endl;
		cout << "book ticket success" << endl;
		m_database.push_back(src);
		return true;
	}
	else{
		return false;
	}
}

int Ticket_System::generate_booking_ID()
{
	// genertate the booking ID, use a counter that is increased by 1 every time
	// make sure that this ID does not exist in booking_ID_list
	id++;
	booking_ID_list.push_back(1);
	return id;
}
void Ticket_System::show_ticket_information(int index)
{
	// show the ticket information by calling showInfo()
	if (m_database.at(index) != NULL) m_database.at(index)->showInfo();
}

void Ticket_System::cancel_booking()
{
	// ask user to enter the booking ID and cancel that booking
	// if the booking ID exist, remove it
	// if the booking ID does not exist, show "Can't find this booking record"
	int x;
	cout << "please enter the booking id:";
	cin >> x;
	if ((m_database.at(x) != NULL) && (booking_ID_list.at(x) == 1) ) {
		m_database.erase(x);
		booking_ID_list[x] = 0;
	}
	else{
		cout << "Can't find this booking record" << endl;
	}
	cout << endl;
}

void Ticket_System::search_booking()
{
	// ask user to enter the booking ID and search that booking
	// if the booking ID exist, call show_ticket_information() and copy_booking()
	// if the booking ID does not exist, show "Can't find this booking record"
	int x;
	cout << "please enter the booking id:";
	cin >> x;
	if ((m_database.at(x) != NULL) && (booking_ID_list.at(x) == 1)){
		show_ticket_information(x);
		copy_booking(x);
	}
	else{
		cout << "Can't find this booking record";
	}
}

void Ticket_System::copy_booking(int index)
{
	// ask user to save this information to your device or not
	// "Save this ticket's information to your device? "
	// save the information to t_ticket or c_ticket or h_ticket according to its type
	Ticket *t_;
	char a;
	int t;
	t_ = m_database[index];
	cout << "Save this ticket's information to your device? " << endl;
	cin >> a;
	if (a == 'y' || a == 'Y'){
		//Ticket = m_database.at(index);
		m_database.at(index)->operator=(*m_database[index]);
		t = m_database.at(index)->type;
		t = m_database[index]->type;
		cout << t << endl;
	}
	switch (t)
	{
	case 0:
		t_ticket = new Train_Ticket();
		//t_ticket = m_database.at(index);
		train = index;
		break;
	case 1:
		cout << "**************************";
		c_ticket = new Concert_Ticket();
		//c_ticket = m_database.at(index);
		concert = index;
		break;
	case 2:
		h_ticket = new Hotel_Ticket();
		//h_ticket = m_database.at(index);
		hotel = index;
		break;
	default:
		break;
	}
}

void Ticket_System::print_booking()
{
	// ask user to select the type to show that saved in the device
	// "Please select the ticket type that saved in your device."
	// "0 = Train Ticket, 1 = Concert Ticket, 2 = Hotel Ticket"
	// if the type is none of these ticket type, show "You do not have this ticket's type in your device."
	// print the ticket's information if it exist, otherwise print "You do not have this ticket's information in your device."
	int x;
	cout << "Please select the ticket type that saved in your device." << endl;
	cin >> x;
	switch (x)
	{
	case 0:
		if (train < 0) cout << "You do not have this ticket's information in your device." << endl;
		if (train >= 0){
			show_ticket_information(train);
		}
		break;
	case 1:
		if (concert < 0) cout << "You do not have this ticket's information in your device." << endl;
		if (concert >= 0){
			show_ticket_information(concert);
		}
		break;
	case 2:
		if (hotel < 0) cout << "You do not have this ticket's information in your device." << endl;
		if (hotel >= 0){
			show_ticket_information(hotel);
		}
		break;
	default:
		cout << "You do not have this ticket's type in your device." << endl;
		break;
	}
}