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
#include <iostream>

using namespace std;

#define MAX_SAMPLES 1000000

MONTE_CARLO_SYSTEM::MONTE_CARLO_SYSTEM( )
{
	cout.precision(8);
	//
	mRadius = 5.0f;
	mNumSamples = 100000;
	computeSamples( );
}

void MONTE_CARLO_SYSTEM::askForInput( )
{
	//
	//Show the system name
	//Ask to input the radius of the circle
	//Ask to input the number of sample points
	//Call computeSamples( ) to compute the sample points and pi
	//
	cout << "MONTE CARLO" << endl;
	cout<<"input the radius"<<endl;
	cout<<"input the number of sample points"<<endl;
	computeSamples( );
	mX.clear();
	mY.clear();
}

void MONTE_CARLO_SYSTEM::computeSamples( )
{
	//
	//Compute the coordinates of the sample points.
	//There are mNumSamples samples.
	//Compute pi which is equal to:
	// 4*(number of samples inside the circle / total samples)
	//
	int count , i;
	float x , y;
	double pi;
	cin >> mRadius;
	cin >> mNumSamples;
	srand(time(NULL));
	for(i = 0;i < mNumSamples;i++){
		x = (float) ( (mRadius- (-mRadius) ) * (float)rand()/RAND_MAX );
		y = (float) ( (mRadius- (-mRadius) ) * (float)rand()/RAND_MAX );
		mX.push_back(x);
		mY.push_back(y);
		getSample( i , x , y);
		if( ( (x*x) + (y*y) ) <= (mRadius) * (mRadius) ){
			count++;
		}
	}
	pi = (double)4*( (double)count / mNumSamples);
	cout<<"pi is "<< pi << endl;
}



double MONTE_CARLO_SYSTEM::getRadius( ) const
{
	//Return the radius of the circle
	return mRadius;
}

int MONTE_CARLO_SYSTEM::getNumSamples( ) const
{
	//Return the number of sample points
	return mNumSamples;
}

bool MONTE_CARLO_SYSTEM::getSample(int sampleIndex, float &x, float &y) const
{
	//
	//Return the sample coordinates in (x, y).
	//Return the boolean value indicating whether the sample lying inside the circle.
	//
	bool flgInside = false;
	if( ( (x*x) + (y*y) ) <= (mRadius) * (mRadius) ){
		flgInside = true;
	}
	x = mX[sampleIndex];
	y = mY[sampleIndex];
	return flgInside;
}
