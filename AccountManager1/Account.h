#pragma once

#include <iostream>

// ���� Ÿ��.
enum class AccountType
{
	// Ư���� �������� ����ϰ� ������.
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

	// �Ա�.
	virtual void Deposit(int money);

	// ���.
	virtual bool Withdraw(int money);

	// ���� ���.
	virtual void Print();

	// ���� ������ ���ڿ��� ����ȭ�ϴ� �Լ�.
	virtual const char* Serialize();

	// Getter.
	inline int GetID() const { return id; }
	inline const char* GetName() const { return name; }
	inline int GetBalance() { return balance; }

protected:
	// �� ID.
	int id = 0;

	// �̸�.
	char* name = nullptr;

	// �ܾ�.
	int balance = 0;

	// ���� Ÿ��.
	AccountType type = AccountType::None;
};