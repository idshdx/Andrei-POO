#include "stdafx.h"
#include "CreditCardAccount.h"
#include "LoyaltyScheme.h"

using namespace System;

CreditCardAccount::CreditCardAccount(long number, double limit)
{
    accountNumber = number;
    creditLimit = limit;
    currentBalance = 0.0;
    scheme = nullptr;
}

void CreditCardAccount::SetCreditLimit(double amount)
{
    creditLimit = amount;
}

bool CreditCardAccount::MakePurchase(double amount)
{
    if (currentBalance + amount > creditLimit)
    {
        return false;
    }
    else
    {
        currentBalance += amount;
        if (currentBalance >= creditLimit / 2 && scheme == nullptr)
        {
            scheme = gcnew LoyaltyScheme();
        }
        else if (scheme != nullptr)
        {
            scheme->EarnPointsOnAmount(amount);
        }
        return true;
    }
}

void CreditCardAccount::MakeRepayment(double amount)
{
    currentBalance -= amount;
}

void CreditCardAccount::PrintStatement()
{
    Console::WriteLine("Account Number: {0}", accountNumber);
    Console::WriteLine("Current balance: {0}", currentBalance);
    Console::WriteLine("Credit Limit: {0}", creditLimit);
    if (scheme != nullptr)
    {
        Console::WriteLine("Loyalty Points: {0}", scheme->GetPoints());
    }
}

void CreditCardAccount::RedeemLoyaltyPoints()
{
    if (scheme == nullptr)
    {
        Console::WriteLine("No loyalty scheme available.");
        return;
    }
    scheme->RedeemPoints(10); // Example: Redeeming 10 points
    Console::WriteLine("Redeemed loyalty points.");
}

long CreditCardAccount::GetAccountNumber()
{
    return accountNumber;
}
