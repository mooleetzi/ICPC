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
int n, m, q;
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
int last[maxn][27], nxt[maxn][27], pre[26];
char s[maxn], query[55];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read<int>(), q = read<int>();
    scanf("%s", s);
    memset(pre, -1, sizeof pre);
    for (int i = 0; i < 26; i++)
    {
        if (s[n - 1] - 'a' == i)
            pre[i] = n - 1;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            nxt[i][j] = pre[j];
        }
        pre[s[i] - 'a'] = i;
    }
    while (q--)
    {
        scanf("%s", query);
        int len = strlen(query);
        if (len > n)
        {
            puts("NO");
            continue;
        }
        int f = 1;
        int cur = pre[query[0] - 'a'];
        if (cur == -1)
        {
            puts("NO");
            continue;
        }
        int res = 1;
        while (res < len && cur != -1)
        {
            cur = nxt[cur][query[res] - 'a'];
            ++res;
        }
        if (res == len)
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}