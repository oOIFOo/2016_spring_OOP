#include<iostream>
using namespace std;

class case_1{
	public:
		int x;
		int i = 0,j = 0,k = 0;
		void mid(int x){
			for (i = 0; i < x; i++){
				cin >> stdent[i];
			}
		}
		void sort(int x){
			for (i = 0; i < x; i++){
				for (j = 0;  j < (x-1); j++){
					if (stdent[ j]>stdent[j + 1]){
						k = stdent[ j + 1];
						stdent[ j + 1] = stdent[ j];
						stdent[j] = k;
					}
				}
			}
			//cout << stdent[1];
		}
		void print(int x){
			if (x == 0){
				cout << "0" << endl;
			}
			if (x % 2 == 0){
				ans = (stdent[(x / 2)] + (stdent[ (x / 2) - 1]) ) /2.0;
			//	cout << stdent[(x / 2)];
			//	cout << stdent[(x / 2)-1];
				cout << ans<< endl;
			}
			if (x % 2 == 1){
				ans = stdent[( (x - 1) / 2)];
				cout << ans << endl;
			}
		}
	private:
		int stdent[10];
		float ans;
};

int main(void){
	case_1 case1;
	int r;
	int i;
	int num;
	cin >> r;
	for (i = 0; i < r;i++){
		cin >> num;
	//	cout << num;
		if (num == 0){
			cout << "0" << endl;
			continue;
		}
		case1.mid(num);
		case1.sort(num);
		case1.print(num);
	}
	//system("pause");
	return 0;
}
