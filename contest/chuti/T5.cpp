#include <bits/stdc++.h>
#define ll long long
#define fastIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef pair<int, int> P;
int n, m, k;
const int maxn = 6e3;
char s[maxn];
ll pre[maxn], nxt[maxn], res[maxn], tmp, cnt;
ll solve(int id)
{
    int cnt = 0;
    ll cur = 0;
    for (int l = 1, r = 1; l <= n; l++)
    {
        while (r <= n && cnt < id)
        {
            if (s[r] == '1')
                ++cnt;
            ++r;
        }
        if (cnt == id && s[l] == '1')
            cur += (pre[l] + 1) * (nxt[r - 1] + 1);
        if (s[l] == '1')
            --cnt;
    }
    return cur;
}
void init()
{
    memset(pre, 0, sizeof(ll) * (n + 1));
    memset(nxt, 0, sizeof(ll) * (n + 1));
    for (int i = 1; i <= n; i++)
        if (s[i] == '0')
            ++cnt;
        else
        {
            tmp += 1LL * cnt * (cnt + 1) / 2;
            pre[i] = cnt;
            cnt = 0;
        }
    if (s[n] == '0')
        tmp += 1LL * cnt * (cnt + 1) / 2;
    res[1] = tmp;
    cnt = 0;
    for (int i = n; i >= 1; i--)
        if (s[i] == '0')
            ++cnt;
        else
        {
            nxt[i] = cnt;
            cnt = 0;
        }
    for (int i = 1; i <= n; i++)
        res[i + 1] = solve(i);
    for (int i = 1; i <= n + 1; i++)
        res[i] += res[i - 1];
}
int main(int argc, char const *argv[])
{
    fastIO;
    cin >> s + 1;
    n = strlen(s + 1);
    cin >> m;
    init();
    while (m--)
    {
        int h, t;
        cin >> h >> t;
        cout << res[min(t, n) + 1] - res[h] << "\n";
    }
    return 0;
}