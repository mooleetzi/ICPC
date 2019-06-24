#include<bits/stdc++.h>
using namespace std;
int a[11];
int n,tot;
int main(int argc, char const *argv[])
{
    cin >> n;
    while(n){
        a[tot++] = n % 10;
        n /= 10;
    }
    int ans = 1;
    for (int i = 0; i < tot;i++)
        ans *= a[i];
    for (int i = 0; i < tot - 1; i++)
    {
        if (a[i] < 9)
        {
            a[i] = 9;
            --a[i + 1];
        }
        if (!a[tot-1])
            a[tot - 1] = 1;
        int tmp = 1;
        for (int j = 0; j < tot; j++)
            tmp *= a[j];
        ans = max(ans, tmp);
    }
    cout << ans;
    return 0;
}
