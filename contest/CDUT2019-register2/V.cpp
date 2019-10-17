/*
    找到01不同点输出即可，k最大为2
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
string s;
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s;
    int z = 0, o = 0;
    int sz = s.size();
    for (int i = 0; i < sz; i++)
        if (s[i] == '1')
            ++o;
        else
            ++z;
    if (o != z)
    {
        cout << 1 << endl;
        cout << s << endl;
    }
    else
    {
        cout << 2 << endl;
        int oo = 0, zz = 0;
        for (int i = 0; i < sz; i++)
        {
            if (s[i] == '1')
                ++oo;
            else
                ++zz;
            if (oo != zz)
            {
                cout << s.substr(0, i + 1) << " " << s.substr(i + 1, sz);
                break;
            }
        }
    }
    return 0;
}