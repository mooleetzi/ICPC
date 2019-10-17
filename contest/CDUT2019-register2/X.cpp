/*
    不必要写线段树的，直接前缀和就行
    !!注意s在0~9之间
    两个数要有贡献则其和>=10,而%10之后又变回了0~9那么相当于每次区间变小我们可以选择不%10，直接保留原数
    最后累加之后的和/10就是结果，
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
struct node
{
    int l, r, val, res;
} tr[maxn << 2];
void push_up(int rt)
{
    tr[rt].val = tr[rt << 1].val + tr[rt << 1 | 1].val;
}
void build(int rt, int l, int r)
{
    tr[rt].l = l, tr[rt].r = r;
    if (l == r)
    {
        tr[rt].val = a[l];
        tr[rt].res = 0;
        return;
    }
    int mid = l + r >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}
int query(int rt, int L, int R)
{
    int l = tr[rt].l, r = tr[rt].r;
    if (l >= L && r <= R)
        return tr[rt].val;
    int mid = l + r >> 1;
    int res = 0;
    if (L <= mid)
        res += query(rt << 1, L, R);
    if (R > mid)
        res += query(rt << 1 | 1, L, R);
    return res;
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
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(1, l, r) / 10 << "\n";
    }
    return 0;
}