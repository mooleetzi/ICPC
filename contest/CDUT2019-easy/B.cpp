#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 27;
int premaxn;
ll pow(ll x, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1)
            ans = ans * (x % mod) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ans;
}
struct wd
{
    char c;
    int t[maxn];
    bool operator<(const wd &a) const
    {
        for (int i = premaxn - 1; i >= 0; i--)
            if (t[i] != a.t[i])
                return t[i] < a.t[i];
        return 0;
    }
} w[26];
int b[26], p[26];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tot = 1, n;
    while (cin >> n)
    {
        memset(b, 0, sizeof b);
        memset(p, -1, sizeof p);
        vector<string> ss;
        for (int i = 0; i < 26; i++)
        {
            w[i].c = 'a' + i;
            for (int j = 0; j < premaxn; j++)
                w[i].t[j] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            b[s[0] - 'a'] = 1;
            ss.emplace_back(s);
            premaxn = max(premaxn, (int)s.size());
            reverse(s.begin(), s.end());
            for (int j = 0; j < s.size(); j++)
                ++w[s[j] - 'a'].t[j];
        }

        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j <= premaxn; ++j)
            {
                w[i].t[j + 1] += w[i].t[j] / 26;
                w[i].t[j] %= 26;
            }
        }
        sort(w, w + 26);
        for (int i = 0; i < 26; i++)
            if (!b[w[i].c - 'a'])
            {
                p[w[i].c - 'a'] = 0;
                break;
            }
        int val = 1;
        for (int i = 0; i < 26; i++)
            if (p[w[i].c - 'a'] == -1)
                p[w[i].c - 'a'] = val++;
        // for (int i = 0; i < 26; i++)
        //     cout << w[i].c << ": " << p[w[i].c - 'a'] << " ";
        // cout << "\n";
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            string now = ss[i];
            ll cur = 0;
            for (int j = 0; j < now.size(); j++)
            {
                cur = cur * 26 + p[now[j] - 'a'];
                while (cur >= mod)
                    cur -= mod;
            }
            ans += cur;
            while (ans >= mod)
                ans -= mod;
        }
        cout << "Case #" << tot++ << ": " << ans << "\n";
    }
    return 0;
}
