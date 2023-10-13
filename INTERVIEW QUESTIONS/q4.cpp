#include <bits/stdc++.h>
using namespace std;
#define n 5
int mat[n][n];
int search(int x)
{
    if (n == 0)
    return -1;
    int smallest = mat[0][0], largest = mat[n - 1][n - 1];
    if (x < smallest || x > largest)
    return -1;
    int i = 0, j = n - 1;
    while (i < n && j >= 0) 
    {
    if (mat[i][j] == x)
    {
    cout << "Element found at " << i << ", " << j;
    return 1;
    }
    if (mat[i][j] > x)
    j--;
    else
    i++;
    }
    cout << "n Element not found";
    return 0;
}
int main()
{
    int a;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>mat[i][j];
    cin>>a;//element to be searched.
    search(a);
    return 0;
}


