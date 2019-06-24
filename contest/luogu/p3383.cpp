#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000010;
int f[maxn];
int prime[maxn];
int tot;
void get_prime(int n)
{
    for (int i = 2;i<=n;i++)
        f[i] = 1;
    f[0] = f[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (f[i])
            prime[tot++] = i;
        for (int j = 0; j < tot && prime[j] * i <= n; j++)
        {
            f[prime[j] * i] = 0;
            if (i % prime[j] == 0)
                break;
        }
    }
}
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    get_prime(n);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        if (f[x])
            cout << "Yes\n";
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}
