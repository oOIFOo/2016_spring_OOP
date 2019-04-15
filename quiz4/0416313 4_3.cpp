// NCTU OOP lab - Quiz Four
// Q3 - Unique Element
//
// Name:
// Student ID:
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <istream>
#include<sstream>
using namespace std;

class stdu{
public:
	void in(){
		int a, b , x;
		string put;
		a = 0;
		vec1.clear();
		vec.clear();
		getline(cin , input);
		while (1){
			b = input.find(' ');
			if (b < 0){
				istringstream is(input);
				is >> x;
				vec.push_back(x);
				break;
			}
			put = input.substr(a , b);
			istringstream is(put);
			is >> x;
			vec.push_back(x);
			input = input.substr(b+1);
		//	cout << input << endl;
		}
	}

	void com(){
		int i , j , count , a;
		j = 1;
		a = vec[0];
		if (vec[0] != vec[1]){
			vec1.push_back(vec[0]);
		}
		for (i = 1; i < ( vec.size()-1 );i++){
			if (a == vec[i]){
				continue;
			}
			if (vec[i] == vec[i + 1]){
				a = vec[i];
				continue;
			}
			vec1.push_back(vec[i]);
		}
		if (vec[vec.size()-1] != vec[vec.size() - 2]){
			if(vec.size() != 1){
				vec1.push_back(vec[vec.size() - 1]);
			}
		}
	}
	void sort0(){
		int i;
		i = vec.size();
		sort(vec.begin() , vec.end());
	}
	void out(){
		int i;
		if (vec1.empty() == 1){
			if(vec.size() == 1){
				cout << vec[0];
			}
			else{
				cout << "Not found";
			}
		}
		else{
			for (i = 0; i < vec1.size()-1; i++){
					cout << vec1[i] << " ";
			}
			cout << vec1[i];
		}
		cout << endl;
	}
	string input;
	vector<int> vec;
	vector<int> vec1;
};

int main() {
	int i;
	stdu quiz;
	cin >> i;
	fflush(stdin);
	for (; i > 0; i--){
		quiz.in();
		quiz.sort0();
		quiz.com();
		quiz.out();
		fflush(stdin);
	}
//	system("pause");
	return 0;
}
