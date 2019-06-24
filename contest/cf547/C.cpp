#include <bits/stdc++.h>
#define gcd __gcd
using ll = long long;
using namespace std;
const int maxn = 4e5 + 10;

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
int a[maxn];
int b[maxn], p[maxn];
ll sum, pre;
int main(int argc, char const *argv[])
{
    n = read();
    int f = 1;
    vector<int> ans;
    ans.clear();
    ans.emplace_back(0);
    for (int i = 1; i < n; i++)
    {
        p[i] = read();
        ans.emplace_back(ans[i - 1] + p[i]);
    }
    int minx = *min_element(ans.begin(), ans.end());
    int maxx = *max_element(ans.begin(), ans.end());
    vector<int> tmp = ans;
    sort(tmp.begin(), tmp.end());
    int sz = unique(tmp.begin(), tmp.end()) - tmp.begin();
    if (maxx - minx == n - 1&&sz==n)
    {
        for (auto x:ans)
            cout << x - minx + 1 << " ";
    }
    else
    {
        cout << "-1";
    }

    return 0;
}
