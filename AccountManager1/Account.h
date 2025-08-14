#pragma once

#include <iostream>

// 계좌 타입.
enum class AccountType
{
	// 특별한 목적으로 사용하고 싶을때.
	None = -1,
	Account = 1,
	CreditAccount,
	DonationAccount
};

class Account
{
public:
	Account();
	Account(int id, const char* name, int balance);
	Account(const Account& other);
	virtual ~Account();

	// 입금.
	virtual void Deposit(int money);

	// 출금.
	virtual bool Withdraw(int money);

	// 정보 출력.
	virtual void Print();

	// 계좌 정보를 문자열로 직렬화하는 함수.
	virtual const char* Serialize();

	// Getter.
	inline int GetID() const { return id; }
	inline const char* GetName() const { return name; }
	inline int GetBalance() { return balance; }

protected:
	// 고객 ID.
	int id = 0;

	// 이름.
	char* name = nullptr;

	// 잔액.
	int balance = 0;

	// 계좌 타입.
	AccountType type = AccountType::None;
};