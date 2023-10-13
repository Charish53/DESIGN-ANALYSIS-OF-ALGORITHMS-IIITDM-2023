/*QUESTION 1:Implement Binary Search + Insertion Sort ; To insert A[i] into the sorted array A[1...(i-1)], we search linearly in A[1...(i-1)].   As the array A[1...(i-1)] is sorted, can we do binary search to locate the position of A[i].   Implement this variant.   Count the number of comparisons, swaps.  Which of these two is a dominant operation.*/
#include<bits/stdc++.h>
using namespace std;

int comp=0;
int sp=0;
int comp1=0,sp1=0;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        comp++;
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return l;
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        comp1++;
        while (j >= 0 && arr[j] > key){
            sp1++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int size,idx,x;
    cin >> size;
    int arr[size+1],arr1[size+1];
    for(int i=0;i<size;i++)
    {
       cin>>arr[i];
        arr1[i]=arr[i];
    }
    cin >> x;
    arr[size]=x;
    arr1[size]=x;
    idx=binarySearch(arr,0,size,arr[size]);
    for(int i=0;i<=size;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
        for(int i=size-1;i>=idx;i--)
        {
            sp++;
            arr[i+1]=arr[i];
        }
        arr[idx]=x;
         for(int i=0;i<=size;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
        cout << "Swap for BS: " << sp << endl;
        cout << "Comparisions for BS : " << comp << endl;
    insertionSort(arr1,size+1);
    cout << "Swap for IS: " << sp1 << endl;
    cout << "Comparisions for IS : " << comp1 << endl;
}



