const int BASE = 64;
struct L_B
{
    ll d[BASE], p[BASE];
    int cnt, flag;
    void init()
    {
        memset(d, 0, sizeof(d));
        memset(p, 0, sizeof(p));
        cnt = 0;
        flag = 0;
    } // 1e18以内的数都适用.
    inline bool insert(LL val)
    {
        for (int i = BASE - 1; i >= 0; i--)
        {
            if (val & (1ll << i))
            {
                if (!d[i])
                {
                    d[i] = val;
                    return true;
                }
                val ^= d[i];
            }
        }
        flag = 1; //可以异或出0
        return false;
        // 可判断val是否存在于线性基当中.
    }
    LL query_max()
    {
        ll res = 0;
        for (int i = BASE - 1; i >= 0; i--)
        {
            if ((res ^ d[i]) > res)
                res ^= d[i];
        }
        return res;
    }
    LL query_min()
    { // 应该预先判断能否是0的情况..QAQ
        if (flag)
            return 0;
        for (int i = 0; i <= BASE - 1; i++)
        {
            if (d[i])
                return d[i];
        }
    }
    void rebuild()
    { // 用于求第k小值.需要先进行独立预处理
        for (int i = BASE - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (d[i] & (1ll << j))
                    d[i] ^= d[j];
            }
        }
        for (int i = 0; i <= BASE - 1; i++)
        {
            if (d[i])
                p[cnt++] = d[i];
        }
    }
    ll kthquery(LL k)
    {             // 注意判断原序列异或出0的情况, 此时应该将k -- 在进行后面的操作.
        if (flag) //判0
            --k;
        if (!k)
            return 0;
        ll res = 0;
        if (k >= (1ll << cnt))
            return -1;
        for (int i = BASE - 1; i >= 0; i--)
        {
            if (k & (1LL << i))
                res ^= p[i];
        }
        return res;
    }
    void Merge(const L_B &b)
    { // 把b这个线性基插入到当前这个线性基中.
        for (int i = BASE - 1; i >= 0; i--)
            if (b.d[i])
                insert(b.d[i]);
    }
} lb;
/*
    区间线性基 HDU6579
    注意init()
*/
const int BASE = 64, maxn = 5e5 + 10;
int val[maxn][BASE], pos[maxn][BASE];
inline void insert(int i, int x)
{
    int k = i, tmp;
    for (int j = BASE - 1; j >= 0; --j)
        val[i][j] = val[i - 1][j], pos[i][j] = pos[i - 1][j];
    for (int j = BASE - 1; j >= 0; --j)
        if (x >> j)
        {
            if (!val[i][j])
            {
                val[i][j] = x;
                pos[i][j] = k;
                break;
            }
            else
            {
                if (k > pos[i][j])
                {
                    tmp = k, k = pos[i][j], pos[i][j] = tmp;
                    tmp = x, x = val[i][j], val[i][j] = tmp;
                }
                x ^= val[i][j];
            }
        }
}
inline void init()
{
    for (int i = 1; i <= n; ++i)
        for (int j = BASE - 1; j >= 0; --j)
            val[i][j] = pos[i][j] = 0;
}
inline int query(int l, int r)
{
    int ans = 0;
    for (int j = BASE - 1; j >= 0; --j)
        if ((ans ^ val[r][j]) > ans && pos[r][j] >= l)
            ans ^= val[r][j];
    return ans;
}