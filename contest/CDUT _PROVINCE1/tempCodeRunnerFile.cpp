#include <bits/stdc++.h>
using namespace std;
using pa = pair<int, int>;
using ll = long long;
const int maxn = 1e5 + 10;
struct pair_hash
{ //pair hash方法
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &pair) const
    {
        return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
    }
};
int a[maxn];
int n, q;
struct node{
    int l, r, g;
}tr[maxn<<2];
unordered_map<int, int> mp[maxn];
unordered_map<int, int> ans;
void build(int rt,int l,int r){
    tr[rt].l = l;
    tr[rt].r=r;
    if (l==r){
        tr[rt].g = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1,r);
    tr[rt].g = __gcd(tr[rt << 1].g, tr[rt << 1 | 1].g);
}
int query(int rt,int L,int R){
    int l = tr[rt].l;
    int r = tr[rt].r;
    if (l>=L&&r<=R)
        return tr[rt].g;
    int mid = l + r >> 1;
    if (mid >= R)
        return query(rt << 1, L, R);
    else if (mid < L)
        return query(rt << 1 | 1, L, R);
    else
        return __gcd(query(rt << 1, L, mid), query(rt << 1 | 1, mid + 1, R));
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; ++cas)
    {
        cin >> n;
        for (int i = 1; i <= n;i++)
            cin >> a[i];
        build(1, 1, n);
        for (int i = 1; i <= n; i++)
            mp[i].clear();
        ans.clear();
        for (int i = n; i >= 1; i--)
        {
            int d = a[i];
            mp[i][d]++;
            if (i == n)
                continue;
            for (auto x:mp[i+1])
            {
                mp[i][__gcd(d, x.first)] += x.second;
            }
        }
        for (int i = 1; i <= n;i++){
            for (auto x:mp[i])
                ans[x.first] += x.second;
        }
        cin >> q;
        cout << "Case #" << cas << ":\n";
        for (int i = 1; i <= q;i++){
            int l, r;
            cin >> l >> r;
            int g = query(1, l, r);
            cout << g << " " << ans[g] << "\n";
        }
    }
    return 0;
}
