#include <iostream>
using namespace std;
using ll = long long;
ll n, k;

ll solve()
{
    ll interval = (n - 1) * 2;
    if (k <= interval)
    {
        if (k <= n)
            return k;
        else
            return k - n;
    }
    else
    {
        k %= interval;
        if (!k)
            k = interval;
        if (k <= n - 1)
        {
            if (k == 1)
                return n - 1;
            else
                return k - 1;
        }
        else
        {
            if (k == n)
                return n;
            else
                return k - n;
        }
    }
}
int main(int argc, char const *argv[])
{
    int tot = 1;
    while (cin >> n >> k)
    {
        cout << "Case #" << tot++ << ": " << solve() << "\n";
    }
    return 0;
}
