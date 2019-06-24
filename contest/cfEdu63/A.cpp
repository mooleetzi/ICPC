#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
inline int read(){
    char ch = getchar();
    register int f = 1, ans = 0;
    while (!isdigit (ch))
    {
        if (ch=='-')
            f = -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        ans = (ans << 1) + (ans << 3) + ch - 48;
        ch = getchar();
    }
    return ans * f;
}
int n;
int main(int argc, char const *argv[])
{
    n = read();
    int flag = 0;
    int l = 0, r = 0;
    char pre = 'a' - 1;
    for (int i = 0; i < n; i++)
    {
        char ch = getchar();
        if (flag)
            continue;
        if (pre > ch)
        {
            flag = 1;
            r = i + 1;
        }
        else
        {

            pre = ch;
            l = i + 1;
        }
    }
    if (flag){
        puts("YES");
        printf("%d %d\n", l, r);
    }
    else
    {
        puts("NO");
    }

    return 0;
}
