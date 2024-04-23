#include <iostream>

using namespace std;

/*
예제 DefaultValue3.cpp에 정의되 함수 BoxVolumne은 '매개변수의 디폴트 값 지정'형태가 아닌,
'함수 오버로딩'의 형태로 재구현해보자.
물론 main 함수는 변경되지 않아야하며, 실행결과도 동일해야한다.
*/

//int BoxVolume(int length, int width = 1, int height = 1);

//'함수 오버로딩'의 형태로 재구현 
int BoxVolume(int length, int width, int height) {
	return length * width * height;
}

int BoxVolume(int length, int width) {
	return length * width * 1;
}

int BoxVolume(int length) {
	return length * 1 * 1;
}

int main(void)
{
	cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << endl;
	cout << "[5, 5, D] : " << BoxVolume(5, 5) << endl;
	cout << "[5, D, D] : " << BoxVolume(7) << endl;
	//cout << "[D, D, D] : " << BoxVolume() << endl;

	return 0;
}

//int BoxVolume(int length, int width, int height) {
//	return length * width * height;
//}