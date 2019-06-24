#include <bits/stdc++.h>
#define gcd __gcd
using namespace std;
const int maxn = 2e5 + 10;
using ll = long long;

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
using pa = pair<int, int>;
map<int, int> vis;
int bfs(int s, int t)
{
    if (s==t)
        return 0;
    queue<pa> q;
    q.push(pa(s,0));
    vis[s] = 1;
    while (!q.empty())
    {
        pa now = q.front();
        q.pop();
        if (now.first > t)
            continue;
        if (!vis[2*now.first]){
            q.push(pa(2 * now.first,now.second+1));
            vis[2 * now.first] = 1;
            if (2*now.first==t)
                return now.second + 1;
        }
        if (!vis[3*now.first]){
            if (3*now.first==t)
                return now.second + 1;
            vis[3 * now.first] = 1;
            q.push(pa(3 * now.first, now.second + 1));
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    n = read(), m = read();
    int k = bfs(n, m);
    cout << k;
    return 0;
}
