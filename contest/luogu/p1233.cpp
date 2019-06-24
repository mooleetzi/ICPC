#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 10;
struct node
{
    int l, w;
    node(int a,int b):l(a),w(b){}
    node(){}
    bool operator<(const node &x){
        if (l==x.l)
            return w >=x.w;
        return l > x.l;
    }
    /* data */
}a[maxn];
int dp[maxn];
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        int x, y;
        cin >> x >> y;
        a[i] = node(x, y);
    }
    sort(a, a + n);
    int ans = 1;
    dp[1] = a[0].w;
    for (int i = 1; i < n;i++){
        if (a[i].w>dp[ans])
            dp[++ans] = a[i].w;
        else
        {
            *lower_bound(dp + 1, dp + 1 + ans, a[i].w) = a[i].w;
        }
    }
    cout << ans;
    return 0;
}

