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

void Bank::Save(const char* filename)
{
	// ������ ������ ����.
	// 1. ������ ������ �ִ� ��� ���·κ��� ����ȭ�� ���ڿ� ���� ����.
	// 2. ���Ͽ� ���.
	// ���׷��̵� ������ ����.
	const int bufferSize = 4096;
	char buffer[bufferSize] = {};
	for (int ix = 0; ix < count; ++ix)
	{
		// ����ȭ�� ���ڿ� ������.
		const char* data = accounts[ix]->Serialize();

		// ����ȭ�� ���ڿ��� ���� ���ڿ��� ���ϱ�.
		strcat_s(buffer, sizeof(buffer), data);
		delete data;
	}

	// ���Ͽ� ���.
	FILE* file = nullptr;
	fopen_s(&file, filename, "wb");
	if (file == nullptr)
	{
		std::cerr << "������ ���� ���߽��ϴ�.\n";
		return;
	}

	// ������ ���Ͽ� ����� ������ ũ�� Ȯ��.
	size_t dataLength = strlen(buffer);

	// ���Ͽ� ����.
	fwrite(buffer, sizeof(char), dataLength, file);
	fclose(file);
}

void Bank::Load(const char* filename)
{
	FILE* file = nullptr;
	fopen_s(&file, filename, "rt");
	if (file == nullptr)
	{
		std::cerr << "������ ���� ���߽��ϴ�.\n";
		return;
	}

	// ���� ����.
	const int bufferSize = 1024;
	char buffer[bufferSize] = { };

	while (!feof(file))
	{
		// ���پ� �б�.
		fgets(buffer, bufferSize, file);

		// ���Ͽ��� ���� �����Ͱ� ������ ����.
		if (!buffer)
		{
			break;
		}

		// ���� Ÿ�� Ȯ��.
		int accountType = -1;
		sscanf_s(buffer, "type: %d", &accountType);

		// ���� ���� ����.
		int id = 0;
		char name[50] = {};
		int balance = 0;

		// ���� Ÿ�Ժ��� ó��.
		switch ((AccountType)accountType)
		{
			// ���� Ÿ�� ������ �߸��ǰų� ������ ���� ���.
			case AccountType::None:
				fclose(file);
				return;

			case AccountType::Account:
			{
				sscanf_s(
					buffer,
					"type: %d id: %d name: %s balance: %d",
					&accountType, &id, name, 50, &balance
				);

				// ���� ����.
				accounts[count++] = new Account(id, name, balance);
			} break;

			case AccountType::CreditAccount:
			{
				sscanf_s(
					buffer,
					"type: %d id: %d name: %s balance: %d",
					&accountType, &id, name, 50, &balance
				);

				// ���� ����.
				accounts[count++] = new CreditAccount(id, name, balance, false);
			} break;

			case AccountType::DonationAccount:
			{
				int donationAmount = 0;

				sscanf_s(
					buffer,
					"type: %d id: %d name: %s balance: %d donationAmount: %d",
					&accountType, &id, name, 50, &balance, &donationAmount
				);

				// ���� ����.
				auto account = new DonationAccount(id, name, balance, false);
				
				// ���Ͽ��� ���� ��ξ� ����.
				account->SetDonationAmount(donationAmount);

				// ���� �߰�.
				accounts[count++] = account;

			} break;
		}

		// ���� ����.
		memset(buffer, 0, sizeof(char) * bufferSize);
	}

	// ���� �ݱ�.
	fclose(file);
}