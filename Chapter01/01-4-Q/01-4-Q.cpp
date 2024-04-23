﻿/*
C++을 제대로 공부하려면 다음의 내용을 잘 알고 있어야 한다.
	- 헤더파일의 의미와 정의 방법
	- 헤더파일에 삽입할 내용과 소스파일에 삽입할 내용을 구분하는 방법
	- 둘 이상의 헤더파일과 소스파일을 만들어서 하나의 실행파일로 컴파일하는 방법

이와 관련해서 전혀 감이 없다면, C언어 기본서를 참조하여 이 부분을 복습하기 바라며,
감이 좀 있다면, 앞으로 조금씩 그 감을 살려나가기 바란다.
그럼 헤더파일, 그리고 파일분할과 관련된 감을 살리기 위해서 앞서 소개한 예제 NameSp2.cpp를 
다음과 같이 총 3개의 파일로 분할해서 컴파일해보자.
	- 헤더파일 : main 함수를 제외한 나머지 두 함수의 선언을 삽입
	- 소스파일1 : main 함수를 제외한 나머지 두 함수의 정의를 삽입
	- 소스파일2 : main 함수만 삽입

파일의 이름은 여러분이 임의로 정해도 된다. 
하지만, 각 파일에 들어갈 내용은 위의 지시대로 진행해야 한다.
*/

//NameSp2.cpp 코드
//#include <iostream>
//
//using namespace std;
//
//namespace BestComImpl
//{
//	void SimpleFunc(void);
//}
//
//namespace ProgComImpl
//{
//	void SimpleFunc(void);
//}
//
//int main(void)
//{
//	BestComImpl::SimpleFunc();
//	ProgComImpl::SimpleFunc();
//	return 0;
//}
//
//void BestComImpl::SimpleFunc(void)
//{
//	cout << "BestCom이 정의한 함수" << endl;
//}
//
//void ProgComImpl::SimpleFunc(void)
//{
//	cout << "ProgCom이 정의한 함수" << endl;
//}
