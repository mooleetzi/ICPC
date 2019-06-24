#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int a[maxn];
int ans, maxx;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        ++a[x];
        if (a[x]>maxx){
            ans = x;
            maxx = a[x];
        }
    }
    cout << ans;
    return 0;
}
