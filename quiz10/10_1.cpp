#include <iostream>
#include <string>
using namespace std;

template <typename T>
class NODE
{
public:
	T value;
	NODE* next;
};

template <typename T>
void bubblesort(NODE<T> *data, int number , int type)
{
		NODE<T> *head = data;
		NODE<T> *x0 , *y0;
		T tmp;
		for (int i = 0; i < number; i++){
			head = data;
			x0 = head;
			y0 = x0->next;
			for (int j = 0;j < number - 1; j++){
				head = data;
				if (x0->value > y0->value){
					tmp = y0->value;
					y0->value = x0->value;
					x0->value = tmp;
				}
				x0 = x0->next;
				y0 = y0->next;
			}
		}
}

int main()
{
	//tmpNode is used to add element
	NODE<int> *tmpNodeInt = NULL;
	NODE<float> *tmpNodeFloat = NULL;
	NODE<string> *tmpNodeString = NULL;

	//headNode always points to the first element
	NODE<int> *headNodeInt = tmpNodeInt;
	NODE<float> *headNodeFloat = tmpNodeFloat;
	NODE<string> *headNodeString = tmpNodeString;

	// add code here.
	// Please use Linked-List to store value!!!

	// input number
	// input type      (0 int  ; 1 float ; 2 string)
	// input elements
	int x0;
	float x1;
	string x2;
	int type , number;
	while (cin >> type){
		cin >> number;
		switch (type)
		{
		case 0:
			//cin >> number;
			for (int i = 0; i < number; i++){
				cin >> x0;
				if (headNodeInt == NULL){
					headNodeInt = new NODE<int>;
					headNodeInt->value = x0;
					headNodeInt->next = NULL;
					tmpNodeInt = headNodeInt;
				}
				else{
					NODE<int> *y = NULL;
					y = new NODE<int>;
					y->value = x0;
					y->next = NULL;
					tmpNodeInt->next = y;
					tmpNodeInt = y;
				}
			}
			break;
		case 1:
			for (int i = 0; i < number; i++){
				cin >> x1;
				if (headNodeFloat == NULL){
					headNodeFloat = new NODE<float>;
					headNodeFloat->value = x1;
					headNodeFloat->next = NULL;
					tmpNodeFloat = headNodeFloat;
				}
				else{
					NODE<float> *y = NULL;
					y = new NODE<float>;
					y->value = x1;
					y->next = NULL;
					tmpNodeFloat->next = y;
					tmpNodeFloat = y;
				}
			}
			break;
		case 2:
			for (int i = 0; i < number; i++){
				cin >> x2;
				if (headNodeString == NULL){
					headNodeString = new NODE<string>;
					headNodeString->value = x2;
					headNodeString->next = NULL;
					tmpNodeString = headNodeString;
				}
				else{
					NODE<string> *y = NULL;
					y = new NODE<string>;
					y->value = x2;
					y->next = NULL;
					tmpNodeString->next = y;
					tmpNodeString = y;
				}
			}
			break;

		}


		switch (type)
		{
		case 0:
			bubblesort(headNodeInt, number, 0);
			for (int i = 0; i < number - 1; i++){
				cout << headNodeInt->value << " ";
				headNodeInt = headNodeInt->next;
			}
			cout << headNodeInt->value << endl;
			break;
		case 1:
			//cout << "0";
			bubblesort(headNodeFloat, number, 1);
			for (int i = 0; i < number - 1; i++){
				cout << headNodeFloat->value << " ";
				headNodeFloat = headNodeFloat->next;
			}
			cout << headNodeFloat->value << endl;
			break;
		case 2:
			bubblesort(headNodeString, number, 2);
			for (int i = 0; i < number - 1; i++){
				cout << headNodeString->value << " ";
				headNodeString = headNodeString->next;
			}
			cout << headNodeString->value << endl;
			break;
		}
		// add code here.
		// print all the elements

		//system("pause");
		//return 0;
		tmpNodeInt = NULL;
		tmpNodeFloat = NULL;
		tmpNodeString = NULL;
		headNodeInt = tmpNodeInt;
		headNodeFloat = tmpNodeFloat;
		headNodeString = tmpNodeString;
	}
	return 0;
}
