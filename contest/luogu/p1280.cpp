#include<bits/stdc++.h>
using namespace std;
const int maxn = 11000;
int n, k;
int f[maxn], exist[maxn];
struct node
{
    int s,t;
    bool operator<(const node&x){
        return s > x.s;
    }
    /* data */
}op[maxn];

int main(int argc, char const *argv[])
{
    cin >> n >> k;
    for (int i = 0; i < k;i++){
        cin >> op[i].s >> op[i].t;
        exist[op[i].s] = 1;
    }
    sort(op, op + k);
    for (int i = n; i > 0; i--)
        if (!exist[i])
            f[i] = f[i + 1] + 1;
        else
        {
            for (int j = 0; j < k;j++)
                if (op[j].s==i){
                    f[i] = max(f[i + op[j].t],f[i]);
                }
        }
    cout << f[1];
    return 0;
}
