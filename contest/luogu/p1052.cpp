#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int f[maxn];
int a[maxn], d[maxn], flag[maxn];
int main(int argc, char const *argv[])
{
    int l, s, t, m;
    cin >> l >> s >> t >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + m);
    for (int i = 1; i <= m;i++)
        d[i] =(a[i] - a[i - 1])%2520;
    for (int i = 1; i <= m;i++)
        a[i] = a[i - 1] + d[i], flag[a[i]] = 1;
    l = a[m];
    for (int i = 1; i <= l+t; i++)
    {
        f[i] = 1e9;
        for (int j = s; j <= t; j++)
            if (i - j >= 0)
                f[i] = min(f[i], f[i - j]);
        f[i] += flag[i];
    }
    int ans = 1e9;
    for (int i = l; i < l + t;i++)
        ans = min(ans, f[i]);
    cout <<ans;
    return 0;
}
