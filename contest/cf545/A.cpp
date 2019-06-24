#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;

inline int read()
{
    register int tmp = 0, f = 1;
    char ch = getchar();
    if (ch == '-')
    {
        ch = getchar();
        f = -1;
    }
    while (ch >= '0' && ch <= '9')
    {
        tmp = tmp * 10 + ch - '0';
        ch = getchar();
    }
    return tmp * f;
}
int n, m;
int a[maxn], ans;
int main(int argc, char const *argv[])
{
    n = read();
    for (int i = 1; i <= n;i++)
        a[i] = read();
    int first = a[1], preCnt = 1,nextCnt=0;
    for (int i = 2; i <= n;i++){
        if (a[i]==first&&!nextCnt)
            ++preCnt;
        else if (a[i]==first&&nextCnt)
        {
            preCnt = nextCnt;
            nextCnt = 0;
            first = a[i - 1];
            --i;
        }
        else if (a[i]!=first)
        {
            ++nextCnt;
        }
        ans = max(ans, 2 * min(nextCnt, preCnt));
    }
    cout << ans;
    return 0;
}
