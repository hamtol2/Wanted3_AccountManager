#pragma once

#include "Account.h"

class CreditAccount : public Account
{
public:
	CreditAccount(int id, const char* name, int balance, bool giveInterest = true);
	virtual void Deposit(int money) override;
	virtual void Print() override;
};