#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int tot;
int a[maxn];
int n;
int dp[maxn];
int main(int argc, char const *argv[])
{
    cin>>n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    int ans = 1;
    int now = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i]<=2*a[i-1])
            ++now, ans = max(ans, now);
        else
        {
            now = 1;
        }
    }
    cout << ans;
    return 0;
}
