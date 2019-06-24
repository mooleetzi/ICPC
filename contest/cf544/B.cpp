#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
multiset<int> s;
int a[maxn], vis[maxn];
int n, k;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        a[i] %= k;
        s.insert(a[i]);
    }
    int ans = 0;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        auto f = s.equal_range(a[i]).first;
        auto e = s.equal_range(a[i]).second;
        if (f!=e)
            s.erase(f);
        else
            continue;
        if (a[i]){
            f = s.equal_range(k - a[i]).first;
            e = s.equal_range(k - a[i]).second;
            if (f!=e){
                s.erase(f);
                ans += 2;
            }
        }
        else
        {
            f = s.equal_range(0).first;
            e = s.equal_range(0).second;
            if (f!=e){
                s.erase(f);
                ans += 2;
            }
        }
    }
    cout << ans;
    return 0;
}
