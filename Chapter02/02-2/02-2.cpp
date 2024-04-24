#include <iostream>
/*
const 포인터에 대한 복습을 겸할 수 있는 문제를 제시하겠다.
다음의 상수선언을 보자.
const int num=12;
포인터 변수를 선언해서 위 변수를 가리키게 해보자. 
그리고 이 포인터 변수를 참조하는 참조자를 하나 선언하자.
마지막으로 이렇게 선언된 포인터 변수와 참조자를 이용해서 num에 저장된 값을 출력하는 예제를 완성해보자.
*/
int main()
{
	const int num = 12;
	//포인터 변수를 선언해서 위 변수를 가리키게 해보자.
	const int *ptr = &num;
	//이 포인터 변수를 참조하는 참조자를 하나 선언하자.
	const int *(&ref) = ptr;
	//이렇게 선언된 포인터 변수와 참조자를 이용해서 num에 저장된 값을 출력
	std::cout << "num에 저장된 값: " << *ptr << std::endl;
	std::cout << "num에 저장된 값: " << *ref << std::endl;
}