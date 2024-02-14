#include "cs50.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>

long long AMEX(long long cardno, long long a);
long long MASTERCARD(long long  cardno, long long a);
long long VISA(long long cardno, long long a);
int altsecondlastdigit(long long cardno, long long cardnodummy);

int main()
{
    long long cardno = get_long_long("Number: ");
    long long a = 0;
    long long cardnodummy = cardno, cardnodummy1 = cardno;
    int sum = altsecondlastdigit(cardno, cardnodummy);
    while (cardnodummy1 > 0)
    {
        cardnodummy1 = cardnodummy1 / 10;
        a++;
    }
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    if (a == 15 && AMEX(cardno, a))
    {
        printf("AMEX\n");
        return 0;
    }
    else if (a == 16 && VISA(cardno, a))
    {
        printf("VISA\n");
        return 0;
    }
    else if (a == 13 && VISA(cardno, a))
    {
        printf("VISA\n");
        return 0;
    }
    else if (a == 16 && MASTERCARD(cardno, a))
    {
        printf("MASTERCARD\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }

    altsecondlastdigit(cardno, cardnodummy);
}
int altsecondlastdigit(long long cardno, long long cardnodummy)
{
    int lastdigit, secondlast, sum = 0, digitadd1, digitadd2, lastaltdigit, secondaltlast;
    while (cardno > 0)
    {
        lastdigit=cardno%100;
        secondlast=lastdigit/10;
        secondlast*=2;
        if (secondlast / 10 != 0)
        {
            //for adding digits mult by 2
            //for first digit eg 12->1
            digitadd1=secondlast/10;
            //for second digit eg 12->2
            digitadd2=secondlast%10;
            sum+=digitadd1;
            sum+=digitadd2;
        }
        else
            sum += secondlast;
        cardno /= 100;
    }

    while(cardnodummy>0)
    {
        lastaltdigit=cardnodummy%100;
        secondaltlast=lastaltdigit%10;
        sum += secondaltlast;
        cardnodummy /= 100;
    }

    return sum;
}
long long AMEX(long long cardno, long long a)
{
    if (a == 15 && ((cardno / (long long) pow(10, 13) == 34) || (cardno / (long long) pow(10, 13) == 37)))
    {

        return 1;
    }
    return 0;
}
long long VISA(long long cardno, long long a)
{
    if (a == 13 && ((cardno / (long long) pow(10, 12) == 4)))
    {

        return 1;
    }
    else if (a == 16 && ((cardno / (long long) pow(10, 15) == 4)))
    {

        return 1;
    }
    return 0;
}
long long MASTERCARD(long long cardno,long long a)
{
    if (a == 16 && ((cardno / (long long)pow(10,14) >=51) && (cardno / (long long)pow(10,14)<=55)))
    {

        return 1;
    }
    return 0;
} 
