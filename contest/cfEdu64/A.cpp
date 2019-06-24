#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 3e5 + 10;
int n, m;
int a[maxn];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int d[4][4];
    d[1][2] = 3;
    d[1][3] = 4;
    d[2][1] = 3;
    d[2][3] = 1e9+7;
    d[3][1] = 4;
    d[3][2] = 1e9 + 7;
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    ll ans = 0;
    for (int i = 1; i < n;i++)
        if ((a[i]+a[i-1]==5)){
            cout << "Infinite";
            return 0;
        }
        else
        {
            ans += d[a[i - 1]][a[i]];
            if (i&&a[i-2]==3&&a[i-1]==1&&a[i]==2)
                --ans;
        }
    cout << "Finite\n";
    cout << ans;
    return 0;
}
