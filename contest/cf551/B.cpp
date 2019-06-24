#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int a[maxn][maxn];
int hf[maxn],hl[maxn];
int n,m,h;
int main(int argc, char const *argv[])
{
    cin >> n >> m >> h;
    for (int i = 1; i <= m;i++)
        cin >> hf[i];
    for (int i = 1; i <= n;i++)
        cin >> hl[i];
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            cin >> a[i][j];
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++){
            if (a[i][j]){
                a[i][j] = min(hl[i], hf[j]);
            }
        }
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++){
            cout << a[i][j] << " ";
            if (j==m)
                cout << "\n";
        }
            return 0;
}