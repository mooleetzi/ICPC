/*
    思维题
    n^2枚举方程解
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;

inline int read()
{
    register int tmp = 0, f = 1;
    char ch = getchar();
    if (ch == '-')
    {
        ch = getchar();
        f = -1;
    }
    while (ch >= '0' && ch <= '9')
    {
        tmp = tmp * 10 + ch - '0';
        ch = getchar();
    }
    return tmp * f;
}
int n, m;
int a[maxn], c[maxn];
vector<int> aa, ac, cc, bb;
int main()
{
    n = read();
    for (int i = 1; i <= n;i++)
        c[i] = getchar() - '0';
    getchar();
    for (int i = 1; i <= n;i++)
        a[i] = getchar() - '0';
    getchar();
    for (int i = 1; i <= n; i++)
        if (c[i]&&a[i])
            ac.emplace_back(i);
        else if (c[i])
        {
            cc.emplace_back(i);
        }
        else if (a[i])
        {
            aa.emplace_back(i);
        }
        else
        {
            bb.emplace_back(i);
        }
    int an = aa.size(), cn = cc.size(), acn = ac.size(), nn = bb.size();
    for (int xa = 0; xa <= an;xa++)
        for (int xc = 0; xc <= cn;xc++){
            if ((acn + an - xa - xc)%2==0){
                int xac = (acn + an - xa - xc) >> 1;
            int xb = n / 2 - xa - xc - xac;
            if (xac>=0&&xac<=acn&&xb>=0&&xb<=nn){
                for (int i = 0; i < xa;i++)
                    printf("%d ", aa[i]);
                for (int i = 0; i < xc;i++)
                    printf("%d ", cc[i]);
                for (int i = 0; i < xb;i++)
                    printf("%d ", bb[i]);
                for (int i = 0; i < xac;i++)
                    printf("%d ", ac[i]);
                return 0;
            }
            }
        }
    printf("-1");
    return 0;
}