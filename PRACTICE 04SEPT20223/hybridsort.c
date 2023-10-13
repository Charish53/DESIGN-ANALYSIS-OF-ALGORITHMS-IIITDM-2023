/* QUESTION 2: Hybrid Sorting (Quick + Bubble),   Generate an arbitrary integer array of size 2000 (use rand function) and implement quick sort with the condition that if the recursive sub problem reduces to less than 30, implement bubble sort.  Is this efficient compared to classical quick sort at all subproblems.*/
#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#define N 2000
int c1;
int c2;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        c1++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
int partition2(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        c2++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void bubbleSort(int arr[], int low, int n)
{
    int i, j;
    bool swapped;
    for (i = low; i < n - 1; i++) {
        swapped = false;
        for (j = low; j < n - i - 1; j++) {
            c1++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        if((pi-low)<=2000)
        bubbleSort(arr,low,pi-low);
        quickSort(arr, low, pi - 1);
        if((high-pi)>=30)
        bubbleSort(arr,high-pi,high);
        quickSort(arr, pi + 1, high);
    }
}
void quick(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition2(arr, low, high);
        quick(arr, low, pi - 1);
        quick(arr, pi + 1, high);
    }
}
int main()
{
    int arr[N],arr2[N];
    time_t t1;
    for(int i=0;i<2000;i++)
    {
    arr[i]=rand()%3000;
    arr2[i]=arr[i];
    printf("%d ",arr[i]);
    }
     printf("\n");
    quickSort(arr, 0, N - 1);
    quick(arr2,0,N-1);
    printf("Sorted array: \n");
    for (int i = 0; i < N; i++)
        printf("%d-%d ", arr[i],arr2[i]);
    printf("\n");
    printf("%d %d",c1,c2);
    return 0;
}

