#include "Account.h"

Account::Account()
	: Account(0, nullptr, 0)
{
}

Account::Account(int id, const char* name, int balance)
	: id(id), balance(balance), type(AccountType::Account)
{
	// 예외처리.
	this->balance = balance <= 0 ? 0 : balance;
	//if (balance <= 0)
	//{
	//	this->balance = 0;
	//}
	//else
	//{
	//	this->balance = balance;
	//}

	// 예외처리.
	if (name == nullptr)
	{
		return;
	}

	// 동적할당 및 이름 값 복사.
	size_t length = strlen(name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, name);
}

Account::Account(const Account& other)
	: id(other.id), balance(other.balance)
{
	// 동적할당 및 이름 값 복사.
	size_t length = strlen(other.name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, other.name);
}

Account::~Account()
{
	if (name == nullptr)
	{
		return;
	}

	delete[] name;
	name = nullptr;
}

void Account::Deposit(int money)
{
	// 예외처리.
	// Silent is violent.
	if (money <= 0)
	{
		std::cout << "입금액은 0원보다 커야합니다.\n";
		return;
	}

	// 잔액에 추가 입금.
	balance += money;
}

bool Account::Withdraw(int money)
{
	// 출금.
	if (money <= 0)
	{
		std::cout << "출금액은 0원보다 커야합니다.\n";
		return false;
	}

	// 잔액에서 출금.
	if (balance < money)
	{
		std::cout << "잔액이 부족합니다.\n";
		return false;
	}

	// 출금 처리.
	balance -= money;
	return true;
}

void Account::Print()
{
	std::cout << "일반 계좌 == ";
	std::cout << "계좌 ID: " << id << " | ";
	std::cout << "이름: " << name << " | ";
	std::cout << "잔액: " << balance << "\n";
}

const char* Account::Serialize()
{
	// 문자열로 정보를 출력하기 위한 버퍼 생성.
	const int bufferSize = 1024;
	char* buffer = new char[bufferSize];
	memset(buffer, 0, sizeof(char) * bufferSize);

	// 문자열 조합.
	sprintf_s(
		buffer,
		bufferSize,
		"type: %d id: %d name: %s balance: %d\n",
		(int)type, id, name, balance
	);

	return buffer;
}