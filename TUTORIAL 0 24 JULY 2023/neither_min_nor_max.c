/*Given an array of integers, discover a logic to find a number which is
neither minimum nor maximum.*/
/*SOLUTION TO THIS PROBLEM EXIST IN TWO DIFFERENT WAYS*/
/* METHOD 1*/
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
# define SIZE 5
int check_for_3(int a,int b,int c)
{
    if ((a < b && b < c) || (c < b && b < a))
       return b;
    else if ((b < a && a < c) || (c < a && a < b))
       return a;
    else
       return c;
}
void check_for_any(int arr[])
{
    int min,max,flag=1;
        min=max=arr[0];
    for(int j=0;j<SIZE;j++)
    {
        if(arr[j]>=max)
            max=arr[j];
        if(arr[j]<=min)
            min=arr[j];
    }
    for(int i=0;i<SIZE;i++)
    {
    if(min!=arr[i] && arr[i]!=max)
    {
    printf("%d",arr[i]);
    flag=0;
    break;
    }
    }
    if(flag!=0)
    printf("neither min nor max");
}
int check(int x)
{
    if(x==0)
    check_for_3(x,x+1,x+2);
    else if(x==(SIZE-1))
    check_for_3(x,x-1,x-2);
    else
    check_for_3(x-1,x,x+1);
}
int main()
{
    int arr[SIZE],m;
    for(int i=0;i<SIZE;i++)
    scanf("%d",&arr[i]);
    printf("enter choice");
    scanf("%d",&m);
    if(m==1)
    {
    int x=(rand()%10)-1;    
    int p=check(x);
    printf("%d",p);
    }
    else
    check_for_any(arr);
}

