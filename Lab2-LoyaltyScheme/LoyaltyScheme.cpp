#include "stdafx.h"
#include "LoyaltyScheme.h"

using namespace System;

LoyaltyScheme::LoyaltyScheme()
{
    totalPoints = 0;
}

void LoyaltyScheme::EarnPointsOnAmount(double amountSpent)
{
    int points = static_cast<int>(amountSpent / 10);
    totalPoints += points;
    Console::WriteLine("Earned {0} bonus points.", points);
}

void LoyaltyScheme::RedeemPoints(int points)
{
    if (points <= totalPoints)
    {
        totalPoints -= points;
    }
    else
    {
        Console::WriteLine("Not enough points to redeem.");
    }
}

int LoyaltyScheme::GetPoints()
{
    return totalPoints;
}
