//0416313¦ó¤¸Ùy


// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
//
/*
This system employs the Monte Carlo Simulation
to perform the calculation.
*/
#ifndef __MY_SYSTEM_MONTE_CARLO_H_
#define __MY_SYSTEM_MONTE_CARLO_H_
#include "../headers.h"
#include <string>
#include "../primitives/vector3d.h"
#include <vector>
#include "base_class.h"
using std::vector;

#define FUNCTION_1				1
#define FUNCTION_2				2

class MONTE_CARLO_SYSTEM : public BASE_SYSTEM
{
protected:
    int mMinNumSamples; // the minimum number of samples
    int mMaxNumSamples; // the maximum number of samples

    int mFunctionType;  // the function type
    vector<double> mX;  // x value
    vector<double> mY;  // the function value 

    double mMinX, mMaxX;    // the range along the x-axis
    double mMinY, mMaxY;    // the range along the y-axis

    int mNumSamples;        // the number of samples
	int inside;
    void computeSamples( );

public:
    MONTE_CARLO_SYSTEM( );
    void askForInput( );
    int getNumSamples( ) const;
    void getSample(int sampleIndex, double &x, double &y ) const;
    void getRangeOfX( double &minX, double &maxX ) const;
	double getValue(double x, int functionIndex) const;
    bool isInsideArea( double x, double y ) const;
    double computeArea( ) const;
    bool handleKeyPressedEvent( int key );
    void reset( );
    ////////////////////////////////////////////////////
public:
    void update(  bool flg_timer = false ) { }
    void clickAt( int x, int y, const vector3 &color ) { }
};
#endif