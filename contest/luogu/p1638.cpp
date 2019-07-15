#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int maxn = 2010;
const int inf = 1e6 + 10;
set<int> s;
int b[maxn];
int n, t;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    vector<int> a(n+1);
    for (int i = 1; i <=n;i++)
        cin >> a[i];
    int ans = inf;
    int p1, p2;
    for (int l = 1,r = 0; l <= n;l++){
        while(s.size()<t&&r<n){
            ++b[a[++r]];
            s.insert(a[r]);
        }
        if (s.size()==t){
            if (r-l+1<ans){
                ans = r - l + 1;
                p1 = l;
                p2 = r;
            }
        }
        --b[a[l]];
        if (!b[a[l]])
            s.erase(a[l]);
    }
    cout << p1 << " " << p2 << "\n";
    return 0;
}
