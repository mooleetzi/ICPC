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
char str[30];
const int s = 17 * 1800, D = 19 * 1800, E = 25 * 1800;
int main()
{
    while (~scanf("%d", &n) && n)
    {
        int cnt = 0;
        for (int cas = 0; cas < n; cas++)
        {
            int S = 0, T = 0, tot = 0, pre = 0, p = 3600;
            scanf("%s", str);
            int len = strlen(str);
            for (int i = 2; i < len; i++)
            {
                if (str[i] != ':' && i != len - 1)
                    pre = pre * 10 + str[i] - '0';
                else
                {
                    if (i == len - 1)
                        pre = pre * 10 + str[i] - '0';
                    tot++;
                    if (tot <= 3)
                    {
                        S += pre * p;
                        if (tot == 3)
                            p = 3600;
                        else
                            p /= 60;
                    }
                    else
                        T += pre * p, p /= 60;
                    pre = 0;
                }
            }
            int flag = 0;
            if (str[0] == 'D' && S > D)
                flag = 1;
            if (str[0] == 'E' && S > E)
                flag = 1;
            int res = T - max(s, S);
            if (str[0] == 'D' && res < 8 * 3600)
                flag = 1;
            if (str[0] == 'E' && res < 9 * 3600)
                flag = 1;
            cnt += flag;
        }
        if (!cnt)
            puts("All OK");
        else if (cnt <= 3)
            printf("%d Point(s) Deducted\n", cnt);
        else
            puts("Issue Show Cause Letter");
    }
}