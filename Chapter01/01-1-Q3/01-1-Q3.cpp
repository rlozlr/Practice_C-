#include <iostream>

using namespace std;

// 숫자를 하나 입력 받아서 그 숫자에 해당하는 구구단을 출력 

int main()
{
	int num;
	int i = 0;
	cout << "출력할 구구단은 몇 단? (숫자 입력) >>> ";
	cin >> num;
	cout << endl;

	cout << "[" << num << "단]" << endl;
	for (int i = 1; i <= 9; i++) {
		cout << num << " X " << i << " = " << num * i << endl;
	}
}