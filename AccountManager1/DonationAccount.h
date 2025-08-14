#pragma once

#include "Account.h"

class DonationAccount : public Account
{
public:
	DonationAccount(int id, const char* name, int balance, bool donate = true);
	virtual void Deposit(int money) override;
	virtual void Print() override;

	// 문자열 직렬화 함수 오버라이드.
	virtual const char* Serialize() override;

	// 기부금액 설정 함수.
	void SetDonationAmount(int amount);

private:
	// 기부액.
	int donationAmount = 0;
};