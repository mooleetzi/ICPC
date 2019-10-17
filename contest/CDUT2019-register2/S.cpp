/*
    1.扫一遍看s能否跳跃匹配，如果不能证明有反着的字符，不能通过添加字符完成转换
    2.对比s+p与t中相同字符的数目，都大于等于则ok
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
typedef pair<int, int> P;
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
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        unordered_map<char, int> ss, pp, tt, fs, ft;
        string s, p, t;
        cin >> s >> t >> p;
        int sz = s.size();
        for (int i = sz - 1; i >= 0; i--)
            ++ss[s[i]], fs[s[i]] = i;
        sz = t.size();
        for (int i = sz - 1; i >= 0; i--)
            ++tt[t[i]];
        for (auto x : p)
            ++pp[x];
        int f = 1;
        int cur = 0;
        for (int i = 0; i < sz && cur < s.size(); i++)
            if (t[i] == s[cur])
                ++cur;
        f = cur == s.size();
        if (f)
            for (auto x : tt)
            {
                char ch = x.first;
                int num = x.second;
                if (num > ss[ch] + pp[ch])
                {
                    f = 0;
                    break;
                }
            }
        if (f)
            cout << "YES\n";
        else
            cout << "NO" << endl;
    }
    return 0;
}