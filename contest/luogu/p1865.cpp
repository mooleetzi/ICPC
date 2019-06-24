#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int c[maxn];
int f[maxn], prime[maxn];
int n, m;
inline int lowbit(int x)
{
    return x & (-x);
}
void add(int x){
    while(x<=m){
        c[x] += 1;
        x += lowbit(x);
    }
}
int query(int x){
    int ans = 0;
    while(x){
        ans+=c[x];
        x -= lowbit(x);
    }
    return ans;
}
void get_prime(){
    int tot = 0;
    for (int i = 2; i <=m;i++)
        f[i] = 1;
    for (int i = 2; i <=m;i++){
        if (f[i]){
            prime[tot++] = i;
            add(i);
        }
        for (int j = 0; j < tot && prime[j] * i <=m;j++){
            f[prime[j] * i] = 0;
            if (i%prime[j]==0)
                break;
        }
    }
}
int main(){
    cin >> n >> m;
    get_prime();
    while(n--){
        int l, r;
        cin >> l >> r;
        if (l<1||l>m||r<1||r>m)
            cout << "Crossing the line\n";
        else
        {
            cout << query(r) - query(l - 1) << "\n";
        }
    }

    return 0;
}