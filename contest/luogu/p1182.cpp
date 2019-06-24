#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n,m;
int a[maxn];
int judge(int x){
    int ans1, ans2;
    ans1 = ans2 = -maxn;
    int tmp = 0;
    int l = 0, r = 0;
    for (int i = 0; i < n;i++){
        tmp += a[i];
        if (tmp>x){
            ++l;
            tmp -= a[i];
            ans1 = max(ans1, tmp);
            tmp = a[i];
        }
    }
    tmp = 0;
    for (int i = n - 1; i > -1; i--)
    {
        tmp+=a[i];
        if (tmp > x)
        {
            ++r;
            tmp -= a[i];
            ans2 = max(ans2, tmp);
            tmp = a[i];
        }
    }
    ++l, ++r;
    return ((l <= m && ans1 <= x) || (r <= m) && ans2 <= x);
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    int l = 0, r = 1e9;
    while(l<r){
        int mid = l+r >> 1;
        // cout << l << " " << r<<"\n";
        if (judge(mid))
            r = mid;
        else
        {
            l = mid+1;
        }
    }
    cout << l;
    return 0;
}