#include "stdafx.h"
#include "CreditCardAccount.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    Console::WriteLine("Credit Card Account Simulator");

    CreditCardAccount^ myAccount = gcnew CreditCardAccount(123456789, 5000.0);
    myAccount->MakePurchase(2500.0); // This should trigger the loyalty scheme creation
    myAccount->PrintStatement();
    myAccount->RedeemLoyaltyPoints();

    return 0;
}
