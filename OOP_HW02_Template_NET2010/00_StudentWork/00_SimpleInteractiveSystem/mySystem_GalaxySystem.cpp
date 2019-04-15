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
    mTimeStep = 0.00025; 
    mMaxV = 100.0;
    mNumOfObjs = 100;
    mNumLargeObjs = 2;
    mMinR = 0.5;            //minimum radius of objects
    mMaxR = 3.0;            //maximum radius of objects
    mSpaceSize = 300.0;
    mG = 5.0;               //gravitational constant
    generateObjects( );
}

/*
Generate randomly the positions,  
velocities and radii of the objects.

Also, if the objects are large, 
set their masses to be a large number.

The mass of an  object depends on the object's radius.

The position of an object is inside 
[-halfSpaceSize, halfSpaceSize]x[-halfSpaceSize, halfSpaceSize].

The velocity of an object is inside
[-100.0, 100]x[-100.0, 100].

Initialize the alive flag of each object.
the alive flag indicates whether the object is alive or not.
If the object is not alive, ignore it in all the calculations.

If there's only one large object,
set its position to the origin
and set its velocity to zero.

*/
void GALAXY_SYSTEM::generateObjects( )
{
    //Fill in here
    /* You can remove the following lines.
    mX.resize( mNumOfObjs );
    mY.resize( mNumOfObjs );
    mR.resize( mNumOfObjs );
    mMass.resize( mNumOfObjs );
    mVx.resize( mNumOfObjs );
    mVy.resize( mNumOfObjs );
    mFx.resize( mNumOfObjs );
    mFy.resize( mNumOfObjs );
    */
	int i , c;
	double a , b;
	bool d;
	//srand(time(NULL));
	//cout << "GALAXY_SYSTEM::askForInput" << endl;
	for (i = 0; i < mNumOfObjs; i++) {
		a = (double)rand()*(mSpaceSize / 2 -  (-mSpaceSize / 2) ) / RAND_MAX + (-mSpaceSize / 2);
		mX.push_back(a);
		a = (double)rand()*(mSpaceSize / 2 - (-mSpaceSize / 2)) / RAND_MAX + (-mSpaceSize / 2);
		mY.push_back(a);
		a = (double)rand()*(mMaxR - (mMinR)) / RAND_MAX + (mMinR);
		mR.push_back(a);
		b = a*a;
		mMass.push_back(b);
		c = (int)rand()*(100 - (-100)) / RAND_MAX + (-100);
		mVx.push_back(c);
		c = (int)rand()*(100 - (-100)) / RAND_MAX + (-100);
		mVy.push_back(c);
		d = true;
		mAlive.push_back(d);
	}
}

/*
Handle the key events.
*/
bool GALAXY_SYSTEM::handleKeyPressedEvent( int key )
{
    bool flgHandled = false;
    return flgHandled;
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
	string re;
    cout << "GALAXY_SYSTEM::askForInput" << endl;
	cout << "Key usage:" << endl;
	cout << "input the num of object" << endl;
	//cin >> mNumOfObjs;
	//getNumOfObjs();
	cout << "1: one large object" << endl; // generate the objects. Only one large object
	cout << "2: two large object" << endl; // generate the objects. Only two large objects
	cout << "3: three large object" << endl; // generate the objects. Only three large objects
	//cin >> mNumLargeObjs;
	cout << "r: reset" << endl; 		// reset the positions of the objects
	//cin >> re;
	if (re == "re") {
		reset();
	}
	
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
*/
bool GALAXY_SYSTEM::getObjInfo( int objIndex, double &x, double &y, double &r ) const
{
    x = 1;
    y = 1;
    r = 10;
    return true;
}

/*p[''
Merge the objects if they overlap with each other.
Modify the velocities of the objects after merging
based on the conservation of momentum.
Set the alive flags of the objects accordingly.

Pseudo-code

For each pair of the objects
  if they do not overlap continue
  If they overlap
    do
      turn off the alive flag of the object with smaller radius
      compute the new velocity of the larger object
*/
void GALAXY_SYSTEM::mergeObjects( )
{
	double mivi_mjvj_X, mivi_mjvj_Y;
	for (int i = 0; i < mNumOfObjs; ++i) {
		double mi = mMass[i];
		if (!mAlive[i]) continue;
		double ri = mR[i];
		for (int j = i + 1; j < mNumOfObjs; ++j) {
			if (!mAlive[j]) continue;
			double mj = mMass[j];
			double rj = mR[j];
			double dx = mX[i] - mX[j];
			double dy = mY[i] - mY[j];
			double d2 = dx*dx + dy*dy;
			double d = dx*dx + dy*dy;
			if (ri + rj > d){
				if (ri > rj){
					mAlive[j] = false;
					mivi_mjvj_X = mVx[i] * mMass[i] + mVx[j] * mMass[j];
					mivi_mjvj_Y = mVy[i] * mMass[i] + mVy[j] * mMass[j];
					mMass[i] += mMass[j]; // total mass
					mVx[i] = mivi_mjvj_X / mMass[i];
					mVy[i] = mivi_mjvj_Y / mMass[i];
					mAlive[j] = 0; 
				}
			}
			else{
				mAlive[i] = false;
				mivi_mjvj_X = mVx[i] * mMass[i] + mVx[j] * mMass[j];
				mivi_mjvj_Y = mVy[i] * mMass[i] + mVy[j] * mMass[j];
				mMass[j] += mMass[i]; // total mass
				mVx[j] = mivi_mjvj_X / mMass[i];
				mVy[j] = mivi_mjvj_Y / mMass[i];
			}
		} // end loop j
	} // end loop i
}

/*
Update the position of the objects
Steps:
1. compute the forces exerting on each object
2. compute the velocity of each object
3. compute the position of each object

Constraints:
The component of a velocity must be inside [-mMaxV, mMaxV].

The component of a position must be inside [-halfSpaceSize, halfSpaceSize].
Warp the position if it's outside of the range.
Consider a position (x,y).
If x > halfSpaceSize, set x = -halfSpaceSize;


*/
void GALAXY_SYSTEM::update()
{
	mergeObjects();
	double nx; //normalize along the x-axis
	double ny;//normalize along the y-axis
	double dx, dy;
	double mij;
	for (int i = 0; i < mNumOfObjs; ++i){
		mFx[i] = 0.0;
		mFy[i] = 0.0;
	}
	for (int i = 0; i < mNumOfObjs; i++){
		double ni = mMass[i];
		if (!mAlive[i]) continue;
		double ri = mR[i];
		for (int j = i + 1;j < mNumOfObjs; j++) {
			if (!mAlive[j]) continue;
			double mj = mMass[j];
			mij = mMass[i] * mMass[j];
			dx = mX[i] - mX[j];
			dy = mY[i] - mY[j];
			double d2 = dx*dx + dy*dy;
			double d = sqrt(d2);
			ny = dy / d;
			nx = dx / d;
			if(dx > 0){
				mFx[i] -= mij*mG / (dx*dx); 	//notice the negative sign	
				mFy[i] -= mij*mG / (dy*dy);	//notice the negative sign
			}
			if (dx < 0) {
				mFx[i] += (mij*mG) / (dx*dx); 	//notice the negative sign	
				mFy[i] += (mij*mG) / (dy*dy);	//notice the negative sign
			}
		}
		for (int i = 0; i < mNumOfObjs; ++i){
			mVx[i] = mVx[i] + mFx[i] / mMass[i] * mTimeStep;
			mVy[i] = mVy[i] + mFy[i] / mMass[i] * mTimeStep;
			if (mVx[i] > mMaxV) mVx[i] = mMaxV;
			if (mVx[i] < -mMaxV) mVx[i] = -mMaxV;
			if (mVy[i] > mMaxV) mVy[i] = mMaxV;
			if (mVy[i] < -mMaxV) mVy[i] = -mMaxV;
		}
		mX[i] = mX[i] + mVx[i] * mTimeStep;
		mY[i] = mY[i] + mVy[i] * mTimeStep;
		}
	}
	

    //
    //Fill in here
    //compute forces exerting on objects
    //compute velocities of objects
    //compute positions of objects
    //make sure the objects inside the space