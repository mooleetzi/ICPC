#include<iostream>
using namespace std;
using ll = long long;
/*
    euler(x)=x*(1-1/p1)*(1-1/p2)...
            =x*(p1-1)/p1*(p2-1)/p2
    公式法直接求
    note:一个数的所有质因子之和是euler(n)*n/2
 */
int euler(int x){
    int res = x, n = x;
    for (int i = 2; i * i <= n;i++)
        if (n%i==0){
            res = res / i * (i - 1);
            while (n%i==0)
                n /= i;
        }
    if (n>1)
        res = res / n * (n - 1);
    return res;
}
/*
    筛选法
 */
const int maxn = 1e5 + 10;
int e[maxn];
void getEuler(){
    for (int i = 1; i < maxn;i++)
        e[i] = i;
    for (int i = 2; i < maxn;i++)
        if (e[i]==i)
            for (int j = i; j < maxn; j += i)
                e[j] = e[j] / i * (i - 1);
}
/*
    欧拉降幂
    a^b mod c  = a^(b mod phi(c)+phi(c)) mod c
    note:b>phi(c)时成立 b<=phi时由于数较小可直接快速幂
    例题洛谷p5091
 */
ll quickpow(ll x,ll n,ll mod){
    ll res = 1;
    while(n){
        if (n&1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}