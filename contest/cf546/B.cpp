#include <bits/stdc++.h>
#define gcd __gcd
using ll = long long;
using namespace std;
using pa = pair<int, int>;
const int maxn = 4e5 + 10;
vector<pa> v;
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
int vis[maxn], st[maxn];
int main(int argc, char const *argv[])
{
    n = read(), m = read();
    for (int i = 1; i <= n;i++)
        st[i] = 1;
    int ans = min(2 * (m - 1) + n - m, 2 * (n - m) + m - 1);
    ans += 2*n+1;
    cout << ans;
    return 0;
}
