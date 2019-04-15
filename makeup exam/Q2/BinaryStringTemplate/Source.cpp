#include<iostream>
#include<string>
using namespace std;

class binaryString
{
public:
	binaryString();
	friend ostream& operator<<(std::ostream& os, const binaryString& obj);
	friend istream& operator>>(std::istream& is, binaryString& obj);
	binaryString operator+(const binaryString& right)const;
	binaryString operator-(const binaryString& right)const;

	string binStr;
	int ans[100];
	int sizeofans = 0;
};
binaryString::binaryString()
{
	for (int i = 0; i < 100; i++){
		ans[i] = 0;
	}
}
binaryString binaryString::operator+(const binaryString& right)const{
	binaryString A = *this;
	binaryString tmp;
	int carry = 0;
	for (int i = 0;;){
		if (carry == 0 && (i >= A.binStr.size()) && (i >= right.binStr.size())){
			break;
		}
		tmp.ans[i] = A.ans[i] + right.ans[i] + carry;
		//cout << tmp.ans[i] << " = " << A.ans[i] << " + " << right.ans[i] << " + " << carry << endl;
		carry = 0;
		//system("pause");
		if (tmp.ans[i] > 1){
			carry = 1;
			tmp.ans[i] %= 2;
		}
		tmp.sizeofans++;
		i++;
	}
	return tmp;
}
binaryString binaryString::operator-(const binaryString& right)const{
	binaryString A = *this;
	binaryString tmp;
	int carry = 0;
	if (A.binStr == right.binStr){
		return tmp;
	}
	for (int i = 0;;){
		if (carry == 0 && (i >= A.binStr.size()) && (i >= right.binStr.size())){
			break;
		}
		tmp.ans[i] = A.ans[i] - right.ans[i] + carry;
	//	cout << tmp.ans[i] << " = " << A.ans[i] << " - " << right.ans[i] << " + " << carry << endl;
		carry = 0;
	//	system("pause");
		if (tmp.ans[i] < 0){
			carry = -1;
			tmp.ans[i] += 2;
		}
		i++;
	}




	for (int j = 100; j >= 0; j--){
		if (tmp.ans[j] != 0){
			tmp.sizeofans = j + 1;
			break;
		}
	}
	return tmp;
}
ostream& operator<<(std::ostream& os, const binaryString &obj)
{
	int x;
	int zero = 0;
	x = obj.binStr.length() - 1;
	for (int i = obj.sizeofans - 1; i >= 0; i--){
		cout << obj.ans[i];
		zero = 1;
	}
	if (zero == 0){
		cout << "0" << endl;
	}
	return os;
}
istream& operator>>(std::istream& is, binaryString& obj)
{
	int x;
	cin >> obj.binStr;
	x = obj.binStr.length() - 1;
	for (int i = 0; i < obj.binStr.length(); i++){
		obj.ans[i] = obj.binStr[x - i] - '0';
	}
	return is;
}

int main(){
	binaryString A;
	binaryString B;
	binaryString C;
	binaryString D;

	cin >> A;
	cin >> B;
	cout << A + B << endl;
	cin >> C;
	cin >> D;
	cout << C - D << endl;


	system("pause");
	return 0;
}