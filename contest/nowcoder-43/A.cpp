#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int a[maxn], b[maxn];
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i] >> b[i];
    }
    string ans = "N0";
    for (int i = 0; i < n; i++)
    {
        int tmp = a[i] + b[i];
        for (int j = i + 1; j < n; j++)
        {
            if (a[j]+b[j]==a[i]&&tmp==a[j]){
                ans = "YE5";
                cout << ans << "\n";
                return 0;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}