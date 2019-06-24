#include<bits/stdc++.h>
using namespace std;
const int maxn = 1110;
int a[maxn],pre[maxn];
int getLen(int a[],int len){
    int dp[len + 10];
    int tot = 1;
    dp[1] = a[1];
    for (int i = 2; i <= len;i++){
        if (a[i]<=dp[tot])
            dp[++tot] = a[i];
        else
        {
            *lower_bound(dp + 1, dp + 1 + tot, a[i]) = a[i];
        }
    }
    return tot;
}
int main(int argc, char const *argv[])
{
    int l, r;
    int t,n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n;i++)
            pre[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i]>=a[i-1])
                pre[i] = i - 1;
        }
        int flag = 1;
        if (getLen(a,n)==n)
            cout << "1 1\n";
        else
        {
            int maxx = -1e9,now=0;
            int l=1, r=0;
            for (int i = 1; i <= n; i++){
                if (pre[i]==i-1){
                    ++now;
                    if (now>maxx){
                        r = i;
                        maxx = now;
                    }
                }
                else
                {
                    l = i;
                    now = 1;
                }
            }
            cout << r-maxx+1 << " " << r << "\n";
        }

        // else
        // for (int len = n - 1; len >= 1 && flag; len--)
        // {
        //     for (int i = 1; i + len <=n&&flag;i++){
        //         int j = i + len;
        //         int f = 1;
        //         for (int k = i; k <=j - 1; k++)
        //         {
        //             if (a[k]>a[k+1]){
        //                 f = 0;
        //                 break;
        //             }
        //         }
        //         if (f){
        //             cout << i << " " << j << "\n";
        //             flag = 0;
        //         }
        //     }
        // }
    }

    return 0;
}
