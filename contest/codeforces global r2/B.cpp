#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
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
using pa = pair<int, int>;
int n, h;
int judge(int x)
{
    int q = 0;
    int tmp[x + 2];
    for (int i = 1; i <= x;i++)
        tmp[i] = a[i];
    int b[x + 2];
    memset(b, 0, sizeof b);
    tmp[x + 1] = 0;
    tmp[0] = 0;
    sort(tmp+1, tmp+1 + x);
    int f1 = 1, f2 = 1;
    for (int i = 1; i <= x; i += 2){
        int t = max(tmp[i], tmp[i + 1]);
        q += t;
        if (q>h){
            f1 = 0;
            break;
        }
    }
    q = 0;
    for (int i = x; i >= 1; i -= 2)
    {
        int t = max(tmp[i], tmp[i - 1]);
        q += t;
        if (q>h){
            f2 = 0;
            break;
        }
    }
    return f1 || f2;
}
int main()
{
    n = read(), h = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    int l = 1, r = n+1;
    while(l<r){
        int mid = l + r >> 1;
        if (judge(mid))
            l = mid + 1;
        else
            r = mid;
    }
    printf("%d", l-1);
}