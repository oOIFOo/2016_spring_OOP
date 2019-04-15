#include <iostream>
using namespace std;
class case_2{
public:
	int i;
	int y = 4;
	void fir(void){
		for (i = 0; i < 5; i++){
			ans[i] = 11;
		}
		y = 4;
	}
	void com(int x){
		while (1){
			i = x % 16;
			x = x / 16;
			if (i > 9){
				if (i == 10){
					ser[y] = 'A';
				}
				if (i == 11){
					ser[y] = 'B';
				}
				if (i == 12){
					ser[y] = 'C';
				}
				if (i == 13){
					ser[y] = 'D';
				}
				if (i == 14){
					ser[y] = 'E';
				}
				if (i == 15){
					ser[y] = 'F';
				}
				if (i == 16){
					ser[y] = 'G';
				}
				ans[y] = 12;
			}
			if (i <= 9){
				ans[y] = i;
			//	cout << ans << endl;
			}
			y--;
			if (x == 0){
				break;
			}
		}
	}
	void print(void){
		int w = 0;
		for (w = 0; w<5; w++){
			if (ans[w] == 11){
				continue;
			}
			else if (ans[w] == 12){
				cout << ser[w];
			}
			else{
				cout << ans[w];
			}
		}
	}
private:
	int number;
	int ans[5];
	char ser[5];
};

int main() {
	int h, r;
	int num;
	case_2 case2;
	cin >> r;
	for (h = 0; h < r; h++){
		cin >> num;
		case2.fir();
		case2.com(num);
		case2.print();
		cout << endl;
	}
	system("pause");
	return 0;
}
