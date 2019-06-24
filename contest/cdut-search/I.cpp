#include<iostream>
#include<cstring>
#include<queue>
#define rep(i,x,y) for (int i=x;i<y;i++)
#define mt(a,x) memset(a,x,sizeof a)
using namespace std;
struct node{
    int x1,y1,x2,y2,step;
    node(){}
    node(int x,int y,int z,int w,int t){
        x1=x;y1=y;x2=z;y2=w;
    }
};
