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
	std::cout << "기부 계좌 == ";
	std::cout << "계좌 ID: " << id << " | ";
	std::cout << "이름: " << name << " | ";
	std::cout << "잔액: " << balance << " | ";
	std::cout << "총 기부액: " << donationAmount << "\n";
}

const char* DonationAccount::Serialize()
{
	// 문자열로 정보를 출력하기 위한 버퍼 생성.
	const int bufferSize = 1024;
	char* buffer = new char[bufferSize];
	memset(buffer, 0, sizeof(char) * bufferSize);

	// 문자열 조합.
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