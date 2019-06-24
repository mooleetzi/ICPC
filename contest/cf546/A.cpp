#include <bits/stdc++.h>
#define gcd __gcd
using ll = long long;
using namespace std;
using pa = pair<int, int>;
const int maxn = 4e5 + 10;
vector<pa> v;
inline int read()
{
    register int f = 1, ans = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ans = (ans << 1) + (ans << 3) + ch - 48;
        ch = getchar();
    }
    return ans * f;
}
int n, m;
int main(int argc, char const *argv[])
{
    n = read();
    for (int i = 0; i < n;i++){
        int s = read(), t = read();
        v.emplace_back(pa(s,t));
    }
    int k = read();
    int ans = 0;
    for (int i = 0; i < n;i++)
        if (v[i].first>=k||(v[i].first<=k&&v[i].second>=k)){
            ++ans;
        }
    cout << ans;
    return 0;
}
