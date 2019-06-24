#include<bits/stdc++.h>
using namespace std;
const int maxn=150000+3;
void read(int &x){
    char ch = getchar();x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >='0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}

int main()
{
    int n,m,opt,u,v,w,val;
    while(~scanf("%d%d",&n,&m))
    {
    deque<int>p[n+2];
    while(m--)
    {
        read(opt);
        if(opt==1)
        {
            read(u);read(w);read(val);
            if(w==1)
            {
                p[u].push_back(val);
            }
            else
            {
                p[u].push_front(val);
            }
        }
        else if(opt==2)
        {
            read(u);read(w);
            if(p[u].empty())
                puts("-1");
            else
            {
                if(w==1)
                {
                    printf("%d\n",p[u].back());
                    p[u].pop_back();
                }
                else
                {
                    printf("%d\n",p[u].front());
                    p[u].pop_front();
                }
            }
        }
        else if(opt==3)
        {
           read(u);read(v);read(w);
           if(w==0)
           {
                deque<int>::iterator it;
                for(it=p[v].begin();it!=p[v].end();it++)
                    p[u].push_back(*it);
           }
           else
           {
                deque<int>::reverse_iterator it;
                for(it=p[v].rbegin();it!=p[v].rend();it++)
                    p[u].push_back(*it);
           }
           p[v].clear();
        }
    }
    }
    return 0;
}

