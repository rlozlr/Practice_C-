/*
다음과 같은 형태로의 함수 오버로딩은 문제가 있다.
어떠한 문제가 있는지 설명해보자.
*/

int SimpleFunc(int a = 10)
{
	return a + 1;
}
int SimpleFunc(void)
{
	return 10;
}

// 풀이
/*
int SimpleFunc(int a = 10) 함수와 int SimpleFunc(void) 함수는 모두 SimpleFunc()로 사용할 수 있기 때문에
SimpleFunc()를 선언했을 때, 둘 중 어떤 함수를 사용해야할지 모르게 되어 에러가 발생한다.
*/