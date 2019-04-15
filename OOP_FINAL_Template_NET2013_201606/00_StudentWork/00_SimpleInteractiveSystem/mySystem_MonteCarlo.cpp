//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
//
#include "mySystem_MonteCarlo.h"
#include "myBasicTools.h"
#include <iostream>

using namespace std;

#define MAX_SAMPLES 100000


MONTE_CARLO_SYSTEM::MONTE_CARLO_SYSTEM( )
{
    //BEGIN DO NOT CHANGE ANYTHING HERE
	mFunctionType = FUNCTION_1;
    cout.precision(8);
	inside = 0;
	mMinX = -4.0;	// minimum x value
    mMaxX = 4.0;	// maximum x value
    mMinY = -10.0;	// minimum y value
    mMaxY = 10.0;	// maximum y value
    mMinNumSamples = 0;
    mMaxNumSamples = MAX_SAMPLES;
    mNumSamples = 5000;
    computeSamples( );
    computeArea( );
    //END DO NOT CHANGE ANYTHING HERE
}

/*
Show the message to the user.
*/
void MONTE_CARLO_SYSTEM::askForInput( )
{
    cout << "MONTE_CARLO_SYSTEM::askForInput( )" << endl;
}

/*
Handle the key events.
Set flgHandled = true if the key is handled.
*/
bool MONTE_CARLO_SYSTEM::handleKeyPressedEvent( int key )
{
    bool flgHandled = false;
	switch (key)
	{
	case 'r':
		mNumSamples = 100;
		break;
	case 'k':
		mNumSamples += 100;
		if (mNumSamples >= 100000){
			mNumSamples = 100000;
		}
		break;
	case 'j':
		mNumSamples -= 1000;
		if (mNumSamples <= 10){
			mNumSamples = 0;
		}
		break;
	case '1':
		mFunctionType = 1;
		break;
	case '2':
		mFunctionType = 2;
		break;
	default:
		break;
	}
	computeArea();
	return flgHandled;
}

/*
Reset the system state.
Steps:
compute the samples
compute the area
*/
void MONTE_CARLO_SYSTEM::reset( )
{
    srand(0);
    computeSamples( );
    computeArea( );
	inside = 0;
}

/*
Return the range [mMinX, mMaxX] of x to [minX, maxX].

    minX = mMinX;
    maxX = mMaxX;

*/
void MONTE_CARLO_SYSTEM::getRangeOfX( double &minX, double &maxX ) const
{
	minX = mMinX;
	maxX = mMaxX;
}

/*
Uniformly generate all the random sample points
inside [mMinX, mMaxX] x [mMinY, mMaxY].

The number of sample points is mNumSamples.

Store them in mX and mY.
*/
void MONTE_CARLO_SYSTEM::computeSamples( )
{
	srand(time(NULL));
	double x , y;
	for (int i = 0; i < mNumSamples; i++){
		x = (mMaxX - mMinX) * rand() / (RAND_MAX + 1.0) + mMinX;
		y = (mMaxY - mMinY) * rand() / (RAND_MAX + 1.0) + mMinY;
		mX.push_back(x);
		mY.push_back(y);
	}
	computeArea();
}

/*
Compute the area based on the Monte Carlo Simulation.
Steps:
1. compute the number of samples inside the area
2. compute the ratio which is equal to

	number of samples inside the area 
	divided 
	by total number of samples

3. Based on the ratio, compute the area

If mNumSamples > 0, 
return the area value

If mNumSamples <= 0,
return 0.0
*/
double MONTE_CARLO_SYSTEM::computeArea( ) const
{
    double area = 0.0;
	int in = 0;
	double x = mNumSamples;
	for (int i = 0; i < mNumSamples; i++){
		if (isInsideArea(mX[i], mY[i])){
			in++;
		}
	}
	area = (double)(in / x) * 160.0;
	cout << area << endl;
    return area;
}

/*
Return the number of sample points.
Return mNumSamples.
*/
int MONTE_CARLO_SYSTEM::getNumSamples( ) const
{
    //Return the number of sample points
	return mNumSamples;
}

/*
 x = mX[ sampleIndex ];
 y = mY[ sampleIndex ];
*/
void MONTE_CARLO_SYSTEM::getSample(int sampleIndex, double &x, double &y ) const
{
	x = mX[sampleIndex];
	y = mY[sampleIndex];
}

/*
Based on the function type mFunctionType and functionIndex,
compute the function value for a given value x.
Return the function value.

functionIndex = 0, function value is f(x)
functionIndex = 1, function value is g(x)
*/
double MONTE_CARLO_SYSTEM::getValue(double x, int functionIndex) const
{
    double y = 0.0;
	if (mFunctionType == 1){
		switch (functionIndex){
		case 0:
			y = x*sin(x) + x*x*cos(x);
			break;
		case 1:
			y = x*sin(2 * x) - (1 - x)*cos(x);
			break;
		}
		return y;
	}
	if (mFunctionType == 2){
		switch (functionIndex){
		case 0:
			y = x*cos(x) + x*x*sin(x);
			break;
		case 1:
			y = x*x*cos(x / 2) - (1 - x)*sin(x / 2);
			break;
		}
		return y;
	}
}

/*
Given a point (x,y).
Check if the point lies inside the area.
Return true if it lies inside the area.
Return false otherwise.

Otherwise, (x,y) does not lay inside the area.

Hint:
compute f(x) and g(x) and 
then determine if (x,y) bounded by f(x) and g(x).

double realY0 = getValue( x, 0 ); // get f(x)
double realY1 = getValue( x, 1 ); // get g(x)
and then add extra code.
*/

bool MONTE_CARLO_SYSTEM::isInsideArea( double x, double y ) const
{
    double realY0 = getValue( x, 0 ); // get f(x)
	double realY1 = getValue( x, 1 ); // get g(x)
	if (y >= realY0 && y <= realY1){
		return true;
	}
	if (y <= realY0 && y >= realY1){
		return true;
	}
	return false;
}