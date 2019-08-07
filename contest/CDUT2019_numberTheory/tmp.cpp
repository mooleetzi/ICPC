#pragma optimize(3)
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
const int maxn = 210;
const int mod = 100000007;
ll n, k, m, pre, r;
template <class T>
inline T read(T &ret)
{
    int f = 1;
    ret = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ret = (ret << 1) + (ret << 3) + ch - '0';
        ch = getchar();
    }
    ret *= f;
    return ret;
}
template <class T>
inline void write(T n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n >= 10)
    {
        write(n / 10);
    }
    putchar(n % 10 + '0');
}
inline ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
inline ll inv(ll a)
{
    return qpow(a, mod - 2);
}
inline ll BSGS(ll a, ll b)
{
    ll m = (ll)sqrt(mod + 0.5);
    unordered_map<ll, ll> x;
    x[1] = 0;
    ll ans = 1;
    for (int i = 1; i <= m; i++)
    {
        ans = ans * a % mod;
        if (!x.count(ans))
            x[ans] = i;
    }
    ll pm = inv(qpow(a, m));
    for (int i = 0; i < m; i++)
    {
        if (x.count(b))
            return i * m + x[b];
        b = b * pm % mod;
    }
    return -1;
}
unordered_map<int, vector<int>> mp;
unordered_set<int> s;
inline ll solve()
{
    ll cur = 1;
    for (auto x : mp)
    {
        vector<int> &now = x.second;
        sort(now.begin(), now.end());
        int sz = now.size();
        int c = 0, first = 1;
        if (now[0] != 1)
        {
            cur = cur * k % mod;

            cur = cur * qpow(k - 1, now[0] - 2) % mod;

            c = 1;
            int pp = now[0];
            while (c < sz)
            {
                for (; c < sz; c++)
                    if (now[c] != now[c - 1] + 1)
                        break;
                    else
                        pp = now[c];
                if (c != sz)
                {
                    cur = cur * k % mod;

                    int left = now[c] - pp - 2;
                    cur = cur * qpow(k - 1, left) % mod;
                }
            }
        }
        else
        {
            c = 1;
            int pp = now[0];
            while (c < sz)
            {
                for (; c < sz; c++)
                    if (now[c] != now[c - 1] + 1)
                        break;
                    else
                        pp = now[c];
                if (c != sz)
                {
                    cur = cur * k % mod;

                    int left = now[c] - pp - 2;
                    cur = cur * qpow(k - 1, left) % mod;
                }
            }
        }
        int left = now[sz - 1];
        if (left < r)
        {
            cur = cur * k % mod;

            cur = cur * qpow(k - 1, r - left - 2);
        }
        else
        {
            s.insert(x.first);
        }
    }
    int no = mp.empty();
    int msz = mp.size();
    if (msz < n && !mp.empty())
    {
        cur = cur * qpow(k, n - msz) % mod;

        cur = cur * qpow(k - 1, (r - 1) * (n - msz)) % mod;
    }
    if (cur == pre)
        return r;
    if (!no)
    {
        int sz = s.size();
        cur = cur * qpow(k, sz);

        cur = cur * qpow(k - 1, n - sz);
    }
    else
    {
        cur = cur * qpow(k, n);
    }
    if (cur == pre)
        return r + 1;
    k = qpow(k - 1, n);
    pre = pre * inv(cur) % mod;
    return r + 1 + BSGS(k, pre);
}
int main(int argc, char const *argv[])
{
    int t;
    read(t);
    int tot = 0;
    while (t--)
    {
        r = 0;
        s.clear();
        mp.clear();
        read(n), read(k), read(m), read(pre);
        for (int i = 0; i < m; i++)
        {
            ll x, y;
            read(x), read(y);
            r = max(x, r);
            mp[y].emplace_back(x);
        }
        printf("Case %d: %lld\n", ++tot, solve());
    }
    return 0;
}