#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e4 + 10;
int n;
struct node
{
    int a, b,d;
    bool operator<(const node&x){
        if (d!=x.d)
            return d < x.d;
        if (d<=0)
            return a < x.a;
        return b > x.b;
        // return !(min(a, x.b) >=min(b, x.a)); //错误的比较
    }
}T[maxn];
ll ans[maxn];
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n;i++){
            cin >> T[i].a >> T[i].b;
            if (T[i].a>T[i].b)
                T[i].d = 1;
            else if (T[i].a<T[i].b)
                T[i].d = -1;
            else
            {
                T[i].d = 0;
            }
        }
        sort(T + 1, T + 1 + n);
        ll pre = 0;
        for (int i = 1; i <= n; i++)
        {
            pre += T[i].a;
            ans[i] = max(pre, ans[i-1]) + T[i].b;
        }
        cout << ans[n]<<"\n";
    }
    return 0;
}
