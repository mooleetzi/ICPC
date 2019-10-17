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
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
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
const int maxn = 1e5 + 10;
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
int n, p, q, m;
unsigned int SA, SB, SC;
unsigned res = 0;
inline unsigned int rng61()
{
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}
inline void gen()
{
    stack<unsigned> s;
    while (!s.empty())
        s.pop();
    multiset<unsigned, greater<unsigned>> ss;
    ss.clear();
    res = 0;
    n = read<int>(), p = read<int>(), q = read<int>(), m = read<int>();
    SA = read<unsigned>(), SB = read<unsigned>(), SC = read<unsigned>();
    for (int i = 1; i <= n; i++)
    {
        unsigned cur = rng61() % (p + q);
        if (cur < p)
        {
            cur = rng61() % m + 1;
            ss.insert(cur);
            res ^= (*(ss.begin()) * i);
            s.emplace(cur);
        }
        else
        {
            if (s.empty())
                continue;
            auto pa = ss.equal_range(s.top());
            ss.erase(pa.first);
            s.pop();
            if (s.empty())
                continue;
            res ^= (*(ss.begin()) * i);
        }
    }
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = read<int>();
    for (int cas = 1; cas <= t; cas++)
    {
        gen();
        printf("Case #%d: %u\n", cas, res);
    }
    return 0;
}
