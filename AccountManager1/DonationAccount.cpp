#include "DonationAccount.h"

DonationAccount::DonationAccount(int id, const char* name, int balance, bool donate)
	: Account(id, name, 0)/*, donationAmount((int)(balance * 0.01f))*/
{
	type = AccountType::DonationAccount;
	this->balance = donate ? balance - (int)(balance * 0.01f) : balance;
	donationAmount = donate ? (int)(balance * 0.01f) : 0;
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

const char* DonationAccount::Serialize()
{
	// ���ڿ��� ������ ����ϱ� ���� ���� ����.
	const int bufferSize = 1024;
	char* buffer = new char[bufferSize];
	memset(buffer, 0, sizeof(char) * bufferSize);

	// ���ڿ� ����.
	sprintf_s(
		buffer,
		bufferSize,
		"type: %d id: %d name: %s balance: %d donationAmount: %d\n",
		(int)type, id, name, balance, donationAmount
	);

	return buffer;
}

void DonationAccount::SetDonationAmount(int amount)
{
	donationAmount = amount;
}