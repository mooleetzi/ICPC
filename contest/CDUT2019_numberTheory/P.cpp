/*
    神仙题呀，哭了
    首先我们思考普通情况我们有K=k1*k2*...*kn种同余方程组合
    如果K很大那么用孙子定理/中国剩余定理是很慢的，这时候我们可以考虑暴力枚举
    暴力枚举的话我们选定一个x最大的和一个k值最小的来枚举，why
    这样我们每次的增量最大而且k值更小的话对于一次增量x来说需要循环判定次数最少，保证了复杂度
    要选择最大的x和最小的k的组合可以采用kc/xc<ki/xi => kc*xi<xc*ki避免除法运算不正确
    如果K比较小那么可以用孙子定理求解(注意到题目说了m互质，用最简单的版本即可)
 */
#pragma optimize(3)
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
const int maxn = 210;
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
int limit = 10000;
unordered_set<int> se[maxn];
int m[maxn], y[maxn][maxn], k[maxn], b[maxn];
vector<int> res;
int c, s;
ll exgcd(ll a, ll b, ll &x, ll &y) //求逆元
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll ret = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return ret;
}

ll crt()
{
    ll d, x, y, ret = 0;
    ll temp;
    ll M = 1;
    for (int i = 0; i < c; i++)
        M *= m[i]; //m是除数
    for (int i = 0; i < c; i++)
    {
        temp = M / m[i];
        d = exgcd(m[i], temp, x, y);       //求temp在模mi意义下的逆元
        ret = (ret + y * temp * b[i]) % M; //b是余数
    }
    return (ret + M) % M;
}
void dfs(int dep)
{
    if (dep == c)
    {
        res.emplace_back(crt());
        return;
    }
    for (int j = 0; j < k[dep]; j++)
    {
        b[dep] = y[dep][j];
        dfs(dep + 1);
    }
}
void solveCrt()
{
    dfs(0);
    ll lcm = 1;
    sort(res.begin(), res.end());
    for (int i = 0; i < c; i++)
        lcm *= m[i];
    for (int i = 0; s; i++)
    {
        int sz = res.size();
        for (int j = 0; j < sz && s; j++)
        {
            ll now = lcm * i + res[j];
            if (now > 0)
            {
                write(now);
                puts("");
                --s;
            }
        }
    }
}
void solveEnum(int best)
{
    for (int i = 0; i < c; i++)
    {
        if (i == best)
            continue;
        se[i].clear();
        for (int j = 0; j < k[i]; j++)
            se[i].insert(y[i][j]);
    }
    for (int i = 0; s; i++)
        for (int j = 0; j < k[best] && s; j++)
        {
            ll now = m[best] * i + y[best][j];
            if (!now)
                continue;
            int f = 1;
            for (int p = 0; p < c; p++)
            {
                if (p != best && !se[p].count(now % m[p]))
                {
                    f = 0;
                    break;
                }
            }
            if (f)
            {
                write(now);
                puts("");
                --s;
            }
        }
}
int main(int argc, char const *argv[])
{
    while (read(c) && read(s))
    {
        res.clear();
        int best = 0, tot = 1;
        for (int i = 0; i < c; i++)
        {
            read(m[i]), read(k[i]);
            for (int j = 0; j < k[i]; j++)
                read(y[i][j]);
            sort(y[i], y[i] + k[i]);
            if (m[best] * k[i] < m[i] * k[best])
                best = i;
            tot *= k[i];
        }
        if (tot >= limit)
            solveEnum(best);
        else
            solveCrt();
        puts("");
    }
    return 0;
}
