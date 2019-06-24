#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll f[40][160];

int main()
{
    int n;
    scanf("%d", &n);
    if (!n)
        return puts("1/1"), 0;
    f[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= 4 * i; j++)
            for (int k = 1; k <= 4; k++)
                f[i + 1][j + k] += f[i][j];
    ll Ans1 = 0, Ans2 = 1ll << (2 * n);
    for (int i = 3 * n; i <= 4 * n; i++)
        Ans1 += f[n][i];
    ll d = __gcd(Ans2, Ans1);
    printf("%lld/%lld\n", Ans1 / d, Ans2 / d);
}