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
int a[26];
inline int getNum(char c){
    return c - 'a';
}
set<char> ss;
stack<char> s[4];
int main(int argc, char const *argv[])
{
    n = read(), m = read();
    for (int i = 0; i < n;i++){
        char ch = getchar();
        ++a[getNum(ch)];
        ss.insert(ch);
    }
    getchar();
    while(m--){
        char op=getchar();
        getchar();
        int d=getchar()-'0';
        getchar();
        if (op == '+')
        {
            char c=getchar();
            getchar();
            if (!ss.count(c))
            {
                s[d].push(c);
                puts("NO");
                continue;
            }
            --a[getNum(c)];
            s[d].push(c);
            int f = 1;
            for (int i = 0; i < 26; i++)
                if (a[i]<0){
                    puts("NO");
                    f = 0;
                    break;
                }
            if (f)
                puts("YES");
        }
        else{
            char c = s[d].top();
            s[d].pop();
            if (ss.count(c))
                ++a[getNum(c)];
            int f = 1;
            for (int i = 0; i < 26; i++)
                if (a[i]<0){
                    puts("NO");
                    f = 0;
                    break;
                }
            if (f)
                puts("YES");
        }
    }
    return 0;
}
