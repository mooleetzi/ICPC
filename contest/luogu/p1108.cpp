#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 10;
int a[maxn];
int dp[maxn],f[maxn];
int n,ans;
bool cmp(int x,int y){
    return x > y;
}
int main(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    int a1 = 0, a2 = 0;
    for (int i = 1; i <= n;i++){
        dp[i] = 1;
        for (int j = 1; j < i;j++)
            if (a[j]>a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        a1 = max(a1, dp[i]);
    }
    for (int i = 1; i <= n;i++){
        f[i] = dp[i]==1;
        for (int j = 1; j < i;j++)
            if (dp[i]==dp[j]+1&&a[i]<a[j])
                f[i] += f[j];
            else if (dp[i]==dp[j]&&a[i]==a[j])
            {
                f[j] = 0;
            }
    }
    for (int i = 1; i <= n; i++){
        if (dp[i]==a1)
            a2 += f[i];
    }
    cout << a1 << " " << a2;
    return 0;
}