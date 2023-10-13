/* QUESTION 4:Given a natural number x, design an algorithm to compute
sqrt(x).*/
#include<stdio.h>
float find(int n)
{
     int first=1,last=n/2;
     float var;
     while(first<=last)
    {
        int mid=(first+last)/2;
        if(mid*mid==n)
        return mid;
        if(mid*mid<n)
        {
        first=mid+1;
        var=mid;
        }
        else
        last=mid-1;
    }
    float x=0.1; 
    for(int j=0;j<=5;j++)
    {
        while(var*var <= n)
        var+=x;
        var=var-x;
        x=x/10;
    }
    return var;
}
void main()
{
    int n;
    float sqr;
    scanf("%d",&n);
    sqr=find(n);
    printf("%f",sqr);
}
