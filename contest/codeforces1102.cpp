#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int x,y,n;
int a[maxn], cnt;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x >> y;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        if (a[i]<=x)
            ++cnt;
    }
    if (x>y)
        cout << n;
    else
        cout << ceil(cnt*1.0/2);
    return 0;
}
