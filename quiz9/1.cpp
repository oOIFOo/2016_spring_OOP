#include <iostream>

using namespace std;

struct node
{
	float value;
	node *next;
};

class Stack
{
	node *head;
	node *end;
public:
	Stack();
	void push(float x);
	void pop();
	void print();
};

void Stack::push(float x)
{
	if (head == NULL){
		head = new node;
		head->value = x;
		head->next = NULL;
		end = head;
	}
	else{
		node *y;
		y = new node;
		y->value = x;
		head->next = y;
		y->next = NULL;
		head = y;
	}
}

Stack::Stack()
{
	head = NULL;
	end = NULL;
}

void Stack::pop()
{
	node *point;
	point = end;
	while ((point != NULL) && (head != end)){
		if (point->next == head){
			delete head;
			head = point;
			break;
		}
		point = point->next;
	}
	if ((point == NULL) || (head == end)){
		delete head;
		head = NULL;
		end = NULL;
	}
}

void Stack::print()
{
	// add code here
	node *p;
	int have = 0;
	p = end;
	while (1){
		if ((p == NULL) && (have == 0)){
			cout << "Empty." << endl;
			break;
		}
		if (p == NULL){
			break;
		}
		cout << p->value << endl;
		p = p->next;
		have = 1;
	}
}

int main()
{
	unsigned char key;
	float input;
	int step;
	Stack myStack;

	cin >> step;
	for (int i = 0; i < step; i++)
	{
		cin >> key;
		switch (key)
		{
		case 'i':
		case 'I':
			cin >> input;
			myStack.push(input);
			break;
		case 'p':
		case 'P':
			myStack.pop();
			break;
		default:
			break;
		}
	}

	myStack.print();
	system("pause");
	return 0;
}
