//1.单点更新，区间查询

int tree[N][N]; //行列分开看，每一行每一列都是一个一维树状数组
int n, m;       //n行m列

int lowbit(int x) { return x & (-x); }
//单点更新,区间查询
void add(int x, int y, int val)
{ //单点更新
    while (x <= n)
    {
        for (int i = y; i <= m; i += lowbit(i))
        { //列的一维树状数组
            tree[x][i] += val;
        }
        x += lowbit(x);
    }
}
int sum(int x, int y)
{ //返回(0,0,),(x,y)为对角顶点的矩阵和
    int res = 0;
    while (x > 0)
    {
        for (int i = y; i > 0; i -= lowbit(i))
        {
            res += tree[x][i];
        }
        x -= lowbit(x);
    }
    return res;
}
int query(int x1, int y1, int x2, int y2)
{                                                                         //区间查询
    return sum(x2, y2) + sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2); //容斥,注意是否可能超longlong
}

//2.区间更新，单点查询
//区间修改,单点查询,和一维树状数组差分思想一样,差分思想。
//二维前缀和：
//sum[i][j]=sum[i−1][j]+sum[i][j−1]−sum[i−1][j−1]+a[i][j]
//那么我们可以令差分数组d[i][j] 表示 a[i][j] 与 a[i−1][j]+a[i][j−1]−a[i−1][j−1] 的差。

void regionUpdate(int x1, int y1, int x2, int y2, int val)
{
    add(x1, y1, val);
    add(x2 + 1, y1, -val);
    add(x1, y2 + 1, -val);
    add(x2 + 1, y2 + 1, val);
}
int pointQuery(int x, int y)
{
    return sum(x, y);
}