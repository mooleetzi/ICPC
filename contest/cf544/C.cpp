#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int n, m;
priority_queue<int,vector<int>,greater<int> > q;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while(!q.empty()&&a[i]>q.top()+5)
            q.pop();
        q.push(a[i]);
        ans = max(ans, (int)q.size());
    }
    cout << ans;
    return 0;
}
