﻿#include <iostream>
using namespace std;

// SwapPointer 함수
void SwapPointer(int *(&ptr1), int *(&ptr2))
{
	int* tmp = ptr1;
	ptr1 = ptr2;
	ptr2 = tmp;
}

int main(void)
{
	int num1 = 5;
	int *ptr1 = &num1;
	int num2 = 10;
	int *ptr2 = &num2;

	cout << *ptr1 << endl;
	cout << *ptr2 << endl;
	cout << "SwapPointer 후" << endl;

	SwapPointer(ptr1, ptr2);
	cout << *ptr1 << endl;
	cout << *ptr2 << endl;

}

/*
위 코드를 보면 ptr1과 ptr2가 각각 num1과 num2를 가리키고 있다.
이 때 ptr1과 ptr2를 대상으로 다음과 같이 함수를 호출하고 나면,
SwapPointer(ptr1, ptr2);
ptr1과 ptr2가 가리키는 대상이 서로 바뀌도록 SwapPointer 함수를 정의해보자.
*/

