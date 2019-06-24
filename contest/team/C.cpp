#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int c, b, n;
int a[maxn];
char ans[maxn];
set<int> s;
struct node
{
    int l, r,t;
    node(int a,int b){
        l = a;
        r = b;
    }
    node(){}
    bool operator<(const node&x){
        return t < x.t;
    }
};
vector<node> ma;
int tot;
int main(int argc, char const *argv[])
{
    cin >> n >> c >> b;
    int now = 0;
    for (int i = 1; i <= n; i++)
        ans[i] = '1';
    for (int i = 1; i <= b; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
        ans[x] = '0';
    }
    int pre = 1;
    for (int i = 1; i <= n;i++){
        if (ans[i]=='0'){
            node cur = node(pre, i - 1);
            if (pre==1)
                cur.t = 1;
            else
                cur.t = 2;
            int j;
            for (j = i + 1; j <= n; j++)
                if (ans[j]=='1')
                    break;
            pre = j;
            i = j;
            ma.emplace_back(cur);
        }
    }
    if (ans[n]=='1'){
        node cur = node(pre, n);
        cur.t = 1;
        ma.emplace_back(cur);
    }
    sort(ma.begin(), ma.end());
    for (int i = 2; i <= n; i++)
    {
        if (ans[i - 1] != ans[i])
            ++now;
    }
    // for (int i = 0; i < tot;i++)
    //     cout << ma[i].l << " " << ma[i].r << " " << ma[i].t << "\n";
    int cur = now - c;
    for (auto x = ma.begin(); x != ma.end();x++){
        cur -= (*x).t;
        for (int i = x->l; i <= x->r;i++)
            ans[i] = '0';
        if (cur <= 0)
            break;
    }
    if (cur){
        for (int i = 2;i<=n-1;i++)
            if (ans[i]==ans[i-1]&&ans[i]==ans[i+1]&&ans[i]=='1'){
                ans[i] = '0';
                break;
            }
    }
    cout << ans + 1;
    return 0;
}
