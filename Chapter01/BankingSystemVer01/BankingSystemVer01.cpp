#include <iostream>
#include <cstring>	//strcpy 사용하기 위해서

using namespace std;
const int NAME_LEN = 20; // 이름 길이

//Func : java에서 Method 같은 것
/*
0. 메뉴
1. 계좌개설
2. 입금
3. 출금
4. 계좌정보 전체 출력
5. 프로그램 종료
*/
void ShowMenu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void AllAccountInfo();

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT}; // SWITCH CASE에서 1,2,3,4처럼 쓰기 위해 사용

// java의 VO Class 같은 느낌으로 씀
typedef struct
{
	int accountID;	// 계좌번호
	int balance;	// 잔액
	char customerName[NAME_LEN];	// 고객명
} Account;

Account accountArr[100];	// Account 저장을 위한 배열
int accountNum = 0;	// 저장된 Account 수

int main()
{
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE: MakeAccount(); break;
		case DEPOSIT: DepositMoney(); break;
		case WITHDRAW: WithdrawMoney(); break;
		case INQUIRE: AllAccountInfo(); break;
		case EXIT: return 0;
		default: cout << "잘못된 번호 입니다." << endl;
		}
	}
	return 0;
}

void ShowMenu()
{
	cout << endl;
	cout << "----Menu----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입   금" << endl;
	cout << "3. 출   금" << endl;
	cout << "4. 계좌정보" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "이름: ";	cin >> name;
	cout << "입금액: ";	cin >> balance;
	cout << endl;

	accountArr[accountNum].accountID = id;
	accountArr[accountNum].balance = balance;
	strcpy(accountArr[accountNum].customerName, name); // char[] 라서 strcpy로 복사해서 저장한다.
	accountNum++;

}

void DepositMoney()
{
	int id;
	int money;
	cout << "[입   금]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "입금액: ";	cin >> money;

	for (int i = 0; i < accountNum; i++)
	{
		if (accountArr[i].accountID == id)
		{
			accountArr[i].balance += money;
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "계좌가 존재하지 않습니다." << endl << endl;
}

void WithdrawMoney()
{
	int id;
	int money;
	cout << "[출   금]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "출금액: ";	cin >> money;

	for (int i = 0; i < accountNum; i++)
	{
		if (accountArr[i].accountID == id)
		{
			if (accountArr[i].balance < money)
			{
				cout << "잔액이 부족합니다." << endl << endl;
				return;
			}
			accountArr[i].balance -= money;
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "계좌가 존재하지 않습니다." << endl << endl;
}

void AllAccountInfo()
{
	for (int i = 0; i < accountNum; i++)
	{
		cout << "계좌ID: " << accountArr[i].accountID << endl;
		cout << "이름: " << accountArr[i].customerName << endl;
		cout << "잔액: " << accountArr[i].balance << endl;
	}
}

