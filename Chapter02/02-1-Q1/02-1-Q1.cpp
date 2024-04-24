#include <iostream>
using namespace std;

/*
참조자를 이용해서 다음 요구사항에 부합하는 함수를 각각 정의하여라.
	- 인자로 전달된 int형 변수의 값을 1씩 증가시키는 함수
	- 인자로 전달된 int형 변수의 부호를 바꾸는 함수
그리고 위의 각 함수를 호출하여 그 결과를 확인하는 main 함수까지 작성하여라.
*/

void incrementFunc(int &num)
{
	num++;
}

void changeSign(int& num)
{
	num *= -1;
}

int main()
{
	int num = 10;

	incrementFunc(num);
	cout << num << endl;
	
	changeSign(num);
	cout << num << endl;

}