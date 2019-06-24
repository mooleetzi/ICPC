#include <bits/stdc++.h>
#define gcd __gcd
using ll = long long;
using namespace std;
using pa = pair<int, int>;
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
int a[1000][1000], b[1000][1000];
int judge(int x,int y){
    vector<int> l, r;
    l.clear(), r.clear();
    for (int i = x, j = y; i <n&&j>-1;i++,j--){
        l.emplace_back(a[i][j]);
        r.emplace_back(b[i][j]);
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    return l == r;
}
int main(int argc, char const *argv[])
{
    n = read(), m = read();
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++)
            a[i][j] = read();
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++)
            b[i][j] = read();
    for (int i = 0; i < m;i++)
        if (!judge(0,i)){
            puts("NO");
            return 0;
        }
    for (int i = 0; i < n;i++)
        if (!judge(i,m-1)){
            puts("NO");
            return 0;
        }
    puts("YES");
    return 0;
}
