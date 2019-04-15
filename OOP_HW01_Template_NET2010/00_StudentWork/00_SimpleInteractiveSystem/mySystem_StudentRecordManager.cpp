//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2016/02/27
//
#include "mySystem_StudentRecordManager.h"
#include <iostream>
#include <algorithm>

using namespace std;

STUDENT_RECORD_MANAGER::STUDENT_RECORD_MANAGER( )
{
	mNumStudents = 0;
}

void STUDENT_RECORD_MANAGER::askForInput( )
{
	//Show the system title
	//Ask to input the number of students
	//Ask to input the score of each student
	//Show the average
	//Show the standard deviation
	//Show the scores in an ascending order
	//
	int i , x;
	cout << "STUDENT_RECORD_MANAGER" << endl;
	cout << "input the number of students" << endl;
	cin >> mNumStudents;
	cout << "input the score of each student" << endl;
	for(i = 0;i < mNumStudents;i++){
		cin >> x;
		mScore.push_back(x);
	}
	//mAverageScore = computeAverage( );
	cout << "Average score is " << mAverageScore << endl;
	//mStandardDeviation = computeStandardDeviation( );
	cout << "Standard deviation is " << mStandardDeviation << endl;
	cout << "The scores in an ascending order:" << endl;
	sortScores( );
	showSortedScores( );
	mScore.clear();
	mSortedScore.clear();
}

double STUDENT_RECORD_MANAGER::computeAverage( )
{
	//Compute the average
	int i;
	double total;
	for(i = 0;i < mNumStudents;i++){
		total = total + mScore[i];
	}
	mAverageScore = total/mNumStudents;
	return mAverageScore;
}

double STUDENT_RECORD_MANAGER::computeStandardDeviation( )
{
	//Compute the standard deviation
	int i;
	double x;
	for(i = 0;i < mNumStudents;i++){
		x = x + (mScore[i] - mAverageScore) * (mScore[i] - mAverageScore);
	}
	mStandardDeviation = sqrt(x/mNumStudents);
	return mStandardDeviation;
}

void STUDENT_RECORD_MANAGER::sortScores( )
{
	//Sorting in an ascending order
	mSortedScore = mScore;
	sort( mSortedScore.begin() , mSortedScore.end() );
}

void STUDENT_RECORD_MANAGER::showSortedScores( ) const
{
	//Show the scores in an ascending order
	int i;
	for(i = 0;i < mNumStudents;i++){
		cout << mSortedScore[i] << " ";
	}
	cout << endl
}

int STUDENT_RECORD_MANAGER::getNumOfStudentsInScoreInterval(int s0, int s1) const
{
	//
	//Return the number of students whose score is inside the interval [s0, s1]. 
	//s0 and s1 are included.
	// 
	int num = 0 , i;
	for(i = 0;i < mNumStudents;i++){
		if( (s0 <= mScore[i]) && (mScore[i]<= s1) ){
			num++;
		}
	}
	return num;
}
