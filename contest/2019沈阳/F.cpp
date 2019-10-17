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
template <class T>
inline void writeln(const T &n)
{
    write(n);
    puts("");
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d%d", &n, &k))
    {
        unordered_map<int, int> mp;
        priority_queue<int, vector<int>, greater<int>> q1;
        priority_queue<int> q2;
        while (!q1.empty())
            q1.pop();
        while (!q2.empty())
            q2.pop();
        mp.clear();
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            ++mp[x];
            if (mp[x] == 1)
            {
                q1.emplace(x);
                q2.emplace(x);
            }
        }
        int f = -1;
        while (k > 0)
        {
            int t1 = q1.top();
            int t2 = q2.top();
            while (!mp[t1])
            {
                q1.pop();
                t1 = q1.top();
            }
            while (!mp[t2])
            {
                q2.pop();
                t2 = q2.top();
            }
            if (t1 == t2)
            {
                f = 0;
                break;
            }
            else if (t1 == t2 - 1)
            {
                f = 1;
                break;
            }
            int dec = min(mp[t1], mp[t2]);
            dec = min(dec, k);
            k -= dec;
            mp[t1] -= dec;
            mp[t2] -= dec;
            if (!mp[t1 + 1])
                q1.emplace(t1 + 1);
            if (!mp[t2 - 1])
                q2.emplace(t2 - 1);
            mp[t1 + 1] += dec;
            mp[t2 - 1] += dec;
            if (!mp[t1])
                q1.pop();
            if (!mp[t2])
                q2.pop();
        }
        if (f != -1)
            printf("%d\n", f);
        else
        {
            int t1 = q1.top();
            int t2 = q2.top();
            // cout << t1 << " " << t2 << "\n";
            printf("%d\n", t2 - t1);
        }
    }
    return 0;
}