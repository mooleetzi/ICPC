#include<iostream>
#include<algorithm>
#include<deque>
typedef long long ll;
using namespace std;
const int maxn = 1e5 + 10;
int n;
ll q[maxn];
ll dp[maxn],a[maxn];

ll m;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        if (a[i]>m){
            cout << "-1";
            return 0;
        }
    }
    ll sum = 0;
    int h = 0, t = 0,now=1;
    for (int i = 1; i <= n;i++){
        sum += a[i];
        while(h<t&&a[q[t-1]]<=a[i])
            --t;
        q[t++] = i;
        while(sum>m)
            sum -= a[now++];
        while(q[h]<now)
            h++;
        dp[i] = dp[now - 1] + a[q[h]];
        for (int j = h + 1; j < t;j++)
            dp[i] = min(dp[i], dp[q[j-1]] + a[q[j]]);
    }
    cout << dp[n];
    return 0;
}
