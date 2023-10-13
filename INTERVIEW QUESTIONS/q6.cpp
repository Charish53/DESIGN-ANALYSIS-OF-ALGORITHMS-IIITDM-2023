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
