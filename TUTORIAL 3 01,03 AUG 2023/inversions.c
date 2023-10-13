/* QUESTION 2 :For an array A of size n, an inversion is a pair (A[i], A[j]) such that i < j
and A[i] > A[j]. Write an efficient algorithm to remove all inversions in A.*/
#include<stdio.h>
int n;
int arr[100];
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int low,int high)
{
    int x=arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++)
    {
        if(arr[j]<=x)
        {
            i=i+1;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
void quick_sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int q;
        q=partition(arr,low,high);
        quick_sort(arr,low,q-1);
        quick_sort(arr,q+1,high);
    }
}
void main()
{
    printf("enter number of elements:");
    scanf("%d",&n);
    printf("enter elements:\n");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}

