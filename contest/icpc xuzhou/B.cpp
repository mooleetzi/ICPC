#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e3+10;
struct node{
    int a,b,c;
    node(){}
    node(int a,int b,int c){
        this->a=a;
        this->b=b;
        this->c=c;
    }
}ask[maxn];
int n,score,h,l;
int main(){
    scanf("%d%d%d%d",&n,&score,&h,&l);
    for (int i=1;i<=n;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        ask[i]=node(a,b,c);
    }
    for (int i=1;i<=n;i++){
        node now=ask[i];
        if (i&1){
            if (now.a==0&&now.b==0)
                score=-score;
            else if (now.a==0&&now.c==0)
                score-=now.b;
            else if (now.b==0&&now.c==0)
                score+=now.a;
            else if (now.a==0){
                if (ask[i+1].c==0)
                    score=max(score-now.b,-score);
                else
                    score=min(score-now.b,-score);
            }
            else if (now.b==0){
                if (ask[i+1].c==0)
                    score=max(score+now.a,-score);
                else
                    score=min(score+now.a,-score);
            }
            else if (now.c==0){
                if (ask[i+1].c==0)
                    score+=now.a;
                else
                    score-=now.b;
            }
            else{
                if (ask[i+1].c==0)
                    score=max(score+now.a,-score);
                else
                    score=min(score-now.b,-score);
            }
        }
        else{
            if (now.a==0&&now.b==0)
                score=-score;
            else if (now.a==0&&now.c==0)
                score-=now.b;
            else if (now.b==0&&now.c==0)
                score+=now.a;
            else if (now.a==0){
                if (ask[i+1].c==0)
                    score=min(score-now.b,-score);
                else
                    score=max(score-now.b,-score);
            }
            else if (now.b==0){
                if (ask[i+1].c==0)
                    score=min(score+now.a,-score);
                else
                    score=max(score+now.a,-score);
            }
            else if (now.c==0){
                if (ask[i+1].c==0)
                    score-=now.b;
                else
                    score+=now.a;
            }
            else{
                if (ask[i+1].c==0)
                    score=min(-score,score-now.b);
                else
                    score=max(-score,score+now.a);
            }
        }
        if (score>100)
            score=100;
        if (score<-100)
            score=-100;
    }
    printf("%d\n",score);
    if (score>=h)
        printf("Good Ending");
    else if (score<=l)
        printf("Bad Ending");
    else
        printf("Normal Ending");
    return 0;
}
