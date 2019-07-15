#include<iostream>
#include<cstring>
using namespace std;
using ll = long long;
const int maxn = 20000010;
ll a,mod;
char b[maxn];
ll euler(ll x){
    ll a = x, res = x;
    for (int i = 2; i * i <=a;i++)
        if (a%i==0){
            res = res / i * (i - 1);
            while(a%i==0)
                a /= i;
        }
    if (a>1)
        res = res / a * (a - 1);
    return res;
}
ll ksm(ll x,ll n){
    ll res = 1;
    while(n){
        if (n&1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> mod >> b;
    int len = strlen(b);
    ll phi = euler(mod);
    ll cur = 0;
    int flag = 0;
    for (int i = 0; i < len;i++){
        cur = (cur * 10 + b[i] - '0');
        if (cur>phi){
            flag = 1;
            cur %= phi;
        }
    }
    if (flag)
        cur += phi;
    cout << ksm(a, cur) << "\n";
    return 0;
}
