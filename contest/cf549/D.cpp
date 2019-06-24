#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
const int maxn = 1e5 + 10;
using ll = long long;
ll p[maxn];
int n, k,a,b;
unordered_set<ll> s;
int main(int argc, char const *argv[])
{
    cin >> n >> k>>a>>b;
    p[1] = 1;
    s.insert(1);
    for (int i = 2; i <= n; i++)
    {
        p[i] = (i - 1) * k + 1;
        s.insert(p[i]);
    }
    int st = 1 + a;
    int l=-1;
    for (int i = 0; i <= n * k / 2&&!(~l); i++)
    {
        for (int j = 1; j <= n;j++)
            if (abs(p[j]-st+i)==b){
                l = i;
                break;
            }
    }
    // cout << ;
    return 0;
}
