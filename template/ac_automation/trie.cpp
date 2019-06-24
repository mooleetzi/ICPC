#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=5e5+10;
struct node{
    node *fail;
    node *next[26];
    int cnt;
    node(){
        fail=NULL;
        memset(this->next,NULL,sizeof this->next);
        cnt=0;
    }
}*q[maxn];
void insert(node *rt,char s[]){
    node *p=rt;
    int len=strlen(s);
    for (int i=0;i<len;i++){
        int cur=s[i]-'a';
        if (p->next[cur]==NULL)
            p->next[cur]=new node();
        p=p->next[cur];
    }
    p->cnt++;
}
void build_ac_automation(node *rt){
    int head,tail=0;
    head=0,tail=1;
    q[head]=rt;
    node *p=NULL;
    while(head<tail){
        //cout<<"HEAD:"<<head<<" TAIL:"<<tail<<"\n";
        node *now=q[head++];
        for (int i=0;i<26;i++)
        if (now->next[i]!=NULL){
            if (now==rt)
                now->next[i]->fail=rt;
            else{
                p=now->fail;
                while(p!=NULL){
                    if (p->next[i]!=NULL){
                        now->next[i]->fail=p->next[i];
                        break;
                    }
                    p=p->fail;
                }
                if (p==NULL)
                    now->next[i]->fail=rt;
            }
            q[tail++]=now->next[i];
        }
    }
}
int query(node *rt,char s[]){
    int cnt=0;
    int len=strlen(s);
    node *p=rt;
    for (int i=0;i<len;i++){
        int cur=s[i]-'a';
        while(p->next[cur]==NULL&&p!=rt)
            p=p->fail;
        p=p->next[cur];
        if (p==NULL)
            p=rt;
        node *tmp=p;
        while(tmp!=rt&&tmp->cnt!=-1){
            cnt+=tmp->cnt;
            tmp->cnt=-1;
            tmp=tmp->fail;
        }
    }
    return cnt;
}
int main(){
    int n;
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        node *rt=new node();
        for (int i=0;i<n;i++){
            char *s=new char[60];
            cin>>s;
            insert(rt,s);
        }
        build_ac_automation(rt);
        char *t=new char[1000010];
        cin>>t;
        cout<<query(rt,t)<<"\n";
    }
}
