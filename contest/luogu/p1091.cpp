#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int dp1[maxn], dp2[maxn];
int n, a[maxn];
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1;i<=n;i++){
        dp1[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j]<a[i])
                dp1[i] = max(dp1[i], dp1[j] + 1);
    }
    for (int i = n; i >= 1;i--){
        dp2[i] = 1;
        for (int j = n; j > i; j--)
            if (a[j]<a[i])
                dp2[i] = max(dp2[i], dp2[j] + 1);
    }
    int ans = -1e9;
    for (int i = 1; i <= n;i++)
        ans = max(ans, dp1[i] + dp2[i]);
    cout << n - ans +1;
    return 0;
}
