#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e7 + 10;
unsigned int SA,SB,SC;
int mod,n;
unsigned int Rand()
{
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}
int p[maxn],a[maxn];
int main()
{
    cin >> n >> mod >> SA >> SB >> SC;
    for (int i = 1; i <= n; ++i)
        a[i] = Rand() % mod + 1;
    int minx = -1e9;
    for (int i = n; i >= 1; i--)
    {
        minx = max(minx, a[i]);
        p[i] = minx;
    }
    
        int ans = 0;
    cout << ans;
    return 0;
}