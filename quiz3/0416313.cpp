// NCTU OOP lab - Quiz Three
// Q3 - String Sorting
//
// Name:OIFO
// Student ID:0416313
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int d = 0;
int times = 0;
int compare[10] = {0};
string word[10];
void read(int w,int d){
	char x;
	int y = 0,i = 0;
	for(i = 0;i < w;i++){
		cin >> word[times];
		x = word[times][d];
		y = (int)x;
		if (65 <= y && y <= 90){
			compare[times] = 100 - y;
		}
		if (48 <= y && y <= 57){
			compare[times] = (-1) * y;
		}
		if (97 <= y && y <= 122){
			compare[times] = -2*y;
		}
	//	cout << y << endl;
		cout << compare[times] << endl;
		times++;
	}	
}

void sort(int num, int j1 ){
	string change;
	int i = 0;
	int j = 0;
	int k = 0;
	int x , y;
	for(i = 0;i < num;i++){
		for(j = j1;j< num -1;j++){
			if(compare[j] < compare[j+1]){
				k = compare[j];
				compare[j] = compare[j + 1];
				compare[j + 1] = k;
				change = word[j];
				word[j] = word[j + 1];
				word[j + 1] = change;
			}
			if(compare[j] == compare[j+1]){
				x = compare[j];
				y = compare[j + 1];
				d++;
				times = j;
				read(2,d);	
				sort(2 , j);
				compare[j] = x;
				compare[j + 1] = y;
			}
		}
	}
}

void print(int t){
	int i = 0;
	for(i = 0;i < t;i++){
		cout << word[i] << endl;
	}
}
int main() {
	int num , r;
	cin >> num;
	read(num,0);
	sort(num , 0);
	print(num);
	system("pause");
	return 0;
}
