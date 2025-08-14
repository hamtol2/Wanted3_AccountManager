#include "DonationAccount.h"

DonationAccount::DonationAccount(int id, const char* name, int balance)
	: Account(id, name, balance - (int)(balance * 0.01f)), donationAmount((int)(balance * 0.01f))
{
	type = AccountType::DonationAccount;
}

void DonationAccount::Deposit(int money)
{
	Account::Deposit(money - (int)(money * 0.01f));
	donationAmount += (int)(money * 0.01f);
}

void DonationAccount::Print()
{
	std::cout << "��� ���� == ";
	std::cout << "���� ID: " << id << " | ";
	std::cout << "�̸�: " << name << " | ";
	std::cout << "�ܾ�: " << balance << " | ";
	std::cout << "�� ��ξ�: " << donationAmount << "\n";
}