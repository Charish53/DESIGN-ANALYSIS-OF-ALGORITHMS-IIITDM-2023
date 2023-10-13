/*QUESTION 1 :Write an algorithm to list all subsets of a given set of size n*/
#include <stdio.h>

int main()
{
    int n,c=0,b;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("NULL");
    for(int i=0;i<(1<<n);i++)
    {
        b=i;
       /* if(b==0)
        printf("NULL"); */
        while(b>0)
        {
            if(b%2==1)
            printf("%d ",arr[c]);
            c++;
            b=b/2;
        }
        c=0;
        printf("\n");
    }

    return 0;
}

