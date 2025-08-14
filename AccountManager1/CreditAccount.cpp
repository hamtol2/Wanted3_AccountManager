#include "CreditAccount.h"

CreditAccount::CreditAccount(int id, const char* name, int balance, bool giveInterest)
	: Account(id, name, 0)
{
	type = AccountType::CreditAccount;
	this->balance = giveInterest ? balance + (int)(balance * 0.01f) : balance;
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