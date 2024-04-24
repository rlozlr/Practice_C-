/*
다음 세 함수를 0이상 100미만의 난수를 총 5개 생성하는 예제를 만들되, C++의 헤더를 선언해서 작성해보자.
참고로 C언어의 경우 time 함수는 <time.h>에 선언되어 있고, 
rand 함수와 strand 함수는 <stdlib.h>에 선언되어 있다.
rand, srand, time
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	// srand : 무작위의 수를 만들건데
	// time(null) : 매번 새롭게 만들어줘
	srand(time(NULL));

	for (int i = 0; i < 5; i++) {
		// rnad() % 100 : 0부터 99까지의 랜덤 숫자 생성
		std::cout << i + 1 << ". " << rand() % 100 << std::endl;
	}
	return 0;
}