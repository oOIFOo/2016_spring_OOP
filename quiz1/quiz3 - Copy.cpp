#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int main(void){
	int start = 0;
	float width = 0.0, height = 0.0, radius = 0.0, area = 0.0, perimeter = 0.0, pi = 3.14;
	cin >> start;
	if (start == 0){
		cin >> width;
		cin >> height;
		area = width*height;
		perimeter = 2 * (width + height);
		cout << area << endl;
		cout << perimeter;
	}
	if (start == 1){
		cin >> width;
		cin >> height;
		area = width*height / 2;
		perimeter = width + 2 * sqrt(width*width / 4 + height*height);
		cout << area << endl;
		cout << perimeter;
	}
	if (start == 2){
		cin >> radius;
		area = radius*radius*pi;
		perimeter = 2 * pi * radius;
		cout << area << endl;
		cout << perimeter;
	}
//	system("pause");
	return 0;
}
