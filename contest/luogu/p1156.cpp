#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int dp[maxn][maxn];
int n,d,ok=0;
struct node
{
    int s, t, h;
    node(){
        s = t = h = 0;
    }
}a[maxn];
int main(int argc, char const *argv[])
{
    cin >> d >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i].s >> a[i].t >> a[i].h;
    sort(a + 1, a + 1 + n, [](node a, node b) { return a.s < b.s; });
    memset(dp, -1, sizeof dp);
    dp[0][0] = 10;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= d;j++){
            if (dp[i-1][j]>=a[i].s-a[i-1].s){
                dp[i][j] = max(dp[i][j], dp[i - 1][j]-a[i].s+a[i-1].s+a[i].t);
            }
            if (j>=a[i].h&&dp[i-1][j-a[i].h]-a[i].s+a[i-1].s>=0){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].h] + a[i - 1].s - a[i].s);
                if (j==d){
                    cout << a[i].s;
                    return 0;
                }
            }
        }
    int maxx = -1e9;
    for (int i = 0; i <= n;i++)
        for (int j = 0; j <= d;j++)
            if (~dp[i][j]){
                maxx = max(dp[i][j] + a[i].s, maxx);
            }
    cout << maxx;
    return 0;
}
