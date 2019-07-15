#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int s, n;
int main(int argc, char const *argv[])
{
    int t;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        int ans = maxn;
        cin >> n >> s;
        for (int i = 0; i < n;i++)
            cin >> a[i];
        for (int l = 0, r = -1, t = 0; l < n;l++){
            while(r<n-1&&t<s)
                t += a[++r];
            if (t<s)
                break;
            ans = min(ans, r - l+1);
            t -= a[l];
        }
        if (ans==maxn)
            ans = 0;
        cout << ans << "\n";
    }
    return 0;
}
