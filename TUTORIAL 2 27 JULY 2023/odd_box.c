/*There are 10 boxes and each box is filled with sufficient number of
coins. It so happens that the exactly one box is odd (every coin
that box weights 1.1 g while in all other boxes, the weight of any
coin is 1g). You are also given an electronic balance. What is the
minimum number of steps (comparisons) to identify the odd box.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
    float n,x,sum,MB;
    x=rand()%10;
    for(int i=1;i<=10;i++)
    {
        if(i!=x)
        sum=sum+i*10;
    }
    sum=sum + 11*x;
    MB=sum-550;
    printf("%f",MB);
}
