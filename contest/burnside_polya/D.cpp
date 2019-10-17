/*
    二元组(i,j)表示循环节个数，循环个数，组合数学里叫K不动置换类和等价类
    不变置换:1*(1,12)
    面心+90:3*(4,3)
    面心-90:3*(4,3)
    面心180:3*(2,6)
    对棱180:6*[(2,5)+(1,2)]
    体心120:4*(3,4)
    体心240:4*(3,4)
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
int n, m, k;
const int maxn = 1e5 + 10;
int a[7], b[7];
inline ll fac(ll n)
{
    ll res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}
inline ll C(ll n, ll m)
{
    if (n < m)
        return 0;
    return fac(n) / (fac(m) * fac(n - m));
}
inline ll doit(int k)
{
    memcpy(b, a, sizeof a);
    int group = 0;
    for (int i = 1; i <= 6; i++)
    {
        if (b[i] % k)
            return 0; //不能完全以k划分
        b[i] /= k;
        group += b[i];
    }
    ll res = 1;
    for (int i = 1; i <= 6; i++)
    {
        res *= C(group, b[i]);
        group -= b[i];
    }
    return res;
}
inline ll solve()
{
    ll res = 0;
    res += doit(1);         //不动置换
    res += 2 * 3 * doit(4); //面心+90,-90
    res += 3 * doit(2);     //面心180
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++)
        {
            if ((i == j && a[i] < 2) || (i != j && (!a[i] || !a[j])))
                continue;
            a[i]--, a[j]--;
            res += 6 * doit(2); //对棱180
            a[i]++, a[j]++;
        }
    res += 2 * 4 * doit(3); //体心+120,-120
    return res / 24;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof a);
        for (int i = 0; i < 12; i++)
        {
            int x;
            cin >> x;
            a[x]++;
        }
        cout << solve() << "\n";
    }
    return 0;
}
