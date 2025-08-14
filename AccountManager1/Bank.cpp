#include "Bank.h"
#include "Account.h"
#include "CreditAccount.h"
#include "DonationAccount.h"

Bank::Bank()
{
}

Bank::~Bank()
{
	// �޸� ����.
	for (int ix = 0; ix < count; ++ix)
	{
		// null check.
		// nullptr -> 0. 0->false, �������� true.
		if (accounts[ix] /*!= nullptr*/)
		{
			delete accounts[ix];
			accounts[ix] = nullptr;
		}
	}
}

void Bank::PrintMenu()
{
	std::cout << "=======�޴�=======\n";
	std::cout << "1. ���� ����\n";
	std::cout << "2. �Ա�\n";
	std::cout << "3. ���\n";
	std::cout << "4. �ܾ� ��ȸ\n";
	std::cout << "q. ���α׷� ����\n";
}

void Bank::CreateAccount()
{
	int id = 0;
	char name[50] = {};
	int balance = 0;
	int accountType = 0;

	// �Է� ���� �ӽ� ����.
	char tempBuffer[255] = {};

	// ���� Ÿ�� ���� ����.
	while (true)
	{
		std::cout << "������ ���� ����====\n";
		std::cout << "1. �Ϲ� ����\n";
		std::cout << "2. �ſ� ����\n";
		std::cout << "3. ��� ����\n";
		std::cout << "   ����: ";

		// �Է� �ޱ�.
		std::cin >> tempBuffer;

		// �Է� �� Ȯ��.
		if (accountType = atoi(tempBuffer))
		{
			if (accountType >= 1 && accountType <= 3)
			{
				break;
			}

			std::cout << "���� ������ �߸��ϼ̽��ϴ�.\n";
		}
		else
		{
			std::cout << "���ڸ� �Է� �����մϴ�.\n";
		}
	}

	std::cout << "���� ����-------\n";
	while (true)
	{
		std::cout << "���� ID: ";
		std::cin >> tempBuffer;

		// ����ó��(�Է� �� Ȯ��).
		if (id = atoi(tempBuffer))
		{
			break;
		}

		std::cout << "ID�� ���ڸ� �Է� �����մϴ�.\n";
	}

	// �̸� �Է� �ޱ�.
	std::cout << "�̸�: ";
	std::cin >> name;

	// �Աݾ� �Է� �ޱ�.
	while (true)
	{
		std::cout << "�Աݾ�: ";
		std::cin >> tempBuffer;

		if (balance = atoi(tempBuffer))
		{
			break;
		}

		std::cout << "�Աݾ��� ���ڸ� �Է� �����մϴ�.\n";
	}

	// ���� ����.
	AccountType type = (AccountType)accountType;
	switch (type)
	{
	case AccountType::Account:
		{
			accounts[count++] = new Account(id, name, balance);
		} break;
	case AccountType::CreditAccount:
		{
			accounts[count++] = new CreditAccount(id, name, balance);
		} break;
	case AccountType::DonationAccount:
		{
			accounts[count++] = new DonationAccount(id, name, balance);
		} break;
	}

	std::cout << "\n";
}

void Bank::Deposit()
{
	// ���� ����.
	int id = 0;
	int money = 0;

	// �ӽù���(���� Ȯ�ο�).
	char tempBuffer[256];

	while (true)
	{
		std::cout << "ID: ";
		std::cin >> tempBuffer;

		if (id = atoi(tempBuffer))
		{
			break;
		}

		std::cout << "ID�� ���ڸ� �Է� �����մϴ�.\n";
	}

	while (true)
	{
		std::cout << "�Աݾ�: ";
		std::cin >> tempBuffer;

		if (money = atoi(tempBuffer))
		{
			break;
		}

		std::cout << "�Աݾ� ���ڸ� �Է� �����մϴ�.\n";
	}

	// �Ա� ó��.
	// ���� �˻�.
	for (Account* account : accounts)
	{
		// null check.
		if (account == nullptr)
		{
			continue;
		}

		// �ƴϸ� �ǳʶٱ�.
		if (account->GetID() != id)
		{
			continue;
		}

		// ã�� ���.
		account->Deposit(money);
		std::cout << "�ԱݿϷ�\n";
		return;
	}

	// �˻� ����.
	std::cout << "��ȿ���� ���� ID�Դϴ�.\n\n";
}

void Bank::Withdraw()
{
	// ���� ����.
	int id = 0;
	int money = 0;

	// �ӽù���(���� Ȯ�ο�).
	char tempBuffer[256];

	while (true)
	{
		std::cout << "ID: ";
		std::cin >> tempBuffer;

		if (id = atoi(tempBuffer))
		{
			break;
		}

		std::cout << "ID�� ���ڸ� �Է� �����մϴ�.\n";
	}

	while (true)
	{
		std::cout << "��ݾ�: ";
		std::cin >> tempBuffer;

		if (money = atoi(tempBuffer))
		{
			break;
		}

		std::cout << "��ݾ� ���ڸ� �Է� �����մϴ�.\n";
	}

	// �Ա� ó��.
	// ���� �˻�.
	for (Account* account : accounts)
	{
		// null check.
		//if (account == nullptr)
		if (!account)
		{
			continue;
		}

		// �ƴϸ� �ǳʶٱ�.
		if (account->GetID() != id)
		{
			continue;
		}

		// ã�� ���.
		// �ܾ� Ȯ��.
		//if (account->GetBalance() < money)
		//{
		//	std::cout 
		//		<< "�ܾ��� �����մϴ�. ���� �ܾ��� "
		//		<< account->GetBalance() 
		//		<< "�� �Դϴ�.\n";
		//	return;
		//}

		if (account->Withdraw(money))
		{
			std::cout << "��ݿϷ�\n";
			return;
		}

		return;
	}

	// �˻� ����.
	std::cout << "��ȿ���� ���� ID�Դϴ�.\n\n";
}

void Bank::Inquire()
{
	// ��� ���� ���� ���.
	for (Account* const account : accounts)
	{
		if (!account)
		{
			continue;
		}

		account->Print();
	}

	std::cout << "\n";
}