#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
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
#define pblank putchar(' ')
#define ll LL
#define fastIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
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
template <typename T>
void _write(const T &t)
{
    write(t);
}
template <typename T, typename... Args>
void _write(const T &t, Args... args)
{
    write(t), pblank;
    _write(args...);
}
template <typename T, typename... Args>
inline void write_line(const T &t, const Args &... data)
{
    _write(t, data...);
}
string s[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
unordered_map<int, string> mp;
void init()
{
    for (int i = 0; i <= 20; i++)
        mp[i] = s[i];
    mp[30] = "thirty", mp[40] = "forty", mp[50] = "fifty";
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt","w", stdout);
#endif
    init();
    int h = read<int>(), m = read<int>();
    if (m >= 60)
        h += m / 60, m %= 60;
    if (h >= 24)
        h %= 24;
    if (!m)
    {
        if (h > 20)
            printf("%s %s", s[20].c_str(), s[h - 20].c_str());
        else
            printf("%s", s[h].c_str());
        printf(" o'clock\n");
    }
    else
    {
        if (h > 20)
            printf("%s %s", s[20].c_str(), s[h - 20].c_str());
        else
            printf("%s", s[h].c_str());
        if (m <= 20)
            printf(" %s", s[m].c_str());
        else
        {
            if (m % 10 == 0)
                printf(" %s\n", mp[m].c_str());
            else if (m)
                printf(" %s %s\n", mp[(m / 10) * 10].c_str(), mp[m % 10].c_str());
        }
    }
    return 0;
}