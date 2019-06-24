#include<bits/stdc++.h>
using namespace std;
const int maxn = 25;
int a[maxn], b[maxn];
int n, m;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1;i<=n;i++){
            int x;
            cin >> x;
            ++a[x];
        }
        for (int i = 1; i <= n;i++){
            int x;
            cin >> x;
            ++b[x];
        }
        for (int i = 1; i <= 20;i++)
            if ((a[i]&&b[i]))
    }

    return 0;
}
