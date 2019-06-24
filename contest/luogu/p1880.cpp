#include<bits/stdc++.h>
using namespace std;
const int maxn = 220;
int a[maxn], f1[maxn][maxn], f2[maxn][maxn],sum[maxn],n;
int dfs1(int l,int r){
    if (f1[l][r])
        return f1[l][r];
    if (l==r)
        return f1[l][r] = 0;
    int res = 1e9;
    for (int i = l; i < r; i++)
    {
        res = min(res, dfs1(l, i) + dfs1(i + 1, r) + sum[r] - sum[l - 1]);
    }
    return f1[l][r]=res;
}
int dfs2(int l,int r){
    if (f2[l][r])
        return f2[l][r];
    if (l == r)
        return f2[l][r] = 0;
    for (int i = l; i < r; i++)
    {
        f2[l][r] = max(f2[l][r], dfs2(l, i) + dfs2(i + 1, r) + sum[r] - sum[l - 1]);
    }
    return f2[l][r];
}
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <=n;i++){
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2*n;i++)
        sum[i] = sum[i - 1] + a[i];
    dfs1(1, 2 * n);
    dfs2(1, 2 * n);
    int ans1 = 1e9;
    int ans2 = 0;
    for (int i = 1; i <= n; i++)
    {
        ans1 = min(ans1, f1[i][i + n - 1]);
        ans2 = max(ans2, f2[i][i + n - 1]);
    }
    cout << ans1 << "\n"
         << ans2;
    return 0;
}
