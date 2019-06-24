#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m;
int a[maxn];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    char s[n + 10];
    cin >> (s + 1);
    int ans = 0;
    for (int i = 1; i <= n;i++)
        if (s[i]=='-'){
            --ans;
            if (ans<0)
                ans = 0;
        }
        else
            ++ans;
    cout << ans;
    return 0;
}
