#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int a[maxn];
int n;
int b[200010];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    for (int i = 0; i < n;i++)
        for (int j = i + 1; j < n;j++)
            ++b[a[i] + a[j]];
    int ans = 0;
    for (int i = 0; i < 200010;i++)
        ans = max(ans, b[i]);
    cout << ans;
    return 0;
}
