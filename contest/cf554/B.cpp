#include<bits/stdc++.h>
using namespace std;
int n;
map<int, int> vis;
const int maxn = 1 << 30;
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
int ans[100];
int p[50];
int judge(int now)
{
    for (int i = 0; i <= 31;i++)
        if (now==p[i])
            return 1;
    return 0;
}
int f = 0;
int tot = 0;
inline int getBit(int x){
    int pos = 0;
    int t = 1;
    while (x)
    {
        if ((x&1)==0)
            pos = t;
        x >>= 1;
        ++t;
    }
    return pos;
}
int main(int argc, char const *argv[])
{
    n = read();
    for (int i = 0; i <= 31;i++)
        p[i] = (1 << i) - 1;
    vector<int> ans;
    ans.clear();
    int num = 0;
    while (!judge(n))
    {
        int pos = getBit(n);
        if (!pos)
            break;
        ++num;
        ans.emplace_back(pos);
        n ^= (1<<pos)- 1;
        if (judge(n))
            break;
        ++n;
        ++num;
    }
    cout << num << "\n";
    for (int x:ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}
