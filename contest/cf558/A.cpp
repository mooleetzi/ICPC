#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n,m;
int a[maxn];
int pre[maxn][11];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int ans;
    if (m==0||m==1)
        ans = 1;
    else
        ans = min(n - m, m);
    cout << ans;
    return 0;
}
