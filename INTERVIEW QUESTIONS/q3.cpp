#include <iostream>
using namespace std;
void sort012(int arr[], int n)
{
    int l=0;
    int r=n-1;
    for(int i=0;i<n && i<=r;)
    {
        if(arr[i]==0)
        {
            swap(arr[l],arr[i]);
            l++;
            i++;
        }
        else if(arr[i]==2)
        {
            swap(arr[i],arr[r]);
            r--;
        }
        else
        i++;
    }
}
void printArray(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    cout << arr[i] << " ";
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    sort012(arr, n);
    printArray(arr, n);
    return 0;
}
