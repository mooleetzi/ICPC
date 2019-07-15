#include<iostream>
#include<vector>
using namespace std;
const int maxn = 255;
const int maxw = 1010;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
int w[maxn], t[maxn];
double dp[maxn], a[maxn];
int n, ww;
int judge(double x){
    for (int i = 0; i < n;i++)
        a[i] = t[i] - x * w[i];
    for (int i = 0; i <= ww;i++)
        dp[i] = -inf;
    dp[0] = 0;
    for (int i = 0; i < n;i++)
        for (int j = ww; j >= 0;j--)
            dp[min(ww, j + w[i])] = max(dp[min(ww, j + w[i])], dp[j] + a[i]);
    return dp[ww] >= 0;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> ww;
    for (int i = 0; i < n;i++)
        cin >> w[i] >> t[i];
    double l = 0, r = 1e6 + 1;
    while(r-l>eps){
        double mid = (l + r) / 2;
        if (judge(mid))
            l = mid;
        else
            r = mid;
    }
    int ans = l * 1000;
    cout << ans << "\n";
    return 0;
}
