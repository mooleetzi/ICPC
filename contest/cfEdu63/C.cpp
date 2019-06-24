#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 3e5 + 10;
ll n, m;
ll first,r;
ll b[maxn];
ll a[maxn];
map<ll, int> ma;
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1;i<=n;i++){
        cin >> a[i];
        if (i>1)
            b[i] = a[i] - a[i - 1];
        if (i==2)
            r = b[i];
        if (i>2)
            r = __gcd(r, b[i]);
    }
    for (int i = 1; i <= m;i++){
        ll x;
        cin>>x;
        if (!ma[x])
            ma[x] = i;
    }
    if (ma[1]){
        puts("YES");
        printf("%lld %d\n", a[1], ma[1]);
        return 0;
    }
    if (n==2){
        for (auto x:ma){
            if (x.second&&b[2]%x.first==0){
                puts("YES");
                printf("%lld %d\n", a[1], x.second);
                return 0;
            }
        }
    }
    for (auto x:ma){
        if (x.second&&r%x.first==0){
            puts("YES");
            printf("%lld %d\n", a[1], x.second);
            return 0;
        }
    }
        puts("NO");
    return 0;
}
