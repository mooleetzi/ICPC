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
int n, m, k;
const int maxn = 1e5 + 10;
ll p[25];
void init()
{
    p[1] = 3;
    for (int i = 2; i < 24; i++)
        p[i] = p[i - 1] * 3;
}
ll solve(int x)
{
    ll t = 1;
    ll res = p[x];
    if (x & 1)
    {
        for (int i = 1; i <= (x - 1) / 2; i++)
        {
            int tmp = 0;
            set<int> s1, s2;
            s1.clear();
            for (int j = 1; j <= x; j++)
                s1.insert(j);
            while (!s1.empty())
            {
                s2.clear();
                int begin = *s1.begin();
                while (!s2.count(begin))
                {
                    // cout << begin << " ";
                    s2.insert(begin);
                    s1.erase(begin);
                    begin = (begin + i) % x;
                    if (!begin)
                        begin = x;
                }
                // cout << "\n";
                ++tmp;
            }
            t += 2;
            res += 2 * p[tmp];
        }
        res += x * p[(x + 1) / 2];
        t += x;
        return res / t;
    }
    else
    {
        int e = x / 2;
        for (int i = 1; i <= e; i++)
        {
            int tmp = 0;
            set<int> s1, s2;
            s1.clear();
            for (int j = 1; j <= x; j++)
                s1.insert(j);
            while (!s1.empty())
            {
                s2.clear();
                int begin = *s1.begin();
                while (!s2.count(begin))
                {
                    // cout << begin << " ";
                    s2.insert(begin);
                    s1.erase(begin);
                    begin = (begin + i) % x;
                    if (!begin)
                        begin = x;
                }
                // cout << "\n";
                ++tmp;
            }
            if (i != e)
            {
                t += 2;
                res += 2 * p[tmp];
            }
            else
            {
                ++t;
                res += p[tmp];
            }
        }
        t += e;
        res += e * p[e + 1];
        t += e;
        res += e * p[e];
        return res / t;
    }
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    while (~scanf("%d", &n) && n != -1)
    {
        printf("%d\n", solve(n));
    }
    return 0;
}
