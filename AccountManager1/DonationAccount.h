#pragma once

#include "Account.h"

class DonationAccount : public Account
{
public:
	DonationAccount(int id, const char* name, int balance, bool donate = true);
	virtual void Deposit(int money) override;
	virtual void Print() override;

	// ���ڿ� ����ȭ �Լ� �������̵�.
	virtual const char* Serialize() override;

	// ��αݾ� ���� �Լ�.
	void SetDonationAmount(int amount);

private:
	// ��ξ�.
	int donationAmount = 0;
};