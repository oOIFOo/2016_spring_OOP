//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2016/02/27
//
#include "mySystem_SortingVisualization.h"
#include <iostream>
#include <time.h>

using namespace std;

SORTING_VISUALIZATION::SORTING_VISUALIZATION( )
{
    mNumElements = 20;
    mMinValue = 1;
    mMaxValue = 30;
    reset( );
}

/*
Generate randomly the elements between mMinValue and mMaxValue.
The total number of elements is mNumElements.
*/
void SORTING_VISUALIZATION::reset( )
{
	int temp;
	askForInput();
	srand(time(NULL));
	for (int i = 0; i < mNumElements; i++) {
		temp = (int)((mMaxValue)-(mMinValue)) * rand() / (RAND_MAX) + mMinValue;
		mNumbers.push_back(temp);
	}
}

/*
Show the system title.
Ask to input the range [mMinValue, mMaxValue] of the elements.
Ask to input the number of elements.
Generate the elements.
*/
void SORTING_VISUALIZATION::askForInput( )
{
    cout << "//////////////////////////////" << endl;
    cout << "SORTING_VISUALIZATION" << endl;
   
}

/*
Two elements whose
indices are (index) and (index+1).

Swap these two elements if their order is incorrect.
*/
void SORTING_VISUALIZATION::checkAndSwapTwoElements( int index )
{
	if (mNumbers[index] >= mNumbers[index + 1]){
		mCurrentIndex = index;
		processOneSwapStep();
	}
}

/*
Perform one swap step for two elements.
The first element is indicated by mCurrentIndex.
*/
void SORTING_VISUALIZATION::processOneSwapStep( )
{
	int temp;
	if (mNumbers[mCurrentIndex] >= mNumbers[mCurrentIndex + 1]){
		temp = mNumbers[mCurrentIndex];
		mNumbers[mCurrentIndex] = mNumbers[mCurrentIndex + 1];
		mNumbers[mCurrentIndex + 1] = temp;
		mCurrentIndex++;
		if (mCurrentIndex == mNumElements - 1){
			mCurrentIndex = 0;
		}
	}
	else{
		mCurrentIndex++;
		if (mCurrentIndex == mNumElements - 1){
			mCurrentIndex = 0;
		}
	}
}

/*
Return the current element that will be processed.
*/
int SORTING_VISUALIZATION::getCurrentElementIndex( ) const
{
	return (mCurrentIndex);
}

/*
Return the index of the last non-handled element.

mMaxNonHandledElementIndex
*/
int SORTING_VISUALIZATION::getMaxNonHandledElementIndex( ) const
{
	return (mCurrentIndex+1);
}

/*
Return the number of elements.
*/
int SORTING_VISUALIZATION::getNumOfElements( ) const
{
    //Return the number of elements
	return  mNumElements;
}

/*
Return the element whose index is elementIndex.
*/
int SORTING_VISUALIZATION::getElement( int elementIndex ) const
{
	return mNumbers[elementIndex];
}