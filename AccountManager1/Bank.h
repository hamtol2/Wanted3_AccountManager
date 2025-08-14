#pragma once

// ���� ����.
class Account;
class Bank
{
public:
	Bank();
	~Bank();

	// �޴� ���.
	void PrintMenu();

	// ���� ���� ���.
	void CreateAccount();
	void Deposit();
	void Withdraw();
	void Inquire();

private:
	// ���� �ִ� ��.
	static const int accountCount = 100;

	// ����.
	Account* accounts[accountCount] = { };

	// ������ ���� ��.
	int count = 0;
};