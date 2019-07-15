#include<iostream>
#include<algorithm>
#include<vector>
#include <set>
using namespace std;
const int maxn = 2e5 + 10;
int n;
multiset<int> s;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    int ans = 0;
    for (int i = 1; i <= n;i++){
        auto now = s.lower_bound(i);
        if (now!=s.end()){
            ++ans;
            s.erase(now);
        }
    }
    cout << ans;
    return 0;
}
