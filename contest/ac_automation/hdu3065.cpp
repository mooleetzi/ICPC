#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn=2000010;
struct node{
    node *fail;
    node *next[26];
    int num,wd;
    node(){
        fail=NULL;
        memset(next,NULL,sizeof next);
        num=wd=0;
    }
};
struct ans{
    char s[55];
    int num;
    int index;
    ans(){}
    ans(char s[],int num,int index){
        strcpy(this->s,s);
        this->num=num;
        this->index=index;
    }
}q[1001];
char p[1001][50];
node *rt;
int num[1001];
void insert(char s[],int i){
    int len=strlen(s);
    //cout<<s<<"\n";
    node *tmp=rt;
    for (int i=0;i<len;i++){
        int cur=s[i]-'A';
        if (tmp->next[cur]==NULL)
            tmp->next[cur]=new node();
        tmp=tmp->next[cur];
    }
    tmp->wd=i;
}
void build_ac_automation(){
    queue<node *> que;
    que.push(rt);
    node *tmp=NULL;
    while(!que.empty()){
        node *now=que.front();
        que.pop();
        for (int i=0;i<26;i++){
            if (now->next[i]!=NULL){
                if (now==rt)
                    now->next[i]->fail=rt;
                else{
                    tmp=now->fail;
                    while(tmp){
                        if (tmp->next[i]){
                            now->next[i]->fail=tmp->next[i];
                            break;
                        }
                        tmp=tmp->fail;
                    }
                    if (tmp==NULL)
                        now->next[i]->fail=rt;
                }
                que.push(now->next[i]);
            }
        }
    }
}
void search(char s[]){
    int len=strlen(s);
    int tot=0;
    node *tmp=rt;
    for (int i=0;i<len;i++){
        int cur=s[i]-'A';
        if (cur<0||cur>25){
            tmp=rt;
            continue;
        }
        while(!tmp->next[cur] && tmp!= rt) tmp = tmp->fail;
        tmp = tmp->next[cur];
        if(!tmp) tmp = rt;
        node *temp = tmp;
        while(temp != rt)
        {
           if(temp->wd)
           {
               num[temp->wd]++;
           }
           else break;
           temp = temp->fail;
        }
    }
}
int main(){
    int n;
    ios::sync_with_stdio(false);
    while(cin>>n){
        rt=new node();
    for (int i=1;i<=n;i++){
        char *s=new char[55];
        cin>>s;
        strcpy(p[i],s);
        insert(s,i);
    }
    build_ac_automation();
    char *ma=new char[maxn];
    cin>>ma;
    memset(num,0,sizeof num);
    search(ma);
    for (int i=1;i<=n;i++)
        if (num[i])
            cout<<p[i]<<": "<<num[i]<<"\n";
    }
    return 0;
}
