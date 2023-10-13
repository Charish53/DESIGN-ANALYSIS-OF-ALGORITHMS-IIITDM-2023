/*QUESTION 1 :Identifying an ODD BALL in collection - Given 27 balls with a
condition that one of them is odd one out (exactly one ball weighs
more compared to all other balls). You are also given a physical
balance. What is the minimum number of steps (number of
comparisons) to identify the odd ball.*/
#include<stdio.h>
int n,count;
int check()
{ 
     
    if(n%3==0)
    { 
        count++;
        n=n-2*(n/3);
        if(n==1)
        return count;
        check();
    }
    else if(n%3==1)
    {
        count++;
        n=n-2*(n/3);
        if(n==1)
        return count;
        if(n==2)
        return count+1;
        check();
    }
    else if(n%3==2)
    {
        count++;
        if(n==2)
        return count;
        n=n-2*(n/3);
        if(n==1)
        return count;
        check();
    }
}
void main()
{
   scanf("%d",&n);
   count=check();
   printf("no of comparisons is %d",count);
}




