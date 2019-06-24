/*
    每次选择结束时间最短的项目
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n;
struct node
{
    int s,e,l;
    node(int a,int b){
        s = a, e = b;
    }
    node(){}
    bool operator<(const node&a)const{
        return e < a.e;
    }
}t[maxn];
inline int read(){
    register int x = 0, f = 1;
    char ch = getchar();
    while(!isdigit(ch)){
        if (ch=='-')
            f=-1;
        ch = getchar();
    }
    while(isdigit(ch)){
        x = (x << 3) + (x << 1) + ch - 48;
        ch = getchar();
    }
    return x * f;
}
int main(){
    int n = read();
    int maxx = 0;
    for (int i = 0; i < n; i++)
    {
        int x = read(), y = read();
        t[i] = node(x, y);
        maxx = max(maxx, y);
    }
    sort(t, t + n);
    int ans = 0, nowt = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i].s>=nowt){
            ++ans;
            nowt = t[i].e;
        }
    }
    printf("%d", ans);
}
