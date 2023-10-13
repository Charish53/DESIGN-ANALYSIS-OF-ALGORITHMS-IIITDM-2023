/*
6. There are n people standing in a circle in an order 1 to n. Assume that person i has a sword. He kills
the next person (i + 1) and gives the sword to the next (i + 2). All people do the same until only 1
person survives. Which number survives at the last ? Present an efficient solution which will return
the ’survivor’
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,pos;
    cin>>n>>pos;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    while (a.size() > 1) 
    {
        pos++;
        pos %= a.size();
        a.erase(a.begin() + pos);
    }
    cout << a[0];
    return 0;
}
