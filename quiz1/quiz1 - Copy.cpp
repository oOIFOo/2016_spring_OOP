#include <iostream>
#include <iomanip>

using namespace std;
class ctof{
public:
	float degree;
	void com(float degree){
		anser = degree*(9.0/5.0)+32.0;
	};
	void print(void){
		cout << anser;
	}
private:
	float anser;
};
class ftoc{
public:
	ftoc(){
		degree = 0.0;
	}
	float degree ;
	void com(float degree){
		anser = (degree-32.0)*(5.0/9.0);
	}
	void print(void){
		cout << anser;
	}
private:
	float anser;
};
int main()
{
	ctof c_to_f;
	ftoc f_to_c;
	int start = 0;
	float degree = 0.0;
	cin >> start;
	if (start == 0){
		cin >> degree;
		c_to_f.com(degree);
		c_to_f.print();
	}
	if (start == 1){
		cin >> degree;
		f_to_c.com(degree);
		f_to_c.print();
	}
//	system("pause");
	return 0;
}
