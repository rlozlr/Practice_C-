/*
1. v.01에서 구조체 Account를 클래스 Account로 변경
	- "어떻게 캡슐화를 시키고 정보를 은닉시켜야 할까?"
	- "생성자와 소멸자는 어떻게 정의해야 할까?"

2. 고객의 이름을 동적 할당의 형태로 구현
	- Account 클래스는 멤버변수로 문자열 포인터(char형 포인터)를 지니고 있어야 한다.

3. 객체 배열을 선언하지 말고, 객체 포인터 배열을 선언해서 객체를 저장
*/
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void ShowAllAccInfo();

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account
{
private:
	int accID;
	int balance;
	char* cusName;
public:
	Account(int ID, int money, char* name)
		: accID(ID), balance(money)
	{
		cusName = new char[strlen(name) + 1]; // 문자열의 끝에는 항상 null 문자 ('\0')이 있기 때문에 +1
		strcpy(cusName, name);
	}

	int GetAccID() { return accID; }

	void Deposit(int money)
	{
		balance += money;
	}

	int Withdraw(int money)
	{
		if (balance < money)
			return 0;

		balance -= money;
		return money;
	}

	void ShowAccInfo()
	{
		cout << "계좌ID: " << accID << endl;
		cout << "이  름: " << cusName << endl;
		cout << "잔  액: " << balance << endl;
	}

	~Account()
	{
		delete[]cusName;
	}
};

Account* accArr[100];	// Account 저장
int accNum = 0;

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
		case INQUIRE: ShowAllAccInfo(); break;
		case EXIT: return 0;
		default:
			cout << "잘못된 접근입니다." << endl;
		}
	}

	for (int i = 0; i < accNum; i++)
		delete accArr[i];
	return 0;
}

void ShowMenu()
{
	cout << "----Menu----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입   금" << endl;
	cout << "3. 출   금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

// 업데이트 된 Method
void MakeAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이  름: "; cin >> name;
	cout << "입금액: "; cin >> balance;

	accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney()
{
	int money;
	int id;
	cout << "[입  금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void WithdrawMoney()
{
	int money;
	int id;
	cout << "[출    금]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "출금액: ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i] -> GetAccID() == id)
		{
			if (accArr[i] -> Withdraw(money) == 0)
			{
				cout << "잔액부족" << endl << endl;
				return;
			}

			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i] -> ShowAccInfo();
		cout << endl;
	}
}

