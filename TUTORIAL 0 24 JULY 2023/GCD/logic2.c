#include<stdio.h>
int gcd(int a ,int b)
{
    if(a==b)
        return a;
    else{
        if(a>b)
            return gcd(a-b,b);
        else
            return gcd(a,b-a);
        }
}

int main()
{
    int n,a[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int h=a[0];
    for(int i=1;i<n;i++)
        h=gcd(h,a[i]);
    printf("GCD OF %d numbers is %d",n,h);
}

