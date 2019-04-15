#include <iostream>

using namespace std;


struct node
{
	float value;
	node *next;
};

class myQueue
{
public:
	myQueue(){
		head = NULL;
		currentNode = NULL;
	};
	node *head;
	node *currentNode;
	int length;
	void push(float x);
	void pop();
};

void myQueue::push(float x)
{
	if (head == NULL){
		head = new node;
		head->value = x;
		head->next = NULL;
		currentNode = head;
	}
	else{
		node *y;
		y = new node;
		y->value = x;
		currentNode->next = y;
		y->next = NULL;
		currentNode = y;
	}
}

void myQueue::pop()
{
	node *point;
	point = head;
	if ((point != NULL) && (head != currentNode)){
		head = head->next;
		delete point;
	}
	if ((point == NULL) || (head == currentNode)){
		delete head;
		head = NULL;
		currentNode = NULL;
	}
}

int main()
{
	unsigned char key;
	float input;
	int step, count = 0;
	myQueue test;

	cin >> step;
	for (int i = 0; i < step; i++)
	{
		cin >> key;
		switch (key)
		{
		case'i':
		case'I':
			count++;
			cin >> input;
			test.push(input);
			break;
		case'p':
		case'P':
			count--;
			if (count < 0){
				count = 0;
			}
			test.pop();
			break;
		default:
			break;
		}
	}
	test.length = count;
	if (count < 0){
		test.length = 0;
	}
	test.currentNode = test.head;
	for (int i = 0; i < test.length; i++)
	{
		cout << test.currentNode->value << endl;
		test.currentNode = test.currentNode->next;
	}

	system("pause");
	return 0;
}
