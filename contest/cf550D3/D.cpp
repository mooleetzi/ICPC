#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
using ll = long long;
ll a[maxn],b[maxn];
int n;
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <=n;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    int tot = 1,tmp=1,num=b[1];
    for (int i = 2; i <= n;i++){
        if (b[i]==b[i-1]){
            ++tmp;
            if (tmp>tot){
                num = b[i];
                tot = tmp;
            }
        }
        else{
            tmp = 1;
        }
    }
    int ans = n - tot;
    if (!ans){
        cout << 0;
        return 0;
    }
    cout << ans << "\n";
    int pos;
    for (int i = 1; i <= n; i++)
        if (a[i]==num){
            pos = i;
            break;
        }
    for (int i = pos - 1; i >= 1;i--){
        if (a[i]<a[pos]){
            cout << 1 << " " << i << " " << i + 1 << "\n";
        }
        else if (a[i]>a[pos]){
            cout << 2 << " " << i << " " << i + 1 << "\n";
        }
    }
    for (int i = pos + 1; i <= n;i++){
        if (a[i] < a[pos])
        {
            cout << 1 << " " << i << " " << i-1 << "\n";
        }
        else if (a[i] > a[pos])
        {
            cout << 2 << " " << i << " " << i-1 << "\n";
        }
    }
}
