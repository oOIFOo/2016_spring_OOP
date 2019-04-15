// NCTU OOP lab - Quiz Three
// Q1 - Simple Calculator
//
// Name:OIFO
// Student ID:0416313
#include <iostream>
#include <vector>
using namespace std;

class SimpleCalculator {
public:
	SimpleCalculator() {}
	~SimpleCalculator() {}
	void add(int x, int *y, float &ans){
		ans = x + *y;
		//return ans;
	}
	void sub(int x, int *y, float &ans){
		int y1 = *(y + 1);
		ans = x - y1;
	}
	void mul(int x, int *y, float &ans){
		int y1 = *(y + 2);
		ans = x*(y1);
	}
	void div(int x, int *y, float &ans){
		float y1 = *(y + 3);
		ans = x / y1;
	}
private:

};

int main() {
	SimpleCalculator myCalculator;
	int arr_1[4];
	vector<int> arr_2;
	int input;

	for (int i = 0; i < 4; i++) {
		cin >> input;
		arr_1[i] = input;
	}
	for (int i = 0; i < 4; i++) {
		cin >> input;
		arr_2.push_back(input);
	}

	float value = 0.0;
	myCalculator.add(arr_1[0], &arr_2[0], value);
	cout << value << " ";
	myCalculator.sub(arr_1[1], &arr_2[0], value);
	cout << value << " ";
	myCalculator.mul(arr_1[2], &arr_2[0], value);
	cout << value << " ";
	myCalculator.div(arr_1[3], &arr_2[0], value);
	cout << value << endl;
	system("pause");
	return 0;
}
