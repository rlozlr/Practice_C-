/*
다음 표준함수를 호출하는 예제를 만들되, C++의 헤더를 선언해서 만들어보자.
그리고 예제의 내용은 상관이 없지만, 아래의 함수들을 최소 1회 이상 호출해야 한다.
참고로 다음 함수들은 C언어의 경우 <string.h>에 선언되어 있다.
	- strlen : 문자열의 길이 계산
	- strcat : 문자열의 뒤에 덧붙이기
	- strcpy : 문자열 복사
	- strcmp : 문자열의 비교
*/
#include <iostream>
#include <cstring>

int main()
{
	const char* str1 = "Hi";
	const char* str2 = "hi";
	char str3[1000];

	std::cout << "str1: " << str1 << std::endl;
	std::cout << "str2: " << str2 << std::endl;
	std::cout << "str1 length: " << strlen(str1) << std::endl;
	std::cout << "str2 length: " << strlen(str2) << std::endl;

	strcpy_s(str3, str1);
	std::cout << "st1을 복사한 str3: " << str3 << std::endl;
	
	strcat_s(str3, str2);
	std::cout << "거기에 str2을 덧붙임: " << str3 << std::endl;

	// java에서 equals와 같고 둘 다 대소문자 구분함
	if (strcmp(str1, str2) == 0) {
		std::cout << "str1 == str2" << std::endl;
	} else {
		std::cout << "str1 != str2" << std::endl;
	}
	return 0;
}
