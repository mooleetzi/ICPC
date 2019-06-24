#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n, t;
int a[maxn], pre[maxn];
int main(int argc, char const *argv[])
{
    cin >> n >> t;
    for (int i = 1; i <= n;i++){
        int s, len;
        cin >> s >> len;
        while (s < maxn)
        {
            pre[s] = i;
            s += len;
        }
    }
    for (int i = t; i < maxn;i++){
        if (pre[i]){
            cout << pre[i];
            break;
        }
    }
        return 0;
}
