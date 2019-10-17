/*
    线性基板题
*/
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define LONG_LONG_MAX 9223372036854775807LL
#define ll LL
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> P;
int n, m, k;
const int maxn = 1e4 + 10, BASE = 64;
template <class T>
inline T read()
{
    int f = 1;
    T ret = 0;
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
struct L_B
{
    ll d[BASE], p[BASE];
    int cnt, flag;
    void init()
    {
        memset(d, 0, sizeof(d));
        memset(p, 0, sizeof(p));
        cnt = 0;
        flag = 0;
    } // 1e18以内的数都适用.
    inline bool insert(LL val)
    {
        for (int i = BASE - 1; i >= 0; i--)
        {
            if (val & (1ll << i))
            {
                if (!d[i])
                {
                    d[i] = val;
                    return true;
                }
                val ^= d[i];
            }
        }
        flag = 1; //可以异或出0
        return false;
        // 可判断val是否存在于线性基当中.
    }
    LL query_max()
    {
        ll res = 0;
        for (int i = BASE - 1; i >= 0; i--)
        {
            if ((res ^ d[i]) > res)
                res ^= d[i];
        }
        return res;
    }
    LL query_min()
    { // 应该预先判断能否是0的情况..QAQ
        if (flag)
            return 0;
        for (int i = 0; i <= BASE - 1; i++)
        {
            if (d[i])
                return d[i];
        }
    }
    void rebuild()
    { // 用于求第k小值.需要先进行独立预处理
        for (int i = BASE - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (d[i] & (1ll << j))
                    d[i] ^= d[j];
            }
        }
        for (int i = 0; i <= BASE - 1; i++)
        {
            if (d[i])
                p[cnt++] = d[i];
        }
    }
    ll kthquery(LL k)
    {             // 注意判断原序列异或出0的情况, 此时应该将k -- 在进行后面的操作.
        if (flag) //判0
            --k;
        if (!k)
            return 0;
        ll res = 0;
        if (k >= (1ll << cnt))
            return -1;
        for (int i = BASE - 1; i >= 0; i--)
        {
            if (k & (1LL << i))
                res ^= p[i];
        }
        return res;
    }
    void Merge(const L_B &b)
    { // 把b这个线性基插入到当前这个线性基中.
        for (int i = BASE - 1; i >= 0; i--)
            if (b.d[i])
                insert(b.d[i]);
    }
} lb;
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = read<int>();
    for (int cas = 1; cas <= t; cas++)
    {
        n = read<int>();
        lb.init();
        for (int i = 1; i <= n; i++)
            lb.insert(read<ll>());
        int q = read<int>();
        printf("Case #%d:\n", cas);
        lb.rebuild();
        while (q--)
        {
            k = read<int>();
            write(lb.kthquery(k));
            puts("");
        }
    }
    return 0;
}