#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m;
int pre[maxn];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int ans;
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (pre[x])
            --mp[pre[x]];
        if (!mp[pre[x]])
            mp.erase(pre[x]);
        ++pre[x];
        ++mp[pre[x]];
        if (mp.size()>2)
            continue;
        else if (mp.size()==1){
            auto x = mp.begin();
            if (x->first==1||x->second==1)
                ans=i;
        }
        else{
            auto q = mp.begin();
            auto f = q++;
            auto e = q;
            if (f->first==1&&f->second==1)
                ans = i;
            if (f->first==e->first-1&&e->second==1)
                ans = i;
            if (e->first==1&&e->second==1)
                ans = i;
            if (e->first==f->first-1&&f->second==1)
                ans = i;
        }   
    }
    cout << ans;
    return 0;
}
