#include <bits/stdc++.h>
using namespace std;
using pa = pair<int, int>;
const int maxn = 3e5 + 10;
const int inf = 1e9 ;
int n, m;
int a[maxn];
int q[maxn];
multiset<pa> s;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i = 1; i <= n;i++)
        cin >> a[i], s.insert(pa(a[i], i));
    int ans = 1e9;
    while(!s.empty()){
        auto cur = s.begin();
        ans = min(ans, cur->first / (max(cur->second - 1, n - cur->second)));
        s.erase(cur);
    }
    cout << ans;
    return 0;
}