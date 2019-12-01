#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2e5 + 10;
int cnt, root[maxn], a[maxn];
vector<int> v;
struct Node
{
    int l, r, sum;
} hjt[maxn * 40];
void insert(int l, int r, int pre, int &now, int x)
{
    hjt[++cnt] = hjt[pre];
    now = cnt;
    hjt[now].sum++;
    if (l == r)
        return;
    int mid = l + r >> 1;
    if (x <= mid)
        insert(l, mid, hjt[pre].l, hjt[now].l, x);
    if (x > mid)
        insert(mid + 1, r, hjt[pre].r, hjt[now].r, x);
}
int query(int l, int r, int L, int R, int k)
{
    if (hjt[R].sum - hjt[L].sum < k)
        return 0;
    if (l == r)
        return hjt[R].sum - hjt[L].sum >= k;
    int mid = l + r >> 1;
    return query(l, mid, hjt[L].l, hjt[R].l, k) + query(mid + 1, r, hjt[L].r, hjt[R].r, k);
}
inline int getid(int x)
{
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}
int main(int argc, char const *argv[])
{
    freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        v.emplace_back(a[i]);
    }
    sort(v.begin(), v.end());                     //排序
    v.erase(unique(v.begin(), v.end()), v.end()); //离散化
    int vlen = v.size();
    for (int i = 1; i <= n; i++)
        insert(1, vlen, root[i - 1], root[i], getid(a[i]));
    while (m--)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", query(1, vlen, root[l - 1], root[r], k));
    }
    return 0;
}
