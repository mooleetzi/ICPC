#include<bits/stdc++.h>
using namespace std;
const int maxn = 1100;
using ll = long long;
int k, n;
ll p[12];
void init(){
    p[0] = 1;
    for (int i = 1; i <= 11;i++)
        p[i] = p[i - 1] * k;
}
ll getAns(int num){
    int t=0;
    int now=0;
    for (int i = 1; i <= num; i <<= 1)
    {
        ++t;
        now = i;
    }
    ll ans = p[t-1];
    // cout << num << " " << now << "\n";
    if (num > now)
        ans += getAns(num - now);
    return ans;
}
int main(int argc, char const *argv[])
{
    cin >> k >> n;
    init();
    ll ans = getAns(n);
    cout << ans;
    return 0;
}
