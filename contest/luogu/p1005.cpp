#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
using ll = __int128_t;
void print(ll x){
    vector<int> ans;
    ans.clear();
    if (!x)
        ans.emplace_back(0);
    while (x)
    {
        ans.emplace_back(x % 10);
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    for (auto t:ans)
        putchar(t + 48);
    putchar('\n');
}
int n, m;
ll dp[maxn][maxn];
int a[maxn];
ll ans;
ll p[85];
template <class T>
inline T read(T&ans)
{
    ans = 0;
    char ch=getchar();
    while (!isdigit(ch)){
        ch = getchar();
    }
    while (isdigit(ch)){
        ans = (ans << 1) + (ans << 3) + ch - 48;
        ch = getchar();
    }
    return ans;
}
void init(){
    p[0] = 1;
    for (int i = 1; i <= 81; i++)
        p[i] = p[i - 1] * 2;
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    init();
    while (n--)
    {
        for (int i = 1; i <= m; i++)
            cin >> a[i];
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                dp[i][j] = 0;
        for (int i = 1; i <= m; i++)
            for (int j = m; j >= i; j--)
            {
                int t = m - j + i-1;
                dp[i][j] = max(dp[i - 1][j] + a[i - 1] * p[t],dp[i][j+1]+a[j+1]*p[t]);
            }
        ll now = 0; 
        for (int i = 1; i <= m; i++)
            now = max(now, dp[i][i]+a[i]*p[m]);
        ans += now;
    }
    print(ans);
    return 0;
}
