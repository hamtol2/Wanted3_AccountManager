#include <iostream>
#include "Bank.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// �޴� ������.
enum class MenuType
{
	CreateAccount = 1,
	Deposit,
	Withdraw,
	Inquire,
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// ����.
	Bank bank;

	// ���Ͽ��� ������ �ε�.
	bank.Load("Save.txt");

	// �޴� ���� �Է� �ޱ�.
	char tempBuffer[10] = {};

	// �޴� ��ȣ �� ����� ����.
	int menuNumber = 0;

	while (true)
	{
		bank.PrintMenu();

		std::cin >> tempBuffer;
		if (strcmp(tempBuffer, "q") == 0)
		{
			// ���Ͽ� ���� ���� ����.
			bank.Save("Save.txt");

			// ����.
			return 0;
		}

		// �Է� �� Ȯ��.
		if (menuNumber = atoi(tempBuffer))
		{
			// ��ȿ�� ���.
			if (menuNumber >= 1 && menuNumber <= 4)
			{
				// ���� �Է� ���� ���������� ��ȯ.
				MenuType type = static_cast<MenuType>(menuNumber);

				switch (type)
				{
				case MenuType::CreateAccount:
					bank.CreateAccount();
					break;

				case MenuType::Deposit:
					bank.Deposit();
					break;

				case MenuType::Withdraw:
					bank.Withdraw();
					break;

				case MenuType::Inquire:
					bank.Inquire();
					break;
				}
			}
		}
	
		std::cout << "�޴� �Է��� �߸��ƽ��ϴ�.\n";
	}
}