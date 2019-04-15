//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2016/02/27
//
#include "mySystem_QuadraticFunction.h"
#include <iostream>

using namespace std;

QUADARTIC_FUNCTION::QUADARTIC_FUNCTION( )
{
	x0 = -10.0;
	x1 = 10.0;
	mNumSamples = 100;
	a = b = c = 1;
}

void QUADARTIC_FUNCTION::askForInput( )
{
	//
	//ax^2 + bx + cx
	//Show the system name
	//Ask to input a, b, c, d
	//Ask to input the range of x in [-10, 10]
	//Ask to input the number of sample points
	//
	cout << "QUADARTIC FUNCTION" <<endl;
	cout << "input a, b, c" <<endl;
	cin >> a;
	cin >> b;
	cin >> c;
	cout << "input the range of x in [-10, 10]" <<endl;
	cin >> x0;
	cin >> x1;
	cout << "input the number of sample points" <<endl;
	cin >> mNumSamples;
}

void QUADARTIC_FUNCTION::getRangeOfX( double &x0, double &x1 ) const
{
	//Return the range of x in x0 and x1.
	x0 = this->x0;
	x1 = this->x1;
}

int QUADARTIC_FUNCTION::getNumOfSamples( ) const
{
	//Return the number of samples
	return mNumSamples;
}

double QUADARTIC_FUNCTION::getValue( double x ) const
{
	//Compute ax^2 + bx + c
	double y;
	y = (a*x*x) + (b*x) + c;
	return y;
}