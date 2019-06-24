#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
inline T read()
{
    T ans = 0;
    register T f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ans = (ans << 3) + (ans << 1) + ch - 48;
        ch = getchar();
    }
    return ans * f;
}
inline int isopt(char a)
{
    if (a == '+' || a == '-' || a == '*' || a == '/')
        return 1;
    return 0;
}
ll getAns(ll o1, char c, ll o2)
{
    if (c == '+')
        return o1 + o2;
    else if (c == '-')
        return o1 - o2;
    else if (c == '*')
        return o1 * o2;
    else
        return o1 / o2;
}
int main()
{
    char ch = getchar();
    stack<ll> data;
    ll tmp = 0;
    while (ch != '@')
    {
        if (ch=='.'){
            data.push(tmp);
            tmp = 0;
        }
        if (isopt(ch)){
            int o2 = data.top();
            data.pop();
            int o1 = data.top();
            data.pop();
            data.push(getAns(o1, ch, o2));
        }
        if (isdigit(ch))
            tmp = (tmp << 1) + (tmp << 3) + ch - 48;
        ch = getchar();
    }
    printf("%lld", data.top());
}