#include "CreditAccount.h"

CreditAccount::CreditAccount(int id, const char* name, int balance)
	: Account(id, name, balance + (int)(balance * 0.01f))
{
	type = AccountType::CreditAccount;
}

void CreditAccount::Deposit(int money)
{
	Account::Deposit(money + (int)(money * 0.01f));
}

void CreditAccount::Print()
{
	std::cout << "�ſ� ���� == ";
	std::cout << "���� ID: " << id << " | ";
	std::cout << "�̸�: " << name << " | ";
	std::cout << "�ܾ�: " << balance << "\n";
}