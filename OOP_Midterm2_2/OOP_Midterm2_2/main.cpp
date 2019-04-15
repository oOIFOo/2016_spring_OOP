#include "Ticket_System.h"

using namespace std;

int main() {
	Ticket_System *app = new Ticket_System();
	app->run();
	delete app;
	system("pause");
	return 0;
}
