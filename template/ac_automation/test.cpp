#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <queue>
#include <map>
#include <stack>
using namespace std;
#define L(i) i<<1
#define R(i) i<<1|1
#define INF  0x3f3f3f3f
#define pi acos(-1.0)
#define eps 1e-3
#define maxn 2000010
#define MOD 100000007

char str[maxn],s[1010][55];
int num[1010];
struct node
{
    int count;
    struct node *next[26];
    struct node *fail;
    void init()
    {
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
        count = 0;
        fail = NULL;
    }
}*root;
void insert(int x)
{
    node *p = root;
    int len = strlen(str);
    for(int i = 0; i < len; i++)
    {
        int pos = str[i] - 'A';
        if(p->next[pos] == NULL)
        {
            p->next[pos] = new node;
            p->next[pos]->init();
            p = p->next[pos];
        }
        else
            p = p->next[pos];
    }
    p->count = x;
}
void getfail()
{
    node *p = root,*son,*temp;
    queue<struct node *> que;
    que.push(p);
    while(!que.empty())
    {
        temp = que.front();
        que.pop();
        for(int i = 0; i < 26; i++)
        {
            son = temp->next[i];
            if(son != NULL)
            {
                if(temp == root)
                    son->fail = root;
                else
                {
                    p = temp->fail;
                    while(p)
                    {
                        if(p->next[i])
                        {
                            son->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if(!p)
                        son->fail = root;
                }
                que.push(son);
            }
        }
    }
}
void query()
{
    int cnt = 0;
    int len = strlen(str);
    node *p = root,*temp;
    for(int i = 0; i < len; i++)
    {
        int pos = str[i] - 'A';
        if(pos < 0 || pos >= 26)
        {
            p = root;
            continue;
        }
        while(!p->next[pos] && p != root)
            p = p->fail;
        p = p->next[pos];
        if(!p)
            p = root;
        temp = p;
        while(temp != root)
        {
            if(temp->count > 0)
                num[temp->count]++;
            else
                break;
            temp = temp->fail;
        }
    }
}
int main()
{
    int T,n;
    //scanf("%d",&T);
    while(scanf("%d",&n) != EOF)
    {
        root = new node;
        root->init();
        root->fail = NULL;
        memset(num,0,sizeof(num));
        for(int i = 1; i <= n; i++)
        {
            scanf("%s",str);
            strcpy(s[i],str);
            insert(i);
        }
        getfail();
        scanf("%s",str);
        query();
        for(int i = 1; i <= n; i++)
            if(num[i])
                printf("%s: %d\n",s[i],num[i]);

    }
    return 0;
}
