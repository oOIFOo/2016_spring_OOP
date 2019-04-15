//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2016/02/27
//
#include "mySystem_GalaxySystem.h"
#include <iostream>

using namespace std;

namespace {
    double getRandDouble( double L, double U ) {
        return L + (U-L)*rand( )/(double) RAND_MAX;
    }
};

GALAXY_SYSTEM::GALAXY_SYSTEM( )
{
	mSpaceRadius = 15.0;
    mTimeStep = 0.0025; 
    mNumOfObjs = 100;
    mMinR = 0.5;            //minimum radius of objects
    mMaxR = 1.0;            //maximum radius of objects
	mSortingType = SORT_X;
    generateObjects( );
	sort();
}

//resize the objects
void GALAXY_SYSTEM::resizeObjs()
{
	srand(time(NULL));
	mR.clear();
	double x, y, r;
	for (int i = 0; i < mNumOfObjs; i++){
		r = (mMaxR - mMinR)* rand() / (RAND_MAX + 1.0) + mMinR;
		//r *= 5;
		mR.push_back(r);
	}
}

/*
Generate objects
*/
void GALAXY_SYSTEM::generateObjects( )
{
	srand(time(NULL));
	double x, y, r, rad = mSpaceRadius*mSpaceRadius;
	for (int i = 0; i < mNumOfObjs; i++){
		while (1){
			x = (2 * mSpaceRadius)* rand() / (RAND_MAX + 1.0) - mSpaceRadius;
			y = (2 * mSpaceRadius)* rand() / (RAND_MAX + 1.0) - mSpaceRadius;
			if (x*x + y*y <= rad){
				break;
			}
		}
		r = (mMaxR - mMinR)* rand() / (RAND_MAX + 1.0) + mMinR;
		//r *= 5;
		mX.push_back(x);
		mY.push_back(y);
		mR.push_back(r);
	}
}

/*
Handle the key events.
Set flgHandled to true if the key is handled.
*/
bool GALAXY_SYSTEM::handleKeyPressedEvent( int key )
{
    bool flgHandled = false;
	switch (key)
	{
	case '9':
		mMaxR -= 0.1;
		if (mMaxR <= 0.1){
			mMaxR = 0.1;
		}
		resizeObjs();
		flgHandled = true;
		break;
	case '0':
		mMaxR += 0.1;
		if (mMaxR >= 2.0){
			mMaxR = 2.0;
		}
		resizeObjs();
		flgHandled = true;
		break;
	case 'j':
		mNumOfObjs -= 100;
		if (mNumOfObjs <= 0){
			mNumOfObjs = 0;
		}
		flgHandled = true;
		generateObjects();
		break;
	case 'k':
		mNumOfObjs += 100;
		if (mNumOfObjs >= 10000){
			mNumOfObjs = 10000;
		}
		flgHandled = true;
		generateObjects();
		break;
	case '1':
		sortX();
		mSortingType = SORT_X;
		flgHandled = true;
		break;
	case '2':
		sortY();
		mSortingType = SORT_Y;
		flgHandled = true;
		break;
	case '3':
		sortCenter();
		mSortingType = SORT_CENTER;
		flgHandled = true;
		break;
	default:
		break;
	}
	return flgHandled;
}

//Use a switch block to perform the sorting based on mSortingType.
void GALAXY_SYSTEM::sort() {

}

void GALAXY_SYSTEM::sortX()
{
	double k;
	for (int i = 0; i < mNumOfObjs; i++){
		for (int j = 0; j < mNumOfObjs - 1; j++){
			if (mX[j] > mX[j + 1]){
				k = mY[j];
				mY[j] = mY[j + 1];
				mY[j + 1] = k;
				k = mX[j];
				mX[j] = mX[j + 1];
				mX[j + 1] = k;
				k = mR[j];
				mR[j] = mR[j + 1];
				mR[j + 1] = k;
			}
		}
	}
}

void GALAXY_SYSTEM::sortCenter()
{
	double d1, d2;
	double k;
	for (int i = 0; i < mNumOfObjs; i++){
		for (int j = 0; j < mNumOfObjs - 1; j++){
			d1 = mX[j] * mX[j] + mY[j] * mY[j];
			d2 = mX[j+1] * mX[j+1] + mY[j+1] * mY[j+1];
			if (d1 < d2){
				k = mY[j];
				mY[j] = mY[j + 1];
				mY	[j + 1] = k;
				k = mX[j];
				mX[j] = mX[j + 1];
				mX[j + 1] = k;
				k = mR[j];
				mR[j] = mR[j + 1];
				mR[j + 1] = k;
			}
		}
	}
}
void GALAXY_SYSTEM::sortY()
{
	double k;
	for (int i = 0; i < mNumOfObjs; i++){
		for (int j = 0; j < mNumOfObjs - 1; j++){
			if (mY[j] > mY[j + 1]){
				k = mY[j];
				mY[j] = mY[j + 1];
				mY[j + 1] = k;
				k = mX[j];
				mX[j] = mX[j + 1];
				mX[j + 1] = k;
				k = mR[j];
				mR[j] = mR[j + 1];
				mR[j + 1] = k;
			}
		}
	}
}
/*
Generate the objects.
Call generateObjects( ).
*/
void GALAXY_SYSTEM::reset( )
{
    generateObjects( );
}

/*
Show the system title.
Show the key usage.
*/
void GALAXY_SYSTEM::askForInput( )
{
    cout << "GALAXY_SYSTEM::askForInput" << endl;
}

/*
Return the number of objects
return mNumOfObjs
*/
int GALAXY_SYSTEM::getNumOfObjs( ) const
{
	return mNumOfObjs;
}

/*
Get the object information based on the object index.
(x,y) = position
r = radius
Return the alive flag.

Note here that the objects 
should have been ordered based on the sorting type.
*/
void GALAXY_SYSTEM::getObjInfo( int objIndex, double &x, double &y, double &r ) const
{
	x = mX[objIndex];
	y = mY[objIndex];
	r = mR[objIndex];
}

void GALAXY_SYSTEM::update( ) 
{
	//This function is empty.
}