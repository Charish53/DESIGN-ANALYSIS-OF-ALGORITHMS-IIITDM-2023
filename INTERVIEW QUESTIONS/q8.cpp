/*
8. Given an array of N non-negative integers array A representing an elevation map (bar chart) where
the width of each bar is 1, compute how much water it can store.
Example: Input arr[] = 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1, Output: 6.
Trap “1 unit” between first 1 and 2, “4 units” between first 2 and 3 and “1 unit” between second last
1 and last 2*/
#include <bits/stdc++.h> 
using namespace std; 
int findWater(int arr[], int n) 
{ 
    int left[n]; 
    int right[n]; 
    int water = 0; 
    left[0] = arr[0]; 
    for (int i = 1; i < n; i++) 
        left[i] = max(left[i - 1], arr[i]); 
    right[n - 1] = arr[n - 1]; 
    for (int i = n - 2; i >= 0; i--) 
        right[i] = max(right[i + 1], arr[i]); 
    for (int i = 1; i < n - 1; i++)
    { 
        int var = min(left[i - 1], right[i + 1]); 
        if (var > arr[i])
        water += var - arr[i]; 
    } 
    return water; 
}
int main() 
{ 
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout << findWater(arr, n); 
    return 0; 
}

