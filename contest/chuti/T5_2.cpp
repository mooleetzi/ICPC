#include <bits/stdc++.h>
#define ll long long
#define fastIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef pair<int, int> P;
int n, m, k;
const int maxn = 5e3 + 10;
char s[maxn];
ll pre[maxn], cnt[maxn], res[maxn];
ll solve(int id)
{
    ll cur = 0;
    memset(cnt, 0, sizeof(ll) * (n + 1));
    cnt[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (pre[i] >= id)
            cur += cnt[pre[i] - id];
        ++cnt[pre[i]];
    }
    return cur;
}
void init()
{
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + (s[i] == '1');
    ll zero = 0, tmp = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] == '0')
            ++tmp;
        else
        {
            zero += tmp * (tmp + 1) >> 1;
            tmp = 0;
        }
    if (s[n] == '0')
        zero += tmp * (tmp + 1) >> 1;
    res[1] = zero;
    for (int i = 1; i <= n; i++)
        res[i + 1] = solve(i);
    for (int i = 1; i <= n + 1; i++)
        res[i] += res[i - 1];
}
int main(int argc, char const *argv[])
{
    // fastIO;
    // cin >> s + 1;
    scanf("%s", s + 1);
    n = strlen(s + 1);
    scanf("%d", &m);
    init();
    while (m--)
    {
        int h, t;
        scanf("%d%d", &h, &t);
        printf("%lld\n", res[min(t, n) + 1] - res[h]);
    }
    return 0;
}