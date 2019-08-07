#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k;
const int maxn = 1e5 + 10;
const int mod = 998244353;
template <class T>
inline T read(T &ret)
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
char a[4][4];
void rot(int t, char c)
{
    if (t == 1)
    {
        if (c == 'R')
        {
            char s = a[0][0];
            a[0][0] = a[0][1];
            a[0][1] = a[1][1];
            a[1][1] = a[1][0];
            a[1][0] = s;
        }
        else
        {
            char s = a[0][0];
            a[0][0] = a[1][0];
            a[1][0] = a[1][1];
            a[1][1] = a[0][1];
            a[0][1] = s;
        }
    }
    else if (t == 2)
    {
        if (c == 'R')
        {
            char s = a[0][1];
            a[0][1] = a[0][2];
            a[0][2] = a[1][2];
            a[1][2] = a[1][1];
            a[1][1] = s;
        }
        else
        {
            char s = a[0][1];
            a[0][1] = a[1][1];
            a[1][1] = a[1][2];
            a[1][2] = a[0][2];
            a[0][2] = s;
        }
    }
    else if (t == 3)
    {
        if (c == 'R')
        {
            char s = a[1][0];
            a[1][0] = a[1][1];
            a[1][1] = a[2][1];
            a[2][1] = a[2][0];
            a[2][0] = s;
        }
        else
        {
            char s = a[1][0];
            a[1][0] = a[2][0];
            a[2][0] = a[2][1];
            a[2][1] = a[1][1];
            a[1][1] = s;
        }
    }
    else if (t == 4)
    {
        if (c == 'R')
        {
            char s = a[1][1];
            a[1][1] = a[1][2];
            a[1][2] = a[2][2];
            a[2][2] = a[2][1];
            a[2][1] = s;
        }
        else
        {
            char s = a[1][1];
            a[1][1] = a[2][1];
            a[2][1] = a[2][2];
            a[2][2] = a[1][2];
            a[1][2] = s;
        }
    }
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < 3; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            char s[5];
            cin >> s;
            rot(s[0] - '0', s[1]);
        }
        for (int i = 0; i < 3; i++)
            cout << a[i] << "\n";
    }
    return 0;
}
