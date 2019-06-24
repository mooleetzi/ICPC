#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;
int vis[maxn];
int n;
double ans = 1e9,t1;
struct node
{
    double x, y;
    node(){}
    node(double x,double y){
        this->x = x;
        this->y = y;
    }
}t[maxn];
double getDis(node a,node b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void dfs(int cnt,int step,double s){
    if (step==n+1){
        ans = min(ans, s);
        return;
    }
    if (s>ans)
        return;
    vis[cnt] = 1;
    for (int i = 1; i <= n; i++)
        if (i!=cnt&&!vis[i])
            dfs(i, step + 1, s + getDis(t[i], t[cnt]));
    vis[cnt] = 0;
}
int main(int argc, char const *argv[])
{
    cin >> n;
    t[0].x = t[0].y = 0;
    for (int i = 1; i <= n; i++)
        cin >> t[i].x >> t[i].y;
    t1 = clock();
    dfs(0, 1, 0);
    printf("%.2f", ans);
    return 0;
}
