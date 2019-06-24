#include <bits/stdc++.h>
using namespace std;
// using pa = pair<double, double>;
typedef pair<double, double> pa;
const int maxn = 3e2 + 10;
pa t[maxn];
int n, top, p;
int st[maxn];
inline double mul(pa x0, pa x1, pa x2)
{
    return (x1.first - x0.first) * (x2.second - x0.second) - (x1.second - x0.second) * (x2.first - x0.first);
}
inline double len(pa x1, pa x2)
{
    return sqrt((x1.first - x2.first) * (x1.first - x2.first) + (x1.second - x2.second) * (x1.second - x2.second));
}
inline int cost(pa x1, pa x2)
{
    return (int)(abs(x1.first + x2.first) * abs(x1.second + x2.second)) % p;
}
int cmp(pa x1, pa x2)
{
    double k = mul(t[1], x1, x2);
    if (k > 0)
        return 1;
    else if (k == 0 && len(t[1], x1) <= len(t[1], x2))
        return 1;
    return 0;
}
int graham()
{
    for (int i = 1; i <= 2; i++)
        st[i] = i;
    top = 2;
    for (int i = 3; i <= n; i++)
    {
        while (top > 1 && mul(t[st[top - 1]], t[st[top]], t[i]) <= 0)
            --top;
        st[++top] = i;
    }
    return top == n;
}
int dp[maxn][maxn], c[maxn][maxn];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> p)
    {
        for (int i = 1; i <= n; i++)
            cin >> t[i].first >> t[i].second;
        for (int i = 2; i <= n; i++)
            if (t[i].second < t[1].second || (t[i].second == t[1].second && t[i].first < t[1].first))
                swap(t[1], t[i]);
        sort(t + 1, t + 1 + n, cmp);
        if (!graham())
            cout << "I can't cut.\n";
        else
        {
            for (int i = 1; i <= n; i++)
                for (int j = i + 2; j <= n; j++)
                    c[i][j] = c[j][i] = cost(t[i], t[j]);
            memset(dp, 0x3f, sizeof dp);
            for (int i = 1; i <= n; i++)
                dp[i][i + 1] = dp[i][i - 1] = dp[i][i] = 0;
            for (int l = 1; l <= n; l++)
                for (int i = 1; i + l <= n; i++)
                {
                    int j = i + l;
                    for (int k = i; k <= j; k++)
                        dp[i][j] = min(dp[i][j], dp[i][k] + c[i][k] + dp[k][j] + c[k][j]);
                }
            cout << dp[1][n] << "\n";
        }
    }
    return 0;
}
