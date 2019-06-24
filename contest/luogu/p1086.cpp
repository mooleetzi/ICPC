#include<bits/stdc++.h>
using namespace std;
const int maxn = 30;
int a[maxn][maxn];
int n, m, k;
struct node
{
    int x, y, t;
    node(){}
    node(int a,int b,int c){
        x = a;
        y = b;
        t = c;
    }
    bool operator<(const node&a)const{
        return t < a.t;
    }
    /* data */
};

priority_queue<node> que;
inline int read()
{
    int ans = 0, f = 1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if (ch=='-'){
            f = -1;
            ch = getchar();
        }
    }
    while(ch>='0'&&ch<='9'){
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * f;
}
int main(int argc, char const *argv[])
{
    // n = read(), m = read(), k = read();
    // cout << n << " " << m << " " << k << "\n";
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=m;j++){
            // a[i][j] = read();
            cin >> a[i][j];
            que.push(node(i, j, a[i][j]));
        }
    }
    int ans = 0;
    int x = 0, y = 0;
    while (k)
    {
        if(que.empty())
            break;
        node now = que.top();
        que.pop();
        if (!now.t)
            break;
        if (x == 0 && y == 0)
        { //初始状态
            x = now.x;
            y = now.y;
            if (2*x>=k)//初始特判
                break;
            k -= x+1;//采摘也需要花费时间
            ans += now.t;
        }
        else
        {
            int tx = now.x;
            int ty = now.y;
            int t1 = abs(x - tx) + abs(ty - y);
            int t2 = tx;
            // cout << x << " " << y << " " << tx << " " << ty << "\n";
            // cout << t1 << " " << t2 << " " << k << " "<<ans<<"\n";
            if (t1 + t2 +1> k)
                break;
            k -= t1+1;
            ans += now.t;
            x = tx;
            y = ty;
        }
    }
    // printf("%d", ans);
    cout << ans;
    return 0;
}
