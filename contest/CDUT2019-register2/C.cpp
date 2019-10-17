/*
    判断中位数最后一个和其下一个的差距决定增加步长
    暴力即可，注意需要ll（wa了一发）
*/
#pragma optmize(2)
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define LONG_LONG_MAX 9223372036854775807LL
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
ll n, m, k;
const int maxn = 2e5 + 10;
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
};
ll a[maxn];
ll last, mid;
inline void get_last()
{
    while (last < n && a[last] == a[last - 1])
        ++last;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read<ll>(), m = read<ll>();
    for (int i = 0; i < n; i++)
        a[i] = read<int>();
    sort(a, a + n);
    mid = n >> 1;
    last = mid + 1;
    ll cur = a[mid];
    while (m)
    {
        get_last();
        ll tmp = last - mid;
        if (m < tmp)
            break;
        ll k = m / tmp;
        if (last == n)
        {
            cur += k;
            break;
        }
        else
        {
            ll p = a[last];
            ll can = p - a[last - 1];
            if (m >= tmp * can)
            {
                a[last - 1] = a[last];
                cur = a[last];
                m -= tmp * can;
            }
            else
            {
                while (1)
                {
                    if (tmp * can <= m)
                        break;
                    --can;
                }
                a[last - 1] += can;
                cur += can;
                m -= tmp * can;
            }
        }
    }
    write(cur);
    return 0;
}