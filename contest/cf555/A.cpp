#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
inline int read(){
    register int f = 1, ans = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
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
int n,m;
set<int> s;
int main(int argc, char const *argv[])
{
    n = read();
    while(!s.count(n)){
        s.insert(n);
        ++n;
        while(n%10==0)
            n /= 10;
    }
    cout << s.size();
    return 0;
}
