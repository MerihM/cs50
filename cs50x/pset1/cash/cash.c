#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change, coinCtr = 0;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);

    while (change > 0)
    {
        if (change >= 25)
        {
            change -= 25;
        }
        else if (change >= 10)
        {
            change -= 10;
        }
        else if (change >= 5)
        {
            change -= 5;
        }
        else
        {
            change--;
        }
        coinCtr++;
    }
    printf("%i\n", coinCtr);
}
