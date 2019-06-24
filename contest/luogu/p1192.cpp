#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5 + 10;
const int MOD = 100003;
int n, m;
int f[maxn];
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    f[0] = 1;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            if (i>=j)
            f[i]= (f[i]%MOD+f[i - j]%MOD)%MOD;
    cout << f[n];
    return 0;
}
