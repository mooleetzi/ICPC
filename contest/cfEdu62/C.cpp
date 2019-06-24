#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
using ll = long long;
int k, n;
struct node
{
    int t, b;
    node(){}
    node(int a,int c):t(a),b(c){}
    bool operator<(const node &x)const{
        if (b==x.b)
            return t > x.t;
        return b > x.b;
    }
}f[maxn];
priority_queue<ll,vector<ll>,greater<ll>> q;
int main(int argc, char const *argv[])
{
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        int t, b;
        cin >> t >> b;
        f[i] = node(t, b);
    }
    sort(f + 1, f + 1 + n);
    ll now = 0;
    ll ans = 0;
    // for (int i = 1; i <= n;i++){
    //     cout << f[i].t << " " << f[i].b << "\n";
    // }
    // q.push(1);
    // q.push(2);
    // cout << q.top()<<"\n";
    for (int i = 1; i <= n; i++)
    {
        q.push(f[i].t);
        now += f[i].t;
        if (q.size() > k)
        {
            now -= q.top();
            q.pop();
        }
        ans = max(ans, now * f[i].b);
        }
    cout << ans<<"\n";
    return 0;
}

