#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //prompt for input

    long long creditcard;

    do {
    creditcard = get_long("Number: ");
    }
    while (creditcard < 0);

    //count numbers

    int count = 0;
    long long i = creditcard;
    while (i > 0)
    {
        i = i / 10;
        count++;
    }

    //check if the lenght is valid
    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    //calculate checksum
    long long j = creditcard;
    int sum1 = 0;
    int sum2 = 0;
    int mod1;
    int mod2;
    int d1;
    int d2;
    int total = 0;

    do
    {
    //Removing last digit and adding to variable sum1
    mod1 = j % 10;
    j = j / 10;
    sum1 = sum1 + mod1;

    //Remove second to last digit
    mod2 = j % 10;
    j = j / 10;

    //Multiply every other digit by 2 and add to variable sum2
    mod2 = mod2 * 2;
    d1 = mod2 % 10;
    d2 = mod2 / 10;
    sum2 = sum2 + d1 + d2;
    }

    while (j > 0);

    total = sum1 + sum2;

        // Next check Luhn Algorithm
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    //check card length and starting digits
    int test = creditcard / pow(10, count - 2);
        if ((count == 13 || count == 16) && test / 10 == 4)
    {
        printf("VISA\n");
    }
    else if (count == 16  && test >= 51 && test <= 55)
    {
        printf("MASTERCARD\n");
    }
    else if (count == 15 && (test == 34 || test == 37))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
    //print card type or invalid
}