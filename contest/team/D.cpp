#include<iostream>
#include<algorithm>
using namespace std;
#define eps 0.000001
const int maxn = 2e5 + 10;
int n;
int a[maxn];
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    double ans = 1e9;
    int flag = 1;
    for (int i = 1; i <= n; i++)
        if (i>=a[i]){
            if (ans>(double)a[i]*1.0/i)
                ans = a[i] * 1.0 / i;
        }
        else
        {
            flag = 0;
        }
    if (!flag)
        cout << "impossible";
    else
    {
        cout << ans;
    }

    return 0;
}
