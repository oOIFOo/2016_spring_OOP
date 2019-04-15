#include <iostream>
#include <iomanip>

using namespace std;
class fibon{
public:
	void start(void){
		anser[0] = 0;
		anser[1] = 1;
	};
	void com(void){
		int i = 2 , n = 100;
		while (i < n){
			anser[i] = anser[i - 1] + anser[i - 2];
			i++;
		}
	};
	void print(int n){
		cout << anser[n - 1];
	}
private:
	int anser[100];
};
int main(void){
	fibon fib;
	int want = 0;
	cin >> want;
	fib.start();
	fib.com();
	fib.print(want);
//	system("pause");
	return 0;
}
