#pragma once

// 전방 선언.
class Account;
class Bank
{
public:
	Bank();
	~Bank();

	// 메뉴 출력.
	void PrintMenu();

	// 계좌 관련 기능.
	void CreateAccount();
	void Deposit();
	void Withdraw();
	void Inquire();

private:
	// 계좌 최대 수.
	static const int accountCount = 100;

	// 계좌.
	Account* accounts[accountCount] = { };

	// 생성된 계좌 수.
	int count = 0;
};