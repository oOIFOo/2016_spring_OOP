#include <iostream>
#include <string>

using namespace std;

class BigInteger {
public:
	BigInteger(string a) {
		int j;
		int count;
		count = 0;
		//int size_;
		size = a.size();
		for (int i = 29; i >= 0; i--) {
			//for (int i = 0; i < size; i++) {
			num[i] = 0;
		}
		//cout << size << endl;
		//size_ = size;
		for (int i = size - 1; i >= 0; i--) {
		//for (int i = 0; i < size; i++) {
			num[i] = a[count] - '0';
			count++;
		}
	//	cout << "*******************************************" << endl;
	//	for (int i = 0; i < size; i++)
	//	{
	//		cout << num[i] << endl;
	//	}
	//	cout << "*******************************************" << endl;

	}

	BigInteger operator +(const BigInteger& com) {
		//BigInteger *ans = new  BigInteger();
		int j;
		int temp;
		BigInteger x = *this;
		for (j = 0; j < 30; j++) {
		//	cout << x.num[j];
			x.num[j] = x.num[j] + com.num[j];
		//	cout << " + " << com.num[j] << " == " << x.num[j] << endl;
			if (x.num[j] >= 10) {
				x.num[j] = x.num[j] - 10;
				x.num[j + 1] = x.num[j + 1] + 1;
			}
		}
		return x;
	}
	bool operator >(const BigInteger& com) {
		int j;
		int y = 1;
		if (size > com.size) {
			return true;
		}
		if (size < com.size) {
			return false;
		}
		if (size == com.size) {
			for (j = size - 1; j > 0; j--) {
				if (num[j] > com.num[j]) {
					return true;
					y = 0;
					break;
				}
				if (num[j] < com.num[j]) {
					return false;
					y = 0;
					break;
				}
			}
			if (y == 0) {
				return false;
			}
		}
	}
	bool operator <(const BigInteger& com) {
		int j;
		int y = 1;
		if (size > com.size) {
			return false;
		}
		if (size < com.size) {
			return true;
		}
		if (size == com.size) {
			for (j = size - 1; j > 0; j--) {
				if (num[j] > com.num[j]) {
					return false;
					y = 0;
					break;
				}
				if (num[j] < com.num[j]) {
					return true;
					y = 0;
					break;
				}
			}
			if (y == 0) {
				return false;
			}
		}
	}
	bool operator !=(const BigInteger& com) {
		int j;
		int y = 0;
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
		for (j = 0; j < 30; j++) {
			//cout << x.num[j];
			x.num[j] = x.num[j] + com.num[j];
			//cout << " + " << com.num[j] << " == " << x.num[j] << endl;
			if (x.num[j] >= 10) {
				x.num[j] = x.num[j] - 10;
				x.num[j + 1] = x.num[j + 1] + 1;
			}
		}
		size = com.size;
		for (j = 0; j < 30; j++) {
			num[j] = x.num[j];
		}
		return x;
	}

	bool operator==(const BigInteger& com) {
		int j;
		int y = 0;
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
		if (com.num[com.size] != 0) {
			out << com.num[com.size];
		}
		for (int j = com.size - 1; j >= 0; j--) {
			out << com.num[j];
		}
		//printSize();
		return out;
	}
public:
	int num[30];
	int numlen[2];
	int size;
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
		cout << (myBigInt1 + myBigInt2) << endl;
		myBigInt2 += myBigInt1;
		cout << myBigInt2 << endl;
		cout << ++myBigInt2 << endl;
		cout << myBigInt1++ << endl;
		cout << myBigInt1 << endl;
	}
	return 0;
}
