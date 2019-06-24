#include<bits/stdc++.h>
using namespace std;
const int maxn = 310;
int a[maxn][maxn];
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    for (int i = 0;i<m;i++){
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    for (int k = 1; k <=n;k++)
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= n;j++)
                if (a[i][k]==1&&a[k][j]==1)
                    a[i][j] = 1;
    int ans = 0;
    for (int i = 1; i <= n;i++)
        for (int j = i+1; j <= n;j++)
            if (a[i][j]==1&&a[j][i]==1)
                ++ans;
    cout << ans << "\n";
    return 0;
}
