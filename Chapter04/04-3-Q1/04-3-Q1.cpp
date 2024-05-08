/*
앞서 제시한 문제 04-2를 해결하였는가?
당시만 해도 생성잘르 설명하지 않은 상황이기 때문에 별도의 초기화 함수를 정의 및 호출해서
Point, Circle, Ring 클래스의 객체를 초기화하였다.
이때 구현한 답에 대해서 모든 클래스에 생성자를 정의해보자.
*/
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x, int y) :xpos(x), ypos(y)
	{	}
	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle
{
private:
	Point center;
	int rad;
public:
	Circle(int x, int y, int r) : center(x, y)
	{
		rad = r;
	}
	void ShowCircleInfo() const
	{
		cout << "radius: " << rad << endl;
		center.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle innerCircle;
	Circle outerCircle;
public:
	Ring(int inX, int inY, int inR, int outX, int outY, int outR)
		:innerCircle(inX, inY, inR), outerCircle(outX, outY, outR)
	{	}
	void ShowRingInfo() const
	{
		cout << "Inner Circle Info..." << endl;
		innerCircle.ShowCircleInfo();
		cout << "Outer Circle Info..." << endl;
		outerCircle.ShowCircleInfo();
	}
};

int main(void)
{
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}