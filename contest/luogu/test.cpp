#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 10;
int pcnt;
int phi[maxn], prime[maxn / 10], vis[maxn];
void init()
{
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i])
        {
            prime[pcnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < pcnt && i * prime[j] < maxn; j++)
        {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
            {
                phi[i * prime[j]] = phi[i] * phi[prime[j]]; // phi[i]*(prime[j]-1);
            }
        }
    }
}
inline int solve(int n)
{
    int res = 0;
    for (int i = 2; i <= n; i++)
        res += i * phi[i] / 2;
    return res;
}
int main()
{
    init();
    int n, a, b, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        cout << solve(n) << endl;
    }
    return 0;
}