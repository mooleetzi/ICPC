#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn], b[maxn],c[maxn];
int tot,to,de;
const int inf = 0x3f3f3f3f;
int isOk()
{
    set<int> s;
    int maxx = -maxn, u = -1;
    for (int i = 1; i < tot;i++){
        if (c[i]>maxx){
            maxx = c[i];
            u = a[i];
            s.clear();
            s.insert(a[i]);
            if (u > to)
                return 0;
        }
        else if (c[i]==maxx)
        {
            s.insert(a[i]);
        }
        
    }
    return s.count(to);
}
int main()
{
    scanf("%d",&to);
    int prex=-1, prey=-1;
    int nowx, nowy;
    int maxx = -inf;
    while (scanf("%d%d", &nowx, &nowy) && (nowx + nowy != -2))
    {
        if (prex==-1&&prey==-1){
            a[tot] = nowx;
            b[tot++] = nowy;
            prex = nowx;
            prey = nowy;
        }
        else
        {
            if (prex+1!=nowx){
                int d = (nowy - prey)/(nowx-prex);
                for (int i = prex + 1; i <=nowx;i++){
                    int p = b[tot-1];
                    // maxx = max(maxx, (i-a[0])*p);
                    a[tot] = i;
                    b[tot++] = p + d;
                }
            }
            else
            {
                a[tot] = nowx;
                b[tot++] = nowy;
                // maxx = max(maxx, (a[tot-1] - a[0]) * b[tot-1]);
            }
            prex = nowx;
            prey = nowy;
        }
    }
    scanf("%d", &de);
    while(b[tot-1]-de>0){
        a[tot] = a[tot - 1] + 1;
        b[tot] = b[tot - 1] - de;
        tot++;
    }
    int ans = 0, f = -1;
    while(1)
    {
        if (ans>maxn){
            break;
        }
        for (int i = 1; i < tot;i++)
            c[i] = (a[i]-a[0]+ans) * b[i];
        if (isOk())
        {
            printf("%d", ans);
            return 0;
        }
        for (int i = 1; i < tot;i++)
            c[i] = (a[i] - a[0] - ans) * b[i];
        if (isOk()){
            printf("%d", -ans);
            return 0;
        }
        ans++;
    }
    printf("NO SOLUTION");
    return 0;
}