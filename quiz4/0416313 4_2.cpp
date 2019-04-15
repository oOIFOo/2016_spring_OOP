// NCTU OOP lab - Quiz Four
// Q2 - Clock Hands
//
// Name:
// Student ID:
#include <iostream>
using namespace std;

class stdu{
public:
	void in( int x0 , int x1 , int y){
		int hour, min , r;
		int i, j;
		float houra, mina;
		hour = x0;
		min = x1 + y;
		if (min >= 60){
			hour = x0 + (min) / 60;
			min = min % 60;
		}
		hour = hour % 12;
		houra = hour * 30.0 + min*0.5;
		mina = min * 6;
		angle = houra - mina;
		if (angle < 0.0){
			angle = -angle;
		}
		if (angle > 180){
			angle = 360 - angle;
		}
		if (angle < 0){
			angle = angle + 360;
		}
	}
	void out(){
		cout << angle << endl;
	}

private:
	float angle;
};

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	stdu quiz;
	int i , j , y;
	char judge;
	while (1){
		cin >> i;
		cin >> judge;
		cin >> j;
		if (i == 24){
			break;
		}
		cin >> y;
		quiz.in(i , j , y);
		quiz.out();
	}
	//system("pause");
	return 0;
}
