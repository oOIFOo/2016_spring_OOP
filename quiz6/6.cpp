#include <iostream>
#include <string>

using namespace std;

class BigInteger {
public:
	BigInteger() {
	}
	BigInteger(string a) {
		int j;
		int count;
		count = 0;
		size = a.size();
		negative = false;
		if (a[0] == '-'){
			negative = true;
			count++;
			//size--;
		}
		for (int i = 29; i >= 0; i--) {
			num[i] = 0;
		}
		if (negative == true){
			for (int i = size - 2; i >= 0; i--) {
				num[i] = a[count] - '0';
				count++;
			}
		}
		count = 0;
		if (negative == false){
			for (int i = size - 1; i >= 0; i--) {
				num[i] = a[count] - '0';
				count++;
			}
		}
	}

	BigInteger operator +(const BigInteger& com) {
		if (negative == com.negative) {
			int len1, len2;
			int tmp[100] = { 0 };
			len1 =size;
			len2 = com.size;
			int last = 0;
			int i;
			for (i = 0;; i++) {
				if (len1 != 0) {
					tmp[i] += num[len1 - 1];
					len1--;
				}
				if (len2 != 0) {
					tmp[i] += com.num[len2 - 1];
					len2--;
				}
				tmp[i] += last;
				last = tmp[i] / 10;
				tmp[i] %= 10;
				tmp[i] += 0;
				if (len1 == 0 && len2 == 0 && last == 0)break;
			}
			BigInteger ans;
			for (int n = i; n >= 0; n--) {
				ans.num[i] += tmp[n];
			}
			ans.negative = negative;
			return ans;
		}
		else {
			BigInteger a;
			for (int i = 0; i < 30; i++) {
				a.num[i] = num[i];
			}
			a.negative = negative;
			BigInteger b;
			for (int i = 0; i < 30; i++) {
				b.num[i] = com.num[i];
			}
			b.negative = com.negative;
			if (a.num == b.num) {
				a.num = "0";
				a.negative = 0;
				return a;
			}
			if (stringcompare(b.num, a.num) == 1) {
				BigInteger tmp;
				tmp = a;
				a = b;
				b = tmp;
			}
			int len1 = a.num.size(), len2 = b.num.size();
			char tmp[100] = { 0 };
			int i, last = 0;
			for (i = 0;; i++) {
				tmp[i] += a.num[len1 - 1] - '0';
				len1--;
				if (len2 != 0) {
					tmp[i] -= (b.num[len2 - 1] - '0');
					len2--;
				}
				if (last == 1) {
					last = 0;
					tmp[i]--;
				}
				if (tmp[i] < 0) {
					last = 1;
					tmp[i] += 10;
				}
				tmp[i] += '0';
				if (len1 == 0)break;
			}
			BigInteger ans;
			int start = 0;
			for (int n = i; n >= 0; n--) {
				if (start == 0) {
					if (tmp[n] == '0')continue;
					else start = 1;
				}
				ans.num += tmp[n];
			}
			ans.minus = a.minus;
			return ans;
		}
	}
	BigInteger operator -(const BigInteger& com) {
		int i , j;
		int temp;
		BigInteger x = *this;
		if (x.negative != com.negative){
			BigInteger y = com;
			if (x.negative == true){
				y.negative = true;
				x = x + y;
			}
			if (x.negative == false){
				y.negative = false;
				x = x + y;
			}
			return x;
		}
		if (x > com){
			temp = x.size;
			cout << "********************************" << endl;
			for (j = 0; j < 30; j++){
			//	cout << x.num[j];
				x.num[j] = x.num[j] - com.num[j];
			//	cout << " - " << com.num[j] << " == " << x.num[j] << endl;
				if (x.num[j] < 0){
					for (i = j + 1; i < temp; i++){
						x.num[i]--;
						if (x.num[i] <= 0){
							x.num[i] = 9;
							continue;
						}
						break;
					}
					x.num[j] = x.num[j] + 10;
				}
			}
			return x;
		}
		if (x < com){
			BigInteger y = com;
		//	cout << "********************************" << endl;
			temp = y.size;
			for (j = 0; j < 0; j--){
				//cout << y.num[j];
				y.num[j] = y.num[j] - x.num[j];
				//cout << " - " << x.num[j] << " == " << y.num[j] << endl;
				if (y.num[j] < 0){
					for (i = j + 1; i < temp; i++){
						y.num[i]--;
						if (y.num[i] <= 0){
							y.num[i] = 9;
							continue;
						}
						break;
					}
					y.num[j] = y.num[j] + 10;
				}
			}
			y.negative = true;
			return y;
		}
		if (x == com){
			return 0;
		}
		return 0;
	}
	bool operator >(const BigInteger& com) {
		int j;
		int y = 1;
		if (negative > com.negative){
			return false;
		}
		if (negative < com.negative){
			return true;
		}
		if (negative == com.negative){
			if (size < com.size) {
				y = 0;
			}
			if (size > com.size) {
				y = 1;
			}
			if (size == com.size) {
				//cout << "**********************************" << endl;
				for (j = size - 1; j > 0; j--) {
					if (num[j] > com.num[j]) {
						y = 1;
						break;
					}
					if (num[j] < com.num[j]) {
						y = 0;
						break;
					}
				}
			}
			if (negative == true){
				if (y == 0){
					y = 1;
				}
				else if (y == 1){
					y = 0;
				}
			}
			if (y == 0) {
				return false;
			}
			if (y == 1){
				return true;
			}
		}
	}
	bool operator <(const BigInteger& com) {
		int j;
		int y = 1;
		if (negative > com.negative){
			return true;
		}
		if (negative < com.negative){
			return false;
		}
		if (negative == com.negative){
			if (size < com.size) {
				y = 0;
			}
			if (size > com.size) {
				y = 1;
			}
			if (size == com.size) {
				//cout << "**********************************" << endl;
				for (j = size - 1; j > 0; j--) {
					if (num[j] > com.num[j]) {
						y = 1;
						break;
					}
					if (num[j] < com.num[j]) {
						y = 0;
						break;
					}
				}
			}
			if (negative == true){
				if (y == 0){
					y = 1;
				}
				else if (y == 1){
					y = 0;
				}
			}
			if (y == 0) {
				return true;
			}
			if (y == 1){
				return false;
			}
		}
	}
	bool operator !=(const BigInteger& com) {
		int j;
		int y = 0;
		if (negative != com.negative){
			return true;
		}
		if (size == com.size) {
			for (j = 0; j < 30; j++) {
				if (num[j] != com.num[j]) {
					return true;
					y = 1;
					break;
				}
			}
		}
		if (y == 0) {
			return true;
		}
	}

	BigInteger operator ++(int) {
		int j;
		BigInteger x = *this;
		num[0] = num[0] + 1;
		for (j = 0; j < 30; j++) {
			if (num[j] < 10) {
				break;
			}
			if (num[j] >= 10) {
				num[j] = num[j] - 10;
				num[j + 1] = num[j + 1] + 1;
			}
		}
		return x;
	}

	BigInteger& operator ++() {
		int j;
		BigInteger x = *this;
		num[0] = num[0] + 1;
		for (j = 0; j < 30; j++) {
			if (num[j] < 10) {
				break;
			}
			if (num[j] >= 10) {
				num[j] = num[j] - 10;
				num[j + 1] = num[j + 1] + 1;
			}
		}
		//cout << "  ";
		return *this;
	}

	BigInteger operator +=(const BigInteger& com) {
		BigInteger x = *this;
		int j;
		/*for (j = 0; j < 30; j++) {
			//cout << x.num[j];
			x.num[j] = x.num[j] + com.num[j];
			//cout << " + " << com.num[j] << " == " << x.num[j] << endl;
			if (x.num[j] >= 10) {
				x.num[j] = x.num[j] - 10;
				x.num[j + 1] = x.num[j + 1] + 1;
			}
		}
		size = com.size;*/
		x = x + com;
		for (j = 0; j < 30; j++) {
			num[j] = x.num[j];
		}
		return x;
	}

	bool operator==(const BigInteger& com) {
		int j;
		int y = 0;
		if (negative != com.negative){
			return false;
		}
		if (size == com.size) {
			for (j = size; j > 0; j--) {
				if (num[j] != com.num[j]) {
					return false;
					y = 1;
					break;
				}
			}
		}
		if (size != com.size) {
			y = 1;
			return false;
		}
		if (y == 0) {
			return true;
		}
	}

	friend ostream& operator<<(ostream& out, const BigInteger& com) {
		if (com.negative == true){
			out << "-";
		}
		if (com.num[com.size] != 0) {
			out << com.num[com.size];
		}

		for (int j = com.size - 1; j >= 0; j--) {
			if (com.num[j] == 0){
				continue;
			}
			out << com.num[j];
		}
		return out;
	}
public:
	int num[30];
	int numlen[2];
	int size;
	bool negative;
	bool temp_negative;
};

int main() {
	string number1, number2;
	while (cin >> number1 >> number2) {
		BigInteger myBigInt1(number1);
		BigInteger myBigInt2(number2);

		cout << (myBigInt1 > myBigInt2) << endl;
		cout << (myBigInt1 < myBigInt2) << endl;
		cout << (myBigInt1 == myBigInt2) << endl;
		cout << (myBigInt1 != myBigInt2) << endl;

		cout << (myBigInt1 - myBigInt2) << endl;
		cout << (myBigInt1 + myBigInt2) << endl;

	/*	myBigInt2 += myBigInt1;
		cout << myBigInt2 << endl;
		/*cout << ++myBigInt2 << endl;
		cout << myBigInt1++ << endl;
		cout << myBigInt1 << endl;

		cout << (myBigInt1 - myBigInt2) << endl;

		/*myBigInt2 -= myBigInt1;
		cout << myBigInt2 << endl;
		cout << --myBigInt2 << endl;
		cout << myBigInt1-- << endl;
		cout << myBigInt1 << endl;*/
	}
	return 0;
}