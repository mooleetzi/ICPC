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
#include <ext/rope>
#include <unordered_map>
#include <unordered_set>
#endif
#include <vector>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define LONG_LONG_MAX 9223372036854775807LL
#define ll LL
using namespace std;
using namespace __gnu_cxx;
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
inline int check(string t)
{
    int st = 0;
    for (int i = 0; i < n; i++)
        if (t[i] == '(')
            ++st;
        else
        {
            --st;
            if (st < 0)
                return 0;
        }
    return 1;
}
string s;
int q[maxn];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s;
    int f = 0, maxx = 0, rx, ry;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            swap(s[i], s[j]);
            int minx = 1e9;
            int p = 0;
            for (int k = 0; k < n; k++)
            {
                s[k] == '(' ? p++ : p--;
                q[k] = p;
                minx = min(minx, q[k]);
            }
            if (p)
                continue;
            int cur = 0;
            for (int k = 0; k < n; k++)
                if (q[k] == minx)
                    ++cur;
            if (cur > maxx)
            {
                f = 1;
                maxx = cur;
                rx = i, ry = j;
            }
            swap(s[i], s[j]);
        }
    if (f)
        cout << maxx << "\n"
             << rx + 1 << " " << ry + 1 << "\n";
    else
        cout << "0\n1 1\n";
    return 0;
}