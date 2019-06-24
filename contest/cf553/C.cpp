#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
ll f(ll x)
{
    ll e = 2, o = 1, op = 1,pre=0,ans=0;
    for (ll i = 1; i <= x; i <<= 1)
    {
        if (pre+i>=x)
            break;
        if (op&1){
            ll od = o + ((i - 1)*2);
            ll r = (((o + od)%mod * i%mod)%mod/2%mod)%mod;
            ans = (ans % mod + r % mod) % mod;
            o = od+2;
        }
        else
        {
            ll ed = e + ((i - 1) << 1);
            ll r = (((e + ed) % mod * i % mod) % mod / 2 % mod) % mod;
            ans = (ans % mod + r % mod) % mod;
            e = ed + 2;
        }
        pre += i;
        op ^= 1;
    }
    if (op&1){
        ll od = o + ((x - pre-1) << 1);
        if (!(od&1))
            --od;
        ll r = (((o + od) % mod * (x - pre) % mod) % mod / 2 % mod) % mod;
        ans = (ans % mod + r % mod) % mod;
    }
    else
    {
        ll ed = e + (x - pre - 1 << 1);
        if (ed&1)
            --ed;
        ll r = (((e + ed) % mod * (x-pre) % mod) % mod / 2 % mod) % mod;
        ans = (ans % mod + r % mod) % mod;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    ll l, r;
    cin >> l >> r;
    ll q1 = f(r);
    ll q2 = f(l - 1);
    if (q1>q2)
        cout << q1 - q2;
    else
    {
        cout << q1 - q2 + mod;
    }

    return 0;
}
