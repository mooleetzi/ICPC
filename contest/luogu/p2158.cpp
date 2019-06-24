#include<bits/stdc++.h>
using namespace std;
const int maxn = 4e4 + 10;
int n;
int dp[maxn];
int main(int argc, char const *argv[])
{
    cin >> n;
    dp[1] = 1;
    for (int i = 2; i <maxn; i++)
    {
        if (dp[i])
            continue;
        for (int j = i; j < maxn; j += i)
        {
            if (!dp[j])
                dp[j] = j;
            dp[j] = dp[j] / i * (i - 1);
        }
    }
    int ans = 0;
    for (int i = 3; i <= n;i++)
        ans += dp[i-1];
    if (n==1){
        cout << 0;
        return 0;
    }
    cout << (ans*2+3);
    return 0;
}