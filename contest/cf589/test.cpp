#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7;

vector<int> Pri;

void Init(LL val)
{
    for (LL i = 2; i * i <= val; i++)
    {
        if (val % i == 0)
            Pri.push_back(i);
        while (val % i == 0)
            val /= i;
    }
    if (val != 1)
        Pri.push_back(val);
}

LL Cal(LL val, int p)
{
    //素数p在val的阶乘下的次方贡献
    LL cnt = 0;
    while (val)
    {
        cnt += val / p;
        val /= p;
    }
    return cnt;
}

LL QucikMi(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main()
{
    freopen("in.txt", "r", stdin);
    LL x, n;
    cin >> x >> n;
    Init(x);
    LL res = 1;
    for (int i = 0; i < Pri.size(); i++)
    {
        cout << Pri[i] << "\n";
        LL cnt = Cal(n, Pri[i]);
        res = (res * (QucikMi(Pri[i], cnt))) % MOD;
    }
    cout << res % MOD << endl;

    return 0;
}