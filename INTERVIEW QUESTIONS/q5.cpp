/*5. Input : Two arrays A, B.
Question : Find two indices i, j such that swapping A[i], B[j] makes the total sum of arrays equal, if
exists.*/
#include <bits/stdc++.h>
using namespace std;
void findSwapValues(int a[], int m, int b[], int n);
int main()//method 2 : sort the 2 arrays and check by finding the difference of numbers from the two arrays.
{
    int m, n;
    cin>>m>>n;
    int a[m], b[n];
    for(int i=0;i<m;i++)
    cin>>a[i];
    for(int j=0;j<n;j++)
    cin>>b[j];
    findSwapValues(a, m, b, n);
    return 0;
}
void findSwapValues(int a[], int m, int b[], int n)
{
    unordered_set<int> x,y; 
    unordered_set<int>::iterator p, q;
    int s1, s2;
    int i;
    s1 = 0;
    for (i = 0; i < m;i++)
    s1 += a[i], x.insert(a[i]);
    s2 = 0;
    for (i = 0; i < n; i++)
    s2 += b[i], y.insert(b[i]);
    if ((s1 - s2) % 2)
    {
    printf("No such values exist.\n");
    return;
    }
    for (p = x.begin(); p != x.end(); p++)
    {
        q = y.find(((s2 - s1) + 2 * *p) / 2); 
        if (q != y.end())
        {
        printf("%d %d\n", *p, *q);
        return;
        }
    }
    printf("No such values exist.\n");
}

