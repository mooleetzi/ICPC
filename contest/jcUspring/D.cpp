#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
using ull = long long;
const ull maxn = 1e5 + 10;
ull ans[maxn];
int tot = 0;
ull n;
ull getSum(ull x, int step)
{
    ull cur =(x-1) / step;
    return (1+1 + cur * step)*(cur+1)/2;
}
int main(int argc, char const *argv[])
{
    cin >> n;
    set<ull> ans;
    for (int i = 1; i <= sqrt(n) + 1; ++i)
    {
        int now = n / i;
        if (__gcd(n,(ull)now)==now){
            ans.insert(getSum(n, i));
            ans.insert(getSum(n, now));
        }
    }
    
    // ans[tot++] = getSum(n,1);
    for (auto x:ans)
        cout << x << " ";
    return 0;
}