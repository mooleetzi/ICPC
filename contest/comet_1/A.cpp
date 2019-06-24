#include<bits/stdc++.h>
using namespace std;
const int maxn = 30;
char a[maxn][maxn];
int n,m;
int judge(int r,int x,int y){
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            if (a[i][j]=='.'&&abs(x-i)+abs(y-j)>r)
                return 0;
    return 1;
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        /* code */
        cin >> n >> m;
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= m;j++)
                cin >> a[i][j];
        int flag = 1;
        for (int i = 0; i <= max(n, m) && flag; i++)
            for (int x = 1; x <= n;x++)
                for (int y = 1; y <= m;y++)
                    if (a[x][y]=='.'&&judge(i,x,y)){
                        cout << i << " " << x << " " << y << "\n";
                        flag = 0;
                    }
    }

    return 0;
}
