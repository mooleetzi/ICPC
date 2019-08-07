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
// template <class T>
// inline T read(T &ret)
// {
//     int f = 1;
//     ret = 0;
//     char ch = getchar();
//     while (!isdigit(ch))
//     {
//         if (ch == '-')
//             f = -1;
//         ch = getchar();
//     }
//     while (isdigit(ch))
//     {
//         ret = (ret << 1) + (ret << 3) + ch - '0';
//         ch = getchar();
//     }
//     ret *= f;
//     return ret;
// }
// template <class T>
// inline void write(T n)
// {
//     if (n < 0)
//     {
//         putchar('-');
//         n = -n;
//     }
//     if (n >= 10)
//     {
//         write(n / 10);
//     }
//     putchar(n % 10 + '0');
// }
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
