/*
앞서 소개한 예제 RefSwap.cpp의 SwapByRef2 함수를 다음의 형태로 호출하면 컴파일 에러가 발생한다.
SwapByRef(23, 45);
컴파일 에러가 발생하는 이유가 무엇인지 설명해보자
*/

//RefSwap.cpp
//#include <iostream>
//using namespace std;
//
//void SwapByRef2(int& ref1, int& ref2)
//{
//	int temp = ref1;
//	ref1 = ref2;
//	ref2 = temp;
//}
//
//int main(void)
//{
//	int val1 = 10;
//	int val2 = 20;
//
//	SwapByRef2(val1, val2);
//	cout << "val1: " << val1 << endl;
//	cout << "val2: " << val2 << endl;
//	return 0;
//}

//풀이
/*
참조자는 상수를 참조할 수 없으므로 반드시 변수를 통해 값을 받아야한다.
*/