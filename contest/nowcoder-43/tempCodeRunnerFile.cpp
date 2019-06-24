#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
inline ll read()
{
    register ll f = 1 ;
    
    ll ans = 0;
    char ch = getchar();
    while(!isdigit(ch)){
        if (ch=='-')
            f = -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        ans = (ans << 3) + (ans << 1) + ch - 48;
        ch = getchar();
    }
    return ans * f;
}
map<int,int> s;
vector<int> q;
int main()
{
    ll t = read();
    while(t--){
        ll a, b, l, r;
        int len = 0;
        s.clear();
        q.clear();
        q.emplace_back(-1);
        a = read(), b = read(), l = read(), r = read();
        int flag = 0;
        for (int i = 1; i <=r; i++)
        {
            a = (a << 3) + (a << 1);
            int now = a / b;
            a = a % b;
            q.emplace_back(now);
            if (s[a]||!a)
            {
                len = i - s[a];
                flag = s[a];
                if (!a)
                    flag = -1;
                break;
            }
            s[a] = i;
        }
        // cout << q.size() - 1 << "\n";
        if (flag)
        {
            if (flag>0)
            for (int i = l; i <= r;i++)
                if (i>=flag)
                    printf("%d", q[flag+ (i - flag) % (len)]);
                else
                {
                    printf("%d", q[i]);
                }
            else
            {
                for (int i = l; i <= r;i++)
                    if (i<q.size())
                        printf("%d", q[i]);
                    else
                    {
                        printf("0");
                    }
            }
        }
        else
        {
            for (int i = l; i <=r;i++)
                printf("%d", q[i]);
        }
        printf("\n");
    }
    return 0;
}