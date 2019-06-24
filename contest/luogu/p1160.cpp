#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
using iter = list<int>::iterator;
int inq[maxn];
inline int read(){
    register int f = 1, ans = 0;
    char ch = getchar();
    while(!isdigit(ch)){
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
iter pos[maxn];
int main()
{
    list<int> l;
    int n = read();
    l.push_back(1);
    inq[1] = 1;
    pos[1] = l.begin();
    for (int i = 2; i <= n; i++)
    {
        int k = read(), p = read();
        if (p)
        {
            auto po=next(pos[k]);
            pos[i]=l.insert(po, i);
            inq[i] = 1;
        }
        else
        {
            pos[i]=l.insert(pos[k], i);
            inq[i] = 1;
        }
    }
    int m = read();
    for (int i = 1; i <= m; i++)
    {
        int x = read();
        if (!inq[x])
            continue;
        l.erase(pos[x]);
        inq[x] = 0;
    }
    for (auto it=l.begin();it!=l.end();it++)
        printf("%d ", *it);
    return 0;
}