#include "Bank.h"
#include "Account.h"
#include "CreditAccount.h"
#include "DonationAccount.h"

Bank::Bank()
{
}

Bank::~Bank()
{
	// 메모리 해제.
	for (int ix = 0; ix < count; ++ix)
	{
		// null check.
		// nullptr -> 0. 0->false, 나머지는 true.
		if (accounts[ix] /*!= nullptr*/)
		{
			delete accounts[ix];
			accounts[ix] = nullptr;
		}
	}
}

void Bank::PrintMenu()
{
	std::cout << "=======메뉴=======\n";
	std::cout << "1. 계좌 개설\n";
	std::cout << "2. 입금\n";
	std::cout << "3. 출금\n";
	std::cout << "4. 잔액 조회\n";
	std::cout << "q. 프로그램 종료\n";
}

void Bank::CreateAccount()
{
	int id = 0;
	char name[50] = {};
	int balance = 0;
	int accountType = 0;

	// 입력 받을 임시 버퍼.
	char tempBuffer[255] = {};

	// 계좌 타입 선택 루프.
	while (true)
	{
		std::cout << "개설할 계좌 선택====\n";
		std::cout << "1. 일반 계좌\n";
		std::cout << "2. 신용 계좌\n";
		std::cout << "3. 기부 계좌\n";
		std::cout << "   선택: ";

		// 입력 받기.
		std::cin >> tempBuffer;

		// 입력 값 확인.
		if (accountType = atoi(tempBuffer))
		{
			if (accountType >= 1 && accountType <= 3)
			{
				break;
			}

			std::cout << "계좌 선택을 잘못하셨습니다.\n";
		}
		else
		{
			std::cout << "숫자만 입력 가능합니다.\n";
		}
	}

	std::cout << "계좌 개설-------\n";
	while (true)
	{
		std::cout << "계좌 ID: ";
		std::cin >> tempBuffer;

		// 예외처리(입력 값 확인).
		if (id = atoi(tempBuffer))
		{
			break;
		}

		std::cout << "ID는 숫자만 입력 가능합니다.\n";
	}

	// 이름 입력 받기.
	std::cout << "이름: ";
	std::cin >> name;

	// 입금액 입력 받기.
	while (true)
	{
		std::cout << "입금액: ";
		std::cin >> tempBuffer;

		if (balance = atoi(tempBuffer))
		{
			break;
		}

		std::cout << "입금액은 숫자만 입력 가능합니다.\n";
	}

	// 계좌 생성.
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
	// 계좌 정보.
	int id = 0;
	int money = 0;

	// 임시버퍼(오류 확인용).
	char tempBuffer[256];

	while (true)
	{
		std::cout << "ID: ";
		std::cin >> tempBuffer;

		if (id = atoi(tempBuffer))
		{
			break;
		}

		std::cout << "ID는 숫자만 입력 가능합니다.\n";
	}

	while (true)
	{
		std::cout << "입금액: ";
		std::cin >> tempBuffer;

		if (money = atoi(tempBuffer))
		{
			break;
		}

		std::cout << "입금액 숫자만 입력 가능합니다.\n";
	}

	// 입금 처리.
	// 계좌 검색.
	for (Account* account : accounts)
	{
		// null check.
		if (account == nullptr)
		{
			continue;
		}

		// 아니면 건너뛰기.
		if (account->GetID() != id)
		{
			continue;
		}

		// 찾은 경우.
		account->Deposit(money);
		std::cout << "입금완료\n";
		return;
	}

	// 검색 실패.
	std::cout << "유효하지 않은 ID입니다.\n\n";
}

void Bank::Withdraw()
{
	// 계좌 정보.
	int id = 0;
	int money = 0;

	// 임시버퍼(오류 확인용).
	char tempBuffer[256];

	while (true)
	{
		std::cout << "ID: ";
		std::cin >> tempBuffer;

		if (id = atoi(tempBuffer))
		{
			break;
		}

		std::cout << "ID는 숫자만 입력 가능합니다.\n";
	}

	while (true)
	{
		std::cout << "출금액: ";
		std::cin >> tempBuffer;

		if (money = atoi(tempBuffer))
		{
			break;
		}

		std::cout << "출금액 숫자만 입력 가능합니다.\n";
	}

	// 입금 처리.
	// 계좌 검색.
	for (Account* account : accounts)
	{
		// null check.
		//if (account == nullptr)
		if (!account)
		{
			continue;
		}

		// 아니면 건너뛰기.
		if (account->GetID() != id)
		{
			continue;
		}

		// 찾은 경우.
		// 잔액 확인.
		//if (account->GetBalance() < money)
		//{
		//	std::cout 
		//		<< "잔액이 부족합니다. 남은 잔액은 "
		//		<< account->GetBalance() 
		//		<< "원 입니다.\n";
		//	return;
		//}

		if (account->Withdraw(money))
		{
			std::cout << "출금완료\n";
			return;
		}

		return;
	}

	// 검색 실패.
	std::cout << "유효하지 않은 ID입니다.\n\n";
}

void Bank::Inquire()
{
	// 모든 계좌 정보 출력.
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
	// 저장할 데이터 생성.
	// 1. 은행이 가지고 있는 모든 계좌로부터 직렬화된 문자열 값을 누적.
	// 2. 파일에 기록.
	// 업그레이드 요지가 많음.
	const int bufferSize = 4096;
	char buffer[bufferSize] = {};
	for (int ix = 0; ix < count; ++ix)
	{
		// 직렬화된 문자열 얻어오기.
		const char* data = accounts[ix]->Serialize();

		// 직렬화된 문자열을 최종 문자열에 더하기.
		strcat_s(buffer, sizeof(buffer), data);
		delete data;
	}

	// 파일에 기록.
	FILE* file = nullptr;
	fopen_s(&file, filename, "wb");
	if (file == nullptr)
	{
		std::cerr << "파일을 열지 못했습니다.\n";
		return;
	}

	// 실제로 파일에 기록할 데이터 크기 확인.
	size_t dataLength = strlen(buffer);

	// 파일에 쓰기.
	fwrite(buffer, sizeof(char), dataLength, file);
	fclose(file);
}

void Bank::Load(const char* filename)
{
	FILE* file = nullptr;
	fopen_s(&file, filename, "rt");
	if (file == nullptr)
	{
		std::cerr << "파일을 열지 못했습니다.\n";
		return;
	}

	// 버퍼 생성.
	const int bufferSize = 1024;
	char buffer[bufferSize] = { };

	while (!feof(file))
	{
		// 한줄씩 읽기.
		fgets(buffer, bufferSize, file);

		// 파일에서 읽은 데이터가 없으면 종료.
		if (!buffer)
		{
			break;
		}

		// 계좌 타입 확인.
		int accountType = -1;
		sscanf_s(buffer, "type: %d", &accountType);

		// 계좌 정보 변수.
		int id = 0;
		char name[50] = {};
		int balance = 0;

		// 계좌 타입별로 처리.
		switch ((AccountType)accountType)
		{
			// 계좌 타입 정보가 잘못되거나 정보가 없는 경우.
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

				// 계좌 생성.
				accounts[count++] = new Account(id, name, balance);
			} break;

			case AccountType::CreditAccount:
			{
				sscanf_s(
					buffer,
					"type: %d id: %d name: %s balance: %d",
					&accountType, &id, name, 50, &balance
				);

				// 계좌 생성.
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

				// 계좌 생성.
				auto account = new DonationAccount(id, name, balance, false);
				
				// 파일에서 읽은 기부액 설정.
				account->SetDonationAmount(donationAmount);

				// 계좌 추가.
				accounts[count++] = account;

			} break;
		}

		// 버퍼 비우기.
		memset(buffer, 0, sizeof(char) * bufferSize);
	}

	// 파일 닫기.
	fclose(file);
}