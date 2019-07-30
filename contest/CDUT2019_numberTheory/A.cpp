#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
const int maxn = 1e6 + 1e5;
int n, m, k;
int p[maxn];
void init()
{
    for (int i = 2; i < maxn; ++i)
    {
        if (!p[i])
        {
            for (int j = i + i; j < maxn; j += i)
                p[j] = 1;
        }
    }
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    int c = 1;
    while (t--)
    {
        ll ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            for (int j = x + 1; j < maxn; j++)
                if (!p[j])
                {
                    ans += j;
                    break;
                }
        }
        cout << "Case " << c << ": " << ans << " Xukha\n";
        ++c;
    }
    return 0;
}
