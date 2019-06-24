#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=5e5+10;
struct node{
    node *fail;
    node *next[180];
    int cnt,num;
    node(){
        fail=NULL;
        memset(this->next,NULL,sizeof this->next);
        cnt=num=0;
    }
}*q[maxn];
void insert(node *rt,char s[],int cnt){
    node *p=rt;
    int len=strlen(s);
    for (int i=0;i<len;i++){
        int cur=s[i]-31;
        if (p->next[cur]==NULL)
            p->next[cur]=new node();
        p=p->next[cur];
    }
    p->cnt++;
    p->num=cnt;
}
void build_ac_automation(node *root)        //      bfs½¨Á¢failÖ¸Õë
{
    int head,tail;
    head=tail=0;
    root->fail = NULL;
    q[tail++] = root;
    while(head < tail) {
        node *temp = q[head++];
        node *p = NULL;
        for(int i = 0; i < 128; i++) {
            if(temp->next[i] != NULL) {
                if(temp == root) temp->next[i]->fail = root;
                else {
                    p = temp->fail;
                    while(p != NULL) {
                        if(p->next[i] != NULL) {
                            temp->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if(p == NULL) temp->next[i]->fail = root;
                }
                q[tail++] = temp->next[i];
            }
        }
    }
}
int query(node *rt,char s[],int a[],int &tot){
    int len=strlen(s);
    node *p=rt;
    for (int i=0;i<len;i++){
        int cur=s[i]-31;
        while(p->next[cur]==NULL&&p!=rt)
            p=p->fail;
        p=p->next[cur];
        if (p==NULL)
            p=rt;
        node *tmp=p;
        while(tmp!=rt&&tmp->cnt!=-1){
            if (tmp->cnt)
                a[tot++]=tmp->num;
            //tmp->cnt=0;
            tmp=tmp->fail;
        }
    }
    if (tot)
        return 1;
    return 0;
}
int main(){
    int n,m,cnt=0;
    scanf("%d",&n);
    node *rt=new node();
    getchar();
    for (int i=1;i<=n;i++){
        char *s=new char[110];
        scanf("%s",s);
        insert(rt,s,i);
    }
    //getchar();
    build_ac_automation(rt);
    scanf("%d",&m);
    for (int i=1;i<=m;i++){
        char *s=new char[10010];
        scanf("%s",s);
        int a[n+1];
        int tot=0;
        memset(a,0,sizeof a);
        if (query(rt,s,a,tot)){
            ++cnt;
            printf("web %d: ",i);
            sort(a,a+tot);
            a[tot]=0x3f3f3f3f;
            for (int i=0;i<tot;i++)
                if(a[i]!=a[i+1])
                printf("%d ",a[i]);
            printf("\n");
        }
    }
    printf("total: %d\n",cnt);
    return 0;
}
