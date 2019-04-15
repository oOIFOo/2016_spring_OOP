//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2016/02/27
//
#include "mySystem_CubicFunction.h"
#include <iostream>

using namespace std;

CUBIC_FUNCTION::CUBIC_FUNCTION( )
{
	x0 = -10.0;
	x1 = 10.0;
	mNumSamples = 100;
	a = b = c = d = 0.5;
}

void CUBIC_FUNCTION::askForInput( )
{
	//
	//ax^3 + bx^2 + cx + d
	//Show the system name
	//Ask to input a, b, c, d
	//Ask to input the range of x in [-10, 10]
	//Ask to input the number of sample points
	//
	cout << "CubicFunction" << endl;
	cout << "input a, b, c , d" <<endl;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cout << "input the range of x in [-10, 10]" <<endl;
	//getRangeOfX(x0 , x1);
	cin >> x0;
	cin >> x1;	
	cout << "input the number of sample points" <<endl;
	cin >> mNumSamples;
	//getNumOfSamples( );
}

void CUBIC_FUNCTION::getRangeOfX( double &x0, double &x1 ) const
{
	//Return the range of x in x0 and x1.
	x0 = this->x0;
	x1 = this->x1;
}

int CUBIC_FUNCTION::getNumOfSamples( ) const
{
	//Return the number of samples
	return mNumSamples;
}

double CUBIC_FUNCTION::getValue( double x ) const
{
	//Compute ax^3 + bx^2 + cx + d
	//i.e., compute the value a*x*x*x + b*x*x + c*x + d
	//return a*x*x*x + b*x*x + c*x + d;
	int y;
	y = (a*x*x*x) + (b*x*x) + (c*x) + d;
	return y;
}