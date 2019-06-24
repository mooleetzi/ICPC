/*
    考虑权值1,2的前缀和
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 3e5 + 10;
int n, q;
struct node
{
    int l, r;
}a[maxn];
int vis[maxn],pre1[maxn],pre2[maxn];
int main(int argc, char const *argv[])
{
    cin >> n >> q;
    for (int i = 0; i < q;i++){
        cin >> a[i].l >> a[i].r;
        for (int j = a[i].l; j <= a[i].r;j++)
            ++vis[j];
    }
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i]==1)
            pre1[i] = pre1[i - 1] + 1, pre2[i] = pre2[i - 1];
        else if (vis[i]==2)
        {
            pre1[i] = pre1[i - 1], pre2[i] = pre2[i - 1] + 1;
        }
        else
        {
            pre1[i] = pre1[i - 1];
            pre2[i] = pre2[i - 1];
        }

        if (vis[i])
            ++tot;
    }
    int ans = 0;
    for (int i = 0; i < q; i++)
        for (int j = i + 1; j < q;j++){
            int tmp = tot;
            int la = a[i].l, lb = a[j].l;
            int ra = a[i].r, rb = a[j].r;
            tmp -= pre1[ra] - pre1[la-1] + pre1[rb] - pre1[lb-1];
            int ml = max(la, lb);
            int mr = min(ra, rb);
            if (ml <= mr)
                tmp -= pre2[mr] - pre2[ml-1];
            ans = max(tmp, ans);
        }
    cout << ans;
    return 0;
}

