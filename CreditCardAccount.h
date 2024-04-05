#pragma once
#include "LoyaltyScheme.h"

using namespace System;

ref class CreditCardAccount
{
public:
    CreditCardAccount(long number, double limit);
    void SetCreditLimit(double amount);
    bool MakePurchase(double amount);
    void MakeRepayment(double amount);
    void PrintStatement();
    void RedeemLoyaltyPoints();
    long GetAccountNumber();

private:
    long accountNumber;
    double currentBalance;
    double creditLimit;
    LoyaltyScheme^ scheme;
};
