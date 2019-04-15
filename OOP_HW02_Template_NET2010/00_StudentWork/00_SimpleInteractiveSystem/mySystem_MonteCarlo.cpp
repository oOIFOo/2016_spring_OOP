//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2016/02/27
//
#include "mySystem_MonteCarlo.h"
#include "myBasicTools.h"
#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

#define MAX_SAMPLES 1000000

MONTE_CARLO_SYSTEM::MONTE_CARLO_SYSTEM( )
{
    //BEGIN DO NOT CHANGE ANYTHING HERE
    mFunctionType = FUNCTION_EXPONENTIAL_SINE;
    cout.precision(8);
    //
    mMinX = 0.0;
    mMaxX = 3.141592654*3.0;
    mMinY = -2.0;
    mMaxY = 2.0;
    mMinNumSamples = 100;
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
	cout << "Use keys to control......" << endl;
	cout << "1: FUNCTION_EXPONENTIAL_SINE" << endl;
	cout << "2: FUNCTION_SINE" << endl;
	cout << "3: FUNCTION_SINE_COSINE" << endl;
	cout << "4: FUNCTION_EXPONENTIAL" << endl;
	cout << "m: minimum number of sample points" << endl;
	cout << ",: decrease the number of sample points" << endl;
	cout << ".: increase the number of sample points" << endl;
	cout << "/: maximum number of sample points" << endl;
	//cin >> mFunctionType;
	//cin >> 
}

/*
Handle the key events.
*/
bool MONTE_CARLO_SYSTEM::handleKeyPressedEvent( int key )
{
    bool flgHandled = false;
//	computeSamples();
//	computeArea();
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
	mX.clear();
	mY.clear();
    computeSamples( );
    computeArea( );
	//cin >> mFunctionType;
}

/*
Return the range [mMinX, mMaxX] of x to [minX, maxX].

    minX = mMinX;
    maxX = mMaxX;

*/
void MONTE_CARLO_SYSTEM::getRangeOfX( double &minX, double &maxX ) const
{
    minX = 0.0;
    maxX = 10.0;
}

/*
Uniformly generate all the random sample points
inside [mMinX, mMaxX] x [mMinY, mMaxY].

The number of sample points is mNumSamples.
*/
void MONTE_CARLO_SYSTEM::computeSamples( )
{
	askForInput();
//	handleKeyPressedEvent();
	double e = 2.718281828;
	int i;
	double a , b;
	for(i = 0;i<mNumSamples;i++){
		a = (double)rand()*(mMaxX - mMinX) / RAND_MAX + mMinX;
		b = (double)rand()*(mMaxY - mMinY) / RAND_MAX + mMinY;
		mX.push_back(a);
		mY.push_back(b);
	}
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

Return the area value
*/
double MONTE_CARLO_SYSTEM::computeArea( ) const
{
    double area = 0.0;
	double count = 0.0;
	for (int i = 0; i < mNumSamples; i++){
		if (isInsideArea(mX[i], mY[i]) == true){
			count++;
		}
	}
	area = count / mNumSamples;
    cout << "Area:" << area << endl;
    return area;

}

/*
Return the number of sample points.
Return mNumSamples.
*/
int MONTE_CARLO_SYSTEM::getNumSamples( ) const
{
    //Return the number of sample points
//	cin >> mNumSamples;
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
Based on the function type mFunctionType,
compute the function value for a given value x.
Return the function value.
*/
double MONTE_CARLO_SYSTEM::getValue(double x) const
{
    double y;
	double e = 2.718281828;

    switch( mFunctionType ) {
    case FUNCTION_EXPONENTIAL_SINE:
		y = 2.0*(pow(e , -x/5.0)) *sin(x);
        break;
    case FUNCTION_SINE:
		y = sin(x);
        break;
    case FUNCTION_SINE_COSINE:
		y = sin(x)*cos(x);
        break;
    case FUNCTION_EXPONENTIAL:
		y = 2.0*(pow(e , -x/5.0));
        break;
    }
    return y;
	//return 0;
}

/*
Given a point (x,y).
Check if the point lies inside the area.
Return true if it lies inside the area.
Return false otherwise.

The area is defined as the region bounded by
the x-axis and the curve of the function f(x).

Assume that (x,y) lies inside area, then
one of the following conditions must be satisfied.

- If f(x) >= 0 and y >=0, then y <= f(x).
- If f(x) <= 0 and y <=0, then y >= f(x).

Otherwise, (x,y) does not lay inside the area.
*/
bool MONTE_CARLO_SYSTEM::isInsideArea( double x, double y ) const
{
	bool ans = false;
    double realY;
	double e = 2.718281828;
	realY = getValue(x);
	if ((y <= realY && y >= 0) || (y >= realY && y <= 0)){
		return true;
	}
	return false;
}