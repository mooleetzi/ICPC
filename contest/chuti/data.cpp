#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn = 1e18 + 1;
const ll maxT = 1e3 + 1;
int main(int argc, char const *argv[])
{
    mt19937 mt_rand(time(nullptr));
    ofstream out("6.in");
    ll t = mt_rand() % maxT;

    out << t << "\n";
    while (t--)
    {
        ll n = mt_rand() % maxn, a = mt_rand() % maxn, b = mt_rand() % maxn, k = mt_rand() % 20 + 1;
        out << n << " " << a << " " << b << " " << k << "\n";
    }
    // int n = mt_rand() % 2001;
    // string r = "";
    // for (int i = 0; i < n; i++)
    // {
    //     int cur = mt_rand() % 2;
    //     r += (char)(cur + 48);
    // }
    // out << r << "\n";
    // int m = mt_rand() % 100001;
    // out << m << "\n";
    // int cnt = 0;
    // while (m--)
    // {
    //     int l = mt_rand() % (n + 1);
    //     int r = mt_rand() % (m + 1);
    //     if (l > r)
    //         swap(l, r);
    //     out << l << " " << r << "\n";
    // }
    return 0;
}
