#include <iostream>

/*
사용자로부터 총 5개의 정수를 입력 받아서, 그 합을 출력하는 프로그램을 작성
단, 프로그램의 실행은 다음과 같이 이루어져 있다.

[실행의 예]

1번째 정수 입력 : 1
2번째 정수 입력 : 2
3번째 정수 입력 : 3
4번째 정수 입력 : 4
5번째 정수 입력 : 5
합계: 15
*/

int main()
{
	int num;
	int i = 0;
	int sum = 0;

	for (int i = 1; i <= 5; i++) {
		std::cout << i << "번째 정수 입력: ";
		std::cin >> num;
		sum += num;
	}
	std::cout << "합계: " << sum;
}