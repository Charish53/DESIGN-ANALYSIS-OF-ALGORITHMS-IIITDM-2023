/*Given an integer n, find (i) sum of the digits of n (ii) sum of the
distinct digits of n*/
#include<stdio.h>
int  sum(int n)
{
    int sum=0;
    while(n!=0)
    {
    sum+=n%10;
    n=n/10;
    }
    return sum;
}
int sumofDistinctdigits(int n)
{
    int h[10]={0};
    int sum=0,a;
    
    while (n != 0) {
        int digit = n % 10;
        if(h[digit]==0)
        sum=sum+digit;
        h[digit] = digit;
        n /= 10;
    }
    return sum;
}
int main()
{
   int n;
   printf("ENTER THE INTEGER n ");
   scanf("%d",&n);
   int ch;
   scanf("%d",&ch);
   printf("1.SUM OF DIGITS OF THE INTEGER \n");
   printf("2.SUM OF DISTINCT DIGITS OF THE INTEGER\n");
   switch (ch)
   {
       case 1:
       printf("sum of digits of the intger %d is %d\n ",n,sum(n));
       break;
       
       case 2:
       printf("sum of the distinct digits of the integer %d is %d\n ",n,sumofDistinctdigits(n));
       break;
       
       default:
       printf("INVALID OPTION,ENTER 1 OR 2\n");
       break;
       
   }
}

