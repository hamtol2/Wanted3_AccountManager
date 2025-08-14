#pragma once

#include "Account.h"

class DonationAccount : public Account
{
public:
	DonationAccount(int id, const char* name, int balance);
	virtual void Deposit(int money) override;
	virtual void Print() override;

private:
	// ±âºÎ¾×.
	int donationAmount = 0;
};