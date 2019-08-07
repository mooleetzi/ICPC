//高精/低精度
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
ll n, m, k;
const ll maxn = 1LL << 31;
const int mod = 998244353;
template <class T>
inline T read(T &ret)
{
    int f = 1;
    ret = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ret = (ret << 1) + (ret << 3) + ch - '0';
        ch = getchar();
    }
    ret *= f;
    return ret;
}
template <class T>
inline void write(T n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n >= 10)
    {
        write(n / 10);
    }
    putchar(n % 10 + '0');
}
vector<int> a;
int b;
char ss[210];
int solve()
{
    int sz = a.size();
    ll t = 0; //注意这里当b为maxInt时,有可能超出int范围，所以应该用ll
    for (int i = 0; i < sz; i++)
    {
        t = t * 10 + a[i];
        t %= b;
    }
    return t == 0;
}
int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    int tot = 0;
    char s[2][20] = {"not divisible", "divisible"};
    while (t--)
    {
        a.clear();
        scanf("%s%d", ss, &b);
        b = abs(b);
        int len = strlen(ss);
        if (ss[0] == '-')
            for (int i = 1; i < len; i++)
                a.emplace_back(ss[i] - '0');
        else
            for (int i = 0; i < len; i++)
                a.emplace_back(ss[i] - '0');

        int ans = solve();
        printf("Case %d: %s\n", ++tot, s[ans]);
    }
    return 0;
}
