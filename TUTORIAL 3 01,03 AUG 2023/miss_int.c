/*QUESTION 3:Let A be an array of size n filled with distinct integers from the set
S = {0, 1, . . . , n}. How efficiently can you return the missing integer.
(exactly one element of S is missing in A).*/
#include<stdio.h>
void main()
{
    int n,sum=0,miss;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
    scanf("%d",&arr[i]);
    sum=sum+arr[i];
    }
    miss=(n*(n+1))/2-sum;
    printf("%d",miss);
}


