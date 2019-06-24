#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int dp1[maxn], dp2[maxn];
int a[maxn];
int n;
struct cmp
{
    bool operator()(int a,int b){
        return a>b;
    }
};

int main(int argc, char const *argv[])
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int x;
    while (cin >> x)
    {
        a[++n] = x;
    }
    int res1 = 1, res2 = 1;
    dp1[res1] = a[1];
    dp2[res2] = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (a[i] <= dp1[res1])
        {
            dp1[++res1] = a[i];
        }
        else
        {
            *upper_bound(dp1 + 1, dp1 + 1 + res1, a[i],cmp()) = a[i];
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > dp2[res2])
        {
            dp2[++res2] = a[i];
        }
        else
        {
            *lower_bound(dp2 + 1, dp2 + 1 + res2, a[i]) = a[i];
        }
    }
    cout << res1 << "\n"
         << res2 << "\n";
    return 0;
}
