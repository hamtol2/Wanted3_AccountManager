#include "Account.h"

Account::Account()
	: Account(0, nullptr, 0)
{
}

Account::Account(int id, const char* name, int balance)
	: id(id), balance(balance), type(AccountType::Account)
{
	// ����ó��.
	this->balance = balance <= 0 ? 0 : balance;
	//if (balance <= 0)
	//{
	//	this->balance = 0;
	//}
	//else
	//{
	//	this->balance = balance;
	//}

	// ����ó��.
	if (name == nullptr)
	{
		return;
	}

	// �����Ҵ� �� �̸� �� ����.
	size_t length = strlen(name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, name);
}

Account::Account(const Account& other)
	: id(other.id), balance(other.balance)
{
	// �����Ҵ� �� �̸� �� ����.
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
	// ����ó��.
	// Silent is violent.
	if (money <= 0)
	{
		std::cout << "�Աݾ��� 0������ Ŀ���մϴ�.\n";
		return;
	}

	// �ܾ׿� �߰� �Ա�.
	balance += money;
}

bool Account::Withdraw(int money)
{
	// ���.
	if (money <= 0)
	{
		std::cout << "��ݾ��� 0������ Ŀ���մϴ�.\n";
		return false;
	}

	// �ܾ׿��� ���.
	if (balance < money)
	{
		std::cout << "�ܾ��� �����մϴ�.\n";
		return false;
	}

	// ��� ó��.
	balance -= money;
	return true;
}

void Account::Print()
{
	std::cout << "�Ϲ� ���� == ";
	std::cout << "���� ID: " << id << " | ";
	std::cout << "�̸�: " << name << " | ";
	std::cout << "�ܾ�: " << balance << "\n";
}

const char* Account::Serialize()
{
	// ���ڿ��� ������ ����ϱ� ���� ���� ����.
	const int bufferSize = 1024;
	char* buffer = new char[bufferSize];
	memset(buffer, 0, sizeof(char) * bufferSize);

	// ���ڿ� ����.
	sprintf_s(
		buffer,
		bufferSize,
		"type: %d id: %d name: %s balance: %d\n",
		(int)type, id, name, balance
	);

	return buffer;
}