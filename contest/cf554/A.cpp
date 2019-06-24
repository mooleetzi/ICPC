#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
inline int read(){
    register int f = 1, ans = 0;
    char ch = getchar();
    while(!isdigit(ch)){
        if (ch=='-')
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
int main(int argc, char const *argv[])
{
    n = read(), m = read();
    int o1 = 0, e1 = 0, o2 = 0, e2 = 0;
    for (int i = 0; i < n;i++){
        int x = read();
        if (x&1)
            ++o1;
        else
        {
            ++e1;
        }
    }
    for (int i = 0; i < m;i++){
        int x = read();
        if (x & 1)
            ++o2;
        else
        {
            ++e2;
        }
    }
    cout << min(o1,e2)+min(e1 ,o2);
    return 0;
}
