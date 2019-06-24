#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
using ll = long long;
ll b[maxn];
ll first;
struct Node
{
    ll num, idx;
    Node(){}
    Node(ll n,ll i){
        num = n;
        idx = i;
    }
    bool operator<(const Node&x)const{
        return num < x.num;
    }
    /* data */
}p[maxn];
ll m, n;
set<ll> s;
map<ll, int> ma;
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    ll pre = 0;
    ll r;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        b[i] = x - pre;
        pre = x;
        if (i!=1)
        {
            if (i==2)
                r = b[i];
            else
            {
                r = __gcd(b[i], r);
            }
        }
    }
    for (int i = 1; i <= m;i++){
        ll x;
        cin >> x;
        s.insert(x);
        if (!ma[x])
            ma[x] = i;
    }
    if (!ma[r])
        puts("NO");
    else
    {
        puts("YES");
        printf("%d %d", b[1],ma[r]);
    }

    return 0;
}

