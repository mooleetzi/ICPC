#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
char a[maxn][maxn];
int vis[maxn][maxn];
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
int c[10], d[10];
char s[] = " yizhong";
int n;
inline int isok(int i, int j)
{
    if (i < 0 || j < 0 || j == n || i == n)
        return 0;
    return 1;
}
void search(int i, int j, int tmp,int op)
{
    if (tmp >7)
    {
        for (int i = 1; i <= 7; i++)
            vis[c[i]][d[i]] = 1;
        return;
    }
    for (int x = 0; x < 8; x++)
    {
        int tx = i + dx[x];
        int ty = j + dy[x];
        if (isok(tx, ty)&&x==op&&a[tx][ty]==s[tmp])
        {
            c[tmp] = tx;
            d[tmp] = ty;
            search(tx, ty, tmp+1,op);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == s[1])
            {
                c[1] = i;
                d[1] = j;
                for (int k = 0; k < 8;k++){
                    int tx = i + dx[k];
                    int ty = j + dy[k];
                    if (isok(tx,ty)&&a[tx][ty]==s[2]){
                        c[2] = tx;
                        d[2] = ty;
                        search(tx, ty, 3, k);
                    }
                }
            }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (vis[i][j])
                putchar(a[i][j]);
            else
                putchar('*');
        putchar('\n');
    }
    return 0;
}