
#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int map[340][340];
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
struct nod{
    int x,y,t;
};
int bfs(){
    if(map[0][0]==0)
	return -1;
    if(map[0][0]==-1)
	return 0;
    nod tmp,now;
    tmp.x=tmp.y=tmp.t=0;
    queue<nod> Q;
    Q.push(tmp);
    while(!Q.empty()){
        now=Q.front();
        Q.pop();
        for(int i=1;i<5;i++){
            tmp.x=now.x+dx[i];
            tmp.y=now.y+dy[i];
            tmp.t=now.t+1;
            if(tmp.x<0||tmp.y<0||tmp.x>=350||tmp.y>=350)
                continue;
            if(map[tmp.x][tmp.y]==-1)//找到安全地带退出
                return tmp.t;
            if(tmp.t>=map[tmp.x][tmp.y])//到达改点的时间大于等于被毁坏的时间都不行
                continue;
            map[tmp.x][tmp.y]=tmp.t;//更新走到改点的短时间
            Q.push(tmp);
        }
    }
    return -1;
}
int main()
{
    int m,x,y,t;
    while(cin>>m)
	{
        memset(map,-1,sizeof(map));  //初始化为-1
        while(m--){
            cin>>x>>y>>t;  //输入点
            int tmpx,tmpy;
            for(int i=0;i<5;i++)
			{//构建地图
                tmpx=x+dx[i],tmpy=y+dy[i];
                if(tmpx<0||tmpx>=340||tmpy<0||tmpy>=340)
                    continue;
                if(map[tmpx][tmpy]==-1)
                    map[tmpx][tmpy]=t;
                else
                    map[tmpx][tmpy]=min(map[tmpx][tmpy],t);
            }
        }
        cout<<bfs()<<endl;
    }
}
