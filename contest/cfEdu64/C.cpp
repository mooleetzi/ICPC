/*
    二分答案
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=3e5+10;
int a[maxn];
int n, m, z;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>z;
    for (int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a + n);
    int l = 0, r = n/2+1;
    while(l<r-1){
        int m = l + r >> 1;
        int f = 1;
        for (int i = 0; i < m;i++)
            f &= (a[n - m + i] - a[i] >= z);
        if (f)
            l = m;
        else
            r = m;
    }
    cout << l;
    return 0;
}
