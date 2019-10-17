// #include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <iostream>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
// using ll = long long;
// using ull = unsigned long long;
// using pa = pair<int, int>;
// using ld = long double;
typedef long long ll;
const int maxn = 5100;
const int mod = 100000007;
ll n, k, m, pre, r;
int isprime(int x)
{
    if (x == 1)
        return 0;
    if (x == 2)
        return 0;
    int m = sqrt(x) + 1;
    for (int i = 2; i <= m; i++)
        if (x % i == 0)
            return 0;
    return 1;
}
int main(int argc, char const *argv[])
{
    int tot = 1, t;
    while (scanf("%d", &t) && t > 0)
    {
        printf("%d: ", tot++);
        if (isprime(t))
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
