/*
    排序一遍
    1..n-1肯定满足大小关系，将a[n-1]和a[n-2]互换更加满足=>
    1..n-1,n-2
    如此可将最大的a[n]放在a[n-1]和a[n-2]间比较，如果满足则输出yes否则为no
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
const int maxn = 1e5 + 10;
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
int a[maxn];
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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    if (a[n - 1] >= a[n - 2] + a[n - 3])
        cout << "NO";
    else
    {
        cout << "YES\n";
        for (int i = 0; i < n - 3; i++)
            cout << a[i] << " ";
        cout << a[n - 2] << " " << a[n - 1] << " " << a[n - 3];
    }
    return 0;
}