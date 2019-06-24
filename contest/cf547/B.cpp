#include <bits/stdc++.h>
#define gcd __gcd
using namespace std;
const int maxn = 4e5 + 10;
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
int main(){
    n = read();
    for (int i = 0; i < n;i++)
        a[i] = read(), a[i + n] = a[i];
    int ans = 0, now = 0;
    for (int i = 0; i < 2*n; i++)
    {
        if (a[i])
            ++now;
        else
        {
            now = 0;
        }

        ans = max(now, ans);
    }
    cout << ans;
    return 0;
}