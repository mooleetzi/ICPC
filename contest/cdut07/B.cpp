#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<map>
#include<queue>
#define maxn 1010
using namespace std;
void bfs();
void swap(char& a,char &b){
    char c=a;
    a=b;
    b=c;
}
map<string,int> d;
int main(){
    bfs();
    string now;
    while(getline(cin,now)){
        for (int i=1;i<now.length();i++)
            if (now[i]==' ')
                now=now.erase(i,1);
        printf("%d\n",d[now]);
    }
    return 0;
}
void bfs(){
    d["01234567"]=0;
    queue<string> que;
    que.push("01234567");
    while(!que.empty()){
        string now=que.front();
        que.pop();
        int u;
        for (int i=0;i<now.length();i++)
            if (now[i]=='0'){
                u=i;
                break;
            }
        if (u>0&&u<3){
            string next=now;
            swap(next[u],next[u+1]);
            if (d.find(next)==d.end()){
                d[next]=d[now]+1;
                que.push(next);
            }
            next=now;
            swap(next[u],next[u-1]);
            if (d.find(next)==d.end()){
                d[next]=d[now]+1;
                que.push(next);
            }
            next=now;
            swap(next[u],next[u+4]);
            if (d.find(next)==d.end()){
                d[next]=d[now]+1;
                que.push(next);
            }
        }
        else if (u==0){
            string next=now;
            swap(next[u],next[u+1]);
            if (d.find(next)==d.end()){
                d[next]=d[now]+1;
                que.push(next);
            }
            next=now;
            swap(next[u],next[u+4]);
            if (d.find(next)==d.end()){
                d[next]=d[now]+1;
                que.push(next);
            }
        }
        else if (u==3){
            string next=now;
            swap(next[u],next[u-1]);
            if (d.find(next)==d.end()){
                d[next]=d[now]+1;
                que.push(next);
            }
            next=now;
            swap(next[u],next[u+4]);
            if (d.find(next)==d.end()){
                d[next]=d[now]+1;
                que.push(next);
            }
        }
        else if (u==4){
            string next=now;
            swap(next[u],next[u+1]);
            if (d.find(next)==d.end()){
                d[next]=d[now]+1;
                que.push(next);
            }
            next=now;
            swap(next[u],next[u-4]);
            if (d.find(next)==d.end()){
                d[next]=d[now]+1;
                que.push(next);
            }
        }
        else if (u==7){
            string next=now;
            swap(next[u],next[u-4]);
            if (d.find(next)==d.end()){
                d[next]=d[now]+1;
                que.push(next);
            }
            next=now;
            swap(next[u],next[u-1]);
            if (!d[next]){
                d[next]=d[now]+1;
                que.push(next);
            }
        }
        else if (u>4&&u<7){
            string next=now;
            swap(next[u],next[u-1]);
            if (d.find(next)==d.end()){
                d[next]=d[now]+1;
                que.push(next);
            }
            next=now;
            swap(next[u],next[u-4]);
            if (d.find(next)==d.end()){
                d[next]=d[now]+1;
                que.push(next);
            }
            next=now;
            swap(next[u],next[u+1]);
            if (d.find(next)==d.end()){
                d[next]=d[now]+1;
                que.push(next);
            }
        }
    }
}
