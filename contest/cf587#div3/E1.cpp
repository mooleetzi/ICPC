#include<bits/stdc++.h>
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
ll n, m, k;
const int maxn = 1e6 + 10;
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
ll p[maxn];
ll t[maxn];
string tostring(int x){
    string str = "";
    while(x)
        str += char(x % 10 + '0'), x /= 10;
    reverse(str.begin(), str.end());
    return str;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt","w", stdout);
#endif
    fastIO;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll nxt = 10;
        ll len = 1;
        ll pre = 0;
        --n;
        for (ll i = 1;; i++)
        {
            if (i == nxt)
            {
                ++len;
                nxt *= 10;
            }
            pre += len;
            if (n >= pre)
                n -= pre;
            else
            {
                ll nxt = 10, len = 1, pre = 0;
                for (ll j = 1;j<=i; j++)
                {
                    if (j == nxt)
                    {
                        ++len;
                        nxt *= 10;
                    }
                    if (n>=len)
                        n -= len;
                    else{
                        cout << tostring(j)[n] << "\n";
                        break;
                    }
                }
                break;
            }
        }
    }
    return 0;
}