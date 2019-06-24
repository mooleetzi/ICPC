#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
using pa = pair<int, int>;
pa a[maxn];
int n, k;
bool cmp(pa a,pa b){
    return a.first > b.first;
}
priority_queue<int, vector<int>, greater<int>> q1,q2;
int main(int argc, char const *argv[])
{
    cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n,cmp);
    for (int i = 0; i < n; i++)
    {
        q1.push(a[i].second);
        if (q1.size() > k)
            q1.pop();
        if (q1.size()==k)
            ans = max(ans, q1.top() + a[i].first);
    }
    cout << ans;
    return 0;
}
