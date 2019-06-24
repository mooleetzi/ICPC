#include <bits/stdc++.h>
#define gcd __gcd
using ll = long long;
using namespace std;
using pa = pair<int, int>;
const int maxn = 4e5 + 10;
vector<pa> v;
inline int read()
{
    register int f = 1, ans = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ans = (ans << 1) + (ans << 3) + ch - 48;
        ch = getchar();
    }
    return ans * f;
}
int n, m;
char s[110][110];
int judge(int x,int y){
    if (x+1>=n||x-1<0||y+1>=n||y-1<0)
        return 0;
    if (s[x][y+1]=='#'||s[x][y-1]=='#'||s[x-1][y]=='#'||s[x+1][y]=='#')
        return 0;
    return 1;
}
void put(int x,int y){
    s[x][y] = s[x + 1][y] = s[x - 1][y] = s[x][y + 1] = s[x][y - 1] = '#';
}
int main(int argc, char const *argv[])
{
    n = read();
    for (int i = 0; i < n;i++)
        scanf("%s", s[i]);
    for (int i = 0;i<n;i++)
        for (int j = 0; j < n;j++){
            if (s[i][j]=='.'&&judge(i,j)){
                put(i, j);
            }
        }
    for (int i = 0; i < n;i++)
        for (int j = 0; j < n;j++)
            if (s[i][j]=='.'){
                puts("NO");
                return 0;
            }
    puts("YES");
    return 0;
}
