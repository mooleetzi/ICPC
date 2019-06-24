#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
using ll = long long;
inline int read()
{
    register int f = 1, ans = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ans = (ans << 1) + (ans << 3) + ch - 48;
        ch = getchar();
    }
    return ans * f;
}
int n, m;
int a[maxn];
int main(int argc, char const *argv[])
{
    n = read();
    for (int i = 0; i < n;i++)
        a[i] = read();
    ll ans = a[n-1];
    int pre = a[n - 1];
    for (int i = n - 2; i > -1; i--)
    {
        if (!pre)
            break;
        if (a[i] < pre)
        {
            ans += a[i];
            pre = a[i];
        }
        else{
            ans += pre - 1;
            --pre;
        }
    }
    cout << ans;
    return 0;
}
