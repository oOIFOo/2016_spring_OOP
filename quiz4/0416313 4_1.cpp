// NCTU OOP lab - Quiz Four
// Q1 - Constructor and Destructor
//
// Name:
// Student ID:
#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A+ ";
	}
	~A()
	{
		cout << "A- " << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "B+ ";
	}
	~B()
	{
		cout << "B- ";
	}
};

class C : public B
{
public:
	C()
	{
		cout << "C+ ";
	}
	~C()
	{
		cout << "C- ";
	}
};

class D : public C
{
public:
	D()
	{
		cout << "D+ ";
	}
	~D()
	{
		cout << "D- ";
	}
};

int main(void)
{
	char command;
	while (cin >> command) {
		if (command == '0')
		{
			A a;
			cout << endl;
			B b;
			cout << endl;
			C c;
			cout << endl;
			D d;
			cout << endl;
			//break;
		}
		else if (command == '1')
		{
			A a;
			cout << endl;
			B b;
			cout << endl;
			C c;
			cout << endl;
			//break;
		}
		else if (command == '2')
		{
			// Add the code here.
			A a;
			cout << endl;
			B b;
			cout << endl;
		}
		else if (command == '3')
		{
			A a;
			cout << endl;
		}
		else if (command == '4')
		{
			B b;
			cout << endl;
			A a;
			cout << endl;
		}
		else if (command == '5')
		{
			C c;
			cout << endl;
			B b;
			cout << endl;
			A a;
			cout << endl;
			// Add the code here.
		}
		else if (command == '6')
		{
			D d;
			cout << endl;
			C c;
			cout << endl;
			B b;
			cout << endl;
			A a;
			cout << endl;
			// Add the code here.
		}
	}
	//system("pause");
	return 0;
}
