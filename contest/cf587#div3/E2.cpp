#include <algorithm>
#include <numeric>
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
ll lten[20];
void init()
{
    ll p = 1;
    for (int i = 0; i < 19;i++)
        lten[i] = p, p *= 10;
}
inline ll num(ll x){
    return (x + 1) * x / 2;
}
ll solve(ll x,int op){
    ll sum = 0, pre = 1, add = 0;
    for (int len = 1;;len++){
        if (10LL*pre-1<x){
            ll cnt = 10 * pre - pre;
            if (op)
            {
                sum += add * cnt + num(cnt) * len;
                add += cnt * len;
            }
            else
                sum += cnt * len;
        }
        else{
            ll cnt = x - pre + 1;
            if (op)
                sum += add * cnt + num(cnt) * len;
            else
                sum += cnt * len;
            break;
        }
        pre *= 10;
    }
    return sum;
}
string tostring(ll x)
{
    string str = "";
    while (x)
        str += char(x % 10 + '0'), x /= 10;
    reverse(str.begin(), str.end());
    return str;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r", stdin);
    // freopen("out.txt","w", stdout);
#endif
    fastIO;
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        --n;
        ll l = 1, r = 1e9,res=-1;
        while(l<=r){
            ll mid = l + r >> 1;
            if (solve(mid,1)>n){
                res = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        n -= solve(res - 1, 1);

        l = 1, r = res,res=-1;
        while(l<=r){
            ll mid = l + r >> 1;
            if (solve(mid,0)>n)
                res = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        n -= solve(res - 1, 0);
        cout << tostring(res)[n] << "\n";
    }
    return 0;
}