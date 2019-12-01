
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char s[N];
int vis[21], sta[1 << 20], mx[N];
int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%s", s);
    int n = strlen(s);

    for (int i = 0; i < n; ++i)
    { //预处理出所以无重复字母子串
        memset(vis, 0, sizeof vis);
        int cnt = 0, tmp = 0;
        for (int j = i; j < n; ++j)
        { //最多二十位
            if (vis[s[j] - 'a'])
                break;
            else
            {
                tmp |= (1 << (s[j] - 'a'));
                vis[s[j] - 'a'] = 1;
                sta[tmp] = ++cnt;
            }
        }
    }

    int m = (1 << 20) - 1;

    for (int i = 0; i <= m; ++i)
        for (int j = 0; j < 20; ++j)
            if (i & (1 << j))
                sta[i] = max(sta[i], sta[i ^ (1 << j)]); //枚举这个集合的最大子集

    int ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        int tmp = m ^ i;
        ans = max(ans, sta[i] + sta[tmp]); //子集 + 补集
    }
    printf("%d\n", ans);
    for (int i = 1; i <= (1<<3)-1;i++)
        cout << i << " " << sta[i] << " "<<(m ^ i) << " " << sta[m ^ i] << "\n";
}