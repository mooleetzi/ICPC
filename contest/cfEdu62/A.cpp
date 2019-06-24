#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int a[maxn];
int n;
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    int ans = 0;
    int now = 1;
    while(now<=n){
        int maxx = a[now];
        for (int i = now; i <= maxx;i++){
            maxx = max(a[i], maxx);
            now = maxx + 1;
        }
        ++ans;
    }
    cout << ans;
    return 0;
}
