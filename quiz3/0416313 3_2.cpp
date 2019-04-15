// NCTU OOP lab - Quiz Three
// Q2 - Email Generator Part.2
//
// Name:OIFO
// Student ID:0416313
#include <iostream>
#include <string>
using namespace std;

class case2{
public:
	void find(string &a){
	int local;
	string email;
	int i;
	cin >> email;
	local = email.find('@');
	a = email.substr(local, email.size() );
	for (i = local-1; i >= 0; i--){
		cout << email[i];
	}
	}
private:
	int num;
};
int main() {
	case2 quiz2;
	int t1, t2;
	int h , r;
	int num = 1;
	string ans;
	cin >> h;
	for (t1 = 0; t1 < h; t1++){
		cin >> r;
		num = 1;
		for (t2 = 0; t2 < r; t2++){
			quiz2.find(ans);
			cout << ".cs" << num << ans << endl;
			num++;
		}
	}
	return 0;
}
