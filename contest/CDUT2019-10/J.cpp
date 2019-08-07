/*
    曼哈顿最大距离和
    考虑每一个维度只有+-两种情况
    2进制枚举(1<<k)种，主武器和副武器是+-刚好相反
    O(2^k(m+n))取最大值
 */
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
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
struct node
{
    int s;
    vector<int> sub;
};
vector<node> M, S;
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    read(t);
    while (t--)
    {
        M.clear(), S.clear();
        read(n), read(m), read(k);
        for (int i = 0; i < n; i++)
        {
            node now;
            read(now.s);
            for (int j = 0; j < k; j++)
            {
                int p;
                read(p);
                now.sub.emplace_back(p);
            }
            M.emplace_back(now);
        }
        for (int i = 0; i < m; i++)
        {
            node now;
            read(now.s);
            for (int j = 0; j < k; j++)
            {
                int p;
                read(p);
                now.sub.emplace_back(p);
            }
            S.emplace_back(now);
        }
        int l = (1 << k);
        ll ans = -inf;
        for (int i = 0; i < l; i++)
        {
            ll t1 = -inf, t2 = -inf;
            for (int j = 0; j < n; j++)
            {
                ll tmp = M[j].s;
                for (int p = 0; p < k; p++)
                    if ((i >> p) & 1)
                        tmp += M[j].sub[p];
                    else
                        tmp -= M[j].sub[p];
                t1 = max(tmp, t1);
            }
            for (int j = 0; j < m; j++)
            {
                ll tmp = S[j].s;
                for (int p = 0; p < k; p++)
                    if ((i >> p) & 1)
                        tmp -= S[j].sub[p]; //和M集合相反
                    else
                        tmp += S[j].sub[p];
                t2 = max(tmp, t2);
            }
            ans = max(ans, t1 + t2);
        }
        write(ans);
        puts("");
    }
    return 0;
}
