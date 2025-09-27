#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long creditCardNumber = get_long("Number: ");
    int digitCtr = 0, luhnSum = 0, sum = 0, digitFlag = 0, tempNum;
    long idNum = creditCardNumber;
    while (creditCardNumber > 0)
    {
        if (digitFlag == 0)
        {
            sum += creditCardNumber % 10;
            digitFlag = 1;
        }
        else
        {
            tempNum = 2 * (creditCardNumber % 10);
            if (tempNum > 9)
            {
                luhnSum += ((tempNum % 10) + (tempNum / 10));
            }
            else
            {
                luhnSum += tempNum;
            }
            digitFlag = 0;
        }
        digitCtr++;
        creditCardNumber /= 10;
    }

    if ((sum + luhnSum) % 10 == 0)
    {
        for (int i = 0; i < digitCtr - 2; i++)
        {
            idNum /= 10;
        }
        if (idNum / 10 == 4)
        {
            idNum /= 10;
        }
    }
    else
    {
        idNum = 0;
    }
    switch (idNum)
    {
        case 4:
            if (digitCtr == 13 || digitCtr == 16)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
            break;
        case 34:
        case 37:
            if (digitCtr == 15)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
            break;
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            if (digitCtr == 16)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
            break;
        default:
            printf("INVALID\n");
            break;
    }
}
