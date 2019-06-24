#include<bits/stdc++.h>
using namespace std;
int a[10];
int k;
int dis[10][10];
int d[10];
int ans[501];
void mul(int x){
    int z = 0;
    for (int i = 1; i < 500; i++)
    {
        ans[i] = ans[i]*x+z;
        z= ans[i] / 10;
        ans[i] %= 10;
    }
}
int main(int argc, char const *argv[])
{
    char ch = getchar();
    while(isdigit(ch)){
        int t = ch - 48;
        ++a[t];
        ch = getchar();
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int s, t;
        cin >> s >> t;
        dis[s][t] = 1;
    }
    for (int k = 1; k < 10;k++)
        for (int i = 0; i < 10;i++)
            for (int j = 1; j < 10;j++)
                if (dis[i][k]&&dis[k][j])
                    dis[i][j] = 1;
    for (int i = 0; i < 10;i++){
        dis[i][i] = 1;
        for (int j = 0; j < 10; j++)
            if(dis[i][j])
                ++d[i];
    }
    ans[1] = 1;
    for (int i = 0; i < 10;i++){
        if (a[i])
            mul(d[i]);
    }
    int j;
    for (int i = 500; i > 0;i--)
        if (ans[i]){
            j = i;
            break;
        }
    for (int i = j; i > 0;i--)
        cout << ans[i];
    cout << "\n";
    return 0;
}
