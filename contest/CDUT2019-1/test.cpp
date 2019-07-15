#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll maxn = 1e2 + 10;
ll a[maxn];
ll s[maxn];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    a[1] = a[2] = 1;
    s[1] = a[1];
    s[2] = s[1] + a[2];
    for (int i = 3; i <= maxn; i++)
    {
        a[i] = a[i - a[i - 1]] + a[i - 1 - a[i - 2]];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= maxn; i++)
    {
        cout << s[i] << " ";
        if (i % 10 == 0)
            cout << "\n";
    }
    return 0;
}
