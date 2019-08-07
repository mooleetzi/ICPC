#include <iostream>
using namespace std;
using ll = long long;
/*
    euler(x)=x*(1-1/p1)*(1-1/p2)...
            =x*(p1-1)/p1*(p2-1)/p2
    公式法直接求
    note:一个数的所有质因子之和是euler(n)*n/2
 */
int euler(int x)
{
    int res = x, n = x;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            res = res / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        res = res / n * (n - 1);
    return res;
}
/*
    埃氏筛选法
 */
const int maxn = 1e5 + 10;
int e[maxn];
void getEuler()
{
    for (int i = 1; i < maxn; i++)
        e[i] = i;
    for (int i = 2; i < maxn; i++)
        if (e[i] == i)
            for (int j = i; j < maxn; j += i)
                e[j] = e[j] / i * (i - 1);
}

/*
欧拉法筛素数
 */

for (int i = 2; i <= maxn; i++)
{
    if (!vis[i])
        prime[pcnt++] = i;
    for (int j = 0; j < pcnt && i * prime[j] <= maxn; j++)
    {
        vis[i * prime[j]] = 1;
        if (i % prime[j] == 0)
            break;
    }
}
/*
欧拉法筛欧拉素数
 */
phi[1] = 1;
int cnt = 0;
for (int i = 2; i < maxn; i++)
{
    if (!vis[i])
    {
        prime[cnt++] = i;
        phi[i] = i - 1;
    }
    for (int j = 0; j < cnt && i * prime[j] < maxn; j++)
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
/*
    欧拉降幂
    a^b mod c  = a^(b mod phi(c)+phi(c)) mod c,此公式适用于(a,c)!=1,且b>phi(c),b<=phi(c)直接求a^b
    如(a,c)=1,有a^b  = a^(b mod phi(c)) (mod c)
    例题洛谷p5091
 */
