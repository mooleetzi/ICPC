/*
    sb模拟
*/
#pragma optmize(2)
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
#define endl "\n"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, char> P;
int n, m, k;
const int maxn = 5e4 + 10;
const int mod = 998244353;
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
P a[3];
map<char, int> mp;
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char ch[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> ch;
        a[i].first = ch[0] - '0',
        a[i].second = ch[1];
        mp[ch[1]]++;
    }
    sort(a, a + 3);
    int res = 2;
    if (a[0].first == a[2].first && mp[a[0].second] == 3)
        res = 0;
    else if (a[0].first == a[1].first - 1 && a[1].first + 1 == a[2].first && mp[a[0].second] == 3)
        res = 0;
    else if (a[0].first == a[1].first - 1 && a[0].second == a[1].second)
        res = 1;
    else if (a[0].first == a[2].first - 2 && a[0].second == a[2].second)
        res = 1;
    else if (a[0].first == a[2].first - 1 && a[0].second == a[2].second)
        res = 1;
    else if (a[1].first + 1 == a[2].first && a[1].second == a[2].second)
        res = 1;
    else if (a[0].first == a[1].first - 2 && a[0].second == a[1].second)
        res = 1;
    else if (a[1].first == a[2].first - 2 && a[1].second == a[2].second)
        res = 1;
    else if (a[0].first == a[1].first && a[0].second == a[1].second)
        res = 1;
    else if (a[1].first == a[2].first && a[1].second == a[2].second)
        res = 1;
    else if (a[0].first == a[2].first && a[0].second == a[2].second)
        res = 1;
    else
        res = 2;
    cout << res << endl;
    return 0;
}