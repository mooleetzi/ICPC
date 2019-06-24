#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int a[maxn];
ll sum, ave, ans,n;
multiset<int> s;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        s.clear();
        cin >> n;
        ans = sum = ave = 0;
        for (int i = 0; i < n;i++){
            cin >> a[i];
            sum += a[i];
            s.insert(a[i]);
        }
        ave = sum / n;
        while(s.upper_bound(ave)!=s.end()){
            multiset<int>::iterator now = s.begin();
            if (*now>ave)
                ans += *now - ave;
            else if (*now<ave){
                int w = *now;
                while(w!=ave){
                    multiset<int>::iterator cur = s.upper_bound(ave);
                    int q = *cur;
                    s.erase(cur);
                    if (q-ave>=ave-w){
                        ans += ave-w;
                        s.insert(q+w-ave);
                        w = ave;
                    }
                    else{
                        ans += q - ave;
                        w += q - ave;
                    }
                }
            }
            s.erase(now);
        }
        cout << ans << "\n";
    }
    return 0;
}
