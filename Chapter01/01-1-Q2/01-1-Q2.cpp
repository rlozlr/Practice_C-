#include <iostream>

/*
프로그램 사용자로부터 이름과 전화번호를 문자열의 형태로 입력 받아서,
입력 받은 데이터를 그대로 출력하는 프로그램을 작성
*/

int main()
{
    char name[100];
    char mobile[100];

    std::cout << "이름 : ";
    std::cin >> name;
    std::cout << "전화번호 : ";
    std::cin >> mobile;

    std::cout << "\n[사용자 정보]\n";
    std::cout << "이름 : " << name << std::endl;
    std::cout << "전화번호 : " << mobile << std::endl;
}