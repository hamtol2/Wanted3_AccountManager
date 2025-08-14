#include <iostream>
#include "Bank.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// 메뉴 열겨형.
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

	// 은행.
	Bank bank;

	// 파일에서 데이터 로드.
	bank.Load("Save.txt");

	// 메뉴 선택 입력 받기.
	char tempBuffer[10] = {};

	// 메뉴 번호 값 저장용 변수.
	int menuNumber = 0;

	while (true)
	{
		bank.PrintMenu();

		std::cin >> tempBuffer;
		if (strcmp(tempBuffer, "q") == 0)
		{
			// 파일에 계좌 정보 저장.
			bank.Save("Save.txt");

			// 종료.
			return 0;
		}

		// 입력 값 확인.
		if (menuNumber = atoi(tempBuffer))
		{
			// 유효한 경우.
			if (menuNumber >= 1 && menuNumber <= 4)
			{
				// 숫자 입력 값을 열거형으로 변환.
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
	
		std::cout << "메뉴 입력이 잘못됐습니다.\n";
	}
}