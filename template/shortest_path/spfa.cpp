#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
const int inf = 2147483647;
int n, m;
struct edge
{
    struct node
    {
        int to, next, w;
    };
    node data[maxn];
    int head[maxn];
    int tot;
    edge(){
        memset(head, -1, sizeof head);
        tot = 0;
    }
    void add(int x,int y,int w){
        data[tot].to = y;
        data[tot].w=w;
        data[tot].next = head[x];
        head[x] = tot++;
    }
    void print(){
        for (int i = 1; i <= n;i++){
            cout << i;
            for (int j = head[i]; ~j; j = data[j].next)
                cout << " ^" << data[j].to << ":" << data[j].w;
            cout << "\n";
        }
    }
}e;
int dis[maxn], inq[maxn], cnt[maxn];
void spfa(int s)
{
    for (int i = 1; i <= n;i++)
        dis[i] = inf;
    dis[s] = 0;
    queue<int> que;
    while(!que.empty()){
        que.pop();
    }
    que.push(s);
    inq[s] = 1;
    cnt[s] = 1;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        inq[now] = 0;
        for (int i = e.head[now]; ~i;i=e.data[i].next){
            int to = e.data[i].to;
            if (dis[to]>dis[now]+e.data[i].w){
                if (!inq[to]){
                    inq[to] = 1;
                    ++cnt[to];
                    if (cnt[to]>n)
                        return;
                    que.push(to);
                }
                dis[to] = dis[now] + e.data[i].w;
            }
        }
    }
}
template<class T>
inline void read(T&ans){
    register T f = 1;
    ans = 0;
    char ch = getchar();
    while(!isdigit(ch)){
        if (ch=='-')
            f = -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        ans = (ans << 1) + (ans << 3) + ch - 48;
        ch = getchar();
    }
    ans *= f;
}
int main(){
    read(n);
    int m1, m2;
    read(m1);
    // read(m2);
    int s, t;
    read(s);
    // read(t);
    for (int i = 0; i < m1; i++)
    {
        int x, y, t;
        read(x), read(y), read(t);
        e.add(x, y, t);
        // e.add(y, x, t);
    }
    spfa(s);
    // for (int i = 0; i < m2;i++){
    //     int x, y, t;
    //     read(x), read(y), read(t);
    //     e.add(y, x, -t);
    // }
    // for (int i = 0; i < n;i++){
    //     e.add(i+1, i, 0);
    // }
    // e.print();
    // cout << spfa(s, t);
    for (int i = 1; i <= n;i++)
        cout << dis[i] << " ";
    return 0;
}
