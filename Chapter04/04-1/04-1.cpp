﻿/*
Chapter 03에서 제시한 과일장수 시뮬레이션 예제 FruitSaleSim1.cpp에서 정의한 두 클래스의 멤버변수는 
private으로 선언이 되어있다. 그러나 다음 조건을 유지할 수 있는 장치는 아무것도 되어있지 않다.
	- 사과의 구매를 목적으로 0보다 작은 수를 전달할 수 없다.
위의 제약사항을 항상 만족시킬 수 있도록 예제를 변경하고, 예제의 안전성을 높일 수 있도록 일부 함수를 const로 선언해보자.
*/

//FruitSaleSim1.cpp
#include <iostream>
using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money)
	{
		APPLE_PRICE=price;
		numOfApples=num;
		myMoney=money;
	}
	int SaleApples(int money)
	{
		if (money < 0) {	// 사과의 구매를 목적으로 0보다 작은 수를 전달할 수 없다.
			cout << "잘못된 금액입니다." << endl;
			return 0;
		}

		int num=money/APPLE_PRICE;
		numOfApples-=num;
		myMoney+=money;
		return num;
	}
	void ShowSalesResult() const	// 예제의 안전성을 높일 수 있도록 함수를 const로 선언
	{
		cout<<"남은 사과: "<<numOfApples<<endl;
		cout<<"판매 수익: "<<myMoney<<endl<<endl;
	}
};

class FruitBuyer
{
	int myMoney;		// private:
	int numOfApples;	// private:

public:
	void InitMembers(int money)
	{
		myMoney=money;
		numOfApples=0;
	}
	void BuyApples(FruitSeller &seller, int money)
	{
		if (money < 0) {	// 사과의 구매를 목적으로 0보다 작은 수를 전달할 수 없다.
			cout << "잘못된 금액입니다." << endl;
			return;
		}

		numOfApples+=seller.SaleApples(money);
		myMoney-=money;
	}
	void ShowBuyResult() const	// 예제의 안전성을 높일 수 있도록 함수를 const로 선언
	{
		cout<<"현재 잔액: "<<myMoney<<endl;
		cout<<"사과 개수: "<<numOfApples<<endl<<endl;
	}
};

int main(void)
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);

	cout<<"과일 판매자의 현황"<<endl;
	seller.ShowSalesResult();
	cout<<"과일 구매자의 현황"<<endl;
	buyer.ShowBuyResult();
	return 0;
}