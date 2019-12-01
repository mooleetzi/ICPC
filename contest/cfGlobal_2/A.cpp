#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int a[maxn];
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
int n;
int b[maxn], c[maxn];
int t1, t2;
int pre , last;
set<int> s1, s2;
int main()
{
    n = read();
    for (int i = 1; i <= n;i++)
        a[i] = read();
    pre = 1;
    last = n;
    int ans = 0;
    for (int i = n; i > 1;i--)
        if (a[i]!=a[1]){
            ans = i - 1;
            break;
        }
    for (int i = 1; i < n;i++)
        if (a[i]!=a[n]){
            ans = max(ans, n - i);
            break;
        }
    printf("%d", ans);
    return 0;
}