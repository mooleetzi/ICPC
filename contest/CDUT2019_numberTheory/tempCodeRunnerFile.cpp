#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
// #define DEBUG
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k;
const int maxE = 5e5 + 10;
const int maxn = 4e4 + 10;
template <class T>
inline void read(T &ret)
{
    int f = 1;
    ret = 0;
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
short p[maxE];
int a[maxn];
unordered_set<int> ss;
unordered_set<int> s1, s2;
vector<int> s[maxE];
void init()
{
    for (int i = 3; i < maxE; i += 2)
        p[i] = 1;
    p[2] = 1;
    for (int i = 2; i < maxE; i++)
        if (p[i])
            for (int j = 2 * i; j < maxE; j += i)
                p[j] = 0;
}
int main(int argc, char const *argv[])
{
    init();
    int t;
    read(t);
    int tot = 1;
    while (t--)
    {
        ss.clear();
        s1.clear();
        s2.clear();
        read(n);
        int maxx = 0;
        for (int i = 0; i < n; i++)
            read(a[i]), ss.insert(a[i]), maxx = max(maxx, a[i]);
        for (int i = 1; i <= maxx; i++)
            s[i].clear();
        sort(a, a + n);
        for (int i = 0; i < n; i++)
        {
            int x = a[i];
            int m = sqrt(x);
            for (int j = 1; j <= m; j++)
            {
                if (x % j == 0)
                {

                    int k = x / j;
                    if (p[k] && ss.count(j))
                        s[j].emplace_back(x);
                    if (p[j] && ss.count(k))
                        s[k].emplace_back(x);
                }
            }
        }
#ifdef DEBUG
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << ":";
            for (auto x : s[a[i]])
                cout << x << " ";
            cout << "\n";
        }
#endif
        for (int i = 0; i < n; i++)
        {
            int x = a[i];
            if (!s1.count(x) && !s2.count(x))
            {
                s1.insert(x);
                for (auto y : s[x])
                    s2.insert(y);
            }
            else if (s1.count(x))
            {
                for (auto y : s[x])
                    s2.insert(y);
            }
            else
            {
                for (auto y : s[x])
                    s1.insert(y);
            }
        }
        printf("Case %d: %u\n", tot++, max(s1.size(), s2.size()));
    }
    return 0;
}
