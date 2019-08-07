/*
    打表，适合i<=1e4的情况
 */
const int M = 10007;
const int MAXN = 1000;
int C[MAXN + 1][MAXN + 1];
void Initial()
{
    int i, j;
    for (i = 0; i <= MAXN; ++i)
    {
        C[0][i] = 0;
        C[i][0] = 1;
    }
    for (i = 1; i <= MAXN; ++i)
    {
        for (j = 1; j <= MAXN; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
    }
}
int Combination(int n, int m)
{
    return C[n][m];
}

const int M = 10007;
const int MAXN = 1000;
int C[MAXN + 1][MAXN + 1];
void Initial()
{
    int i, j;
    for (i = 0; i <= MAXN; ++i)
    {
        C[0][i] = 0;
        C[i][0] = 1;
    }
    for (i = 1; i <= MAXN; ++i)
    {
        for (j = 1; j <= MAXN; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
    }
}
int Combination(int n, int m)
{
    return C[n][m];
}

/*
    乘法逆元求组合数
 */
ll fac[maxn];

ll inv[maxn];

void init()
{
    ll p = 1;
    inv[0] = 1;
    inv[1] = 1;
    fac[0] = fac[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        p = (p * i) % mod;
        fac[i] = p;
    }
    for (int i = 2; i < maxn; i++)
        inv[i] = inv[mod % i] * (mod - mod / i) % mod; //O(n)求逆元

    for (int i = 2; i < maxn; i++)
        inv[i] = inv[i - 1] * inv[i] % mod; //扩展到i!的逆元
}
ll C(int n, int m)
{
    if (m > n)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}