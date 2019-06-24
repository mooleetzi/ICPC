#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n,m;
int a[maxn];
struct node
{
    int l, r;
}p[maxn];

int b[maxn];
int num = 0;
bool cmp(node a,node b){
    return a.r - a.l > b.r - b.l;
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i]&&!b[a[i]]){
            b[a[i]] = 1;
            p[a[i]].l = i;
        }
        p[a[i]].r = i;
    }
    for (int i = 1; i <= m;i++)
        cout << p[i].l << " " << p[i].r << "\n";
    return 0;
}
