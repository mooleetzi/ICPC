
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
            if(map[tmp.x][tmp.y]==-1)//�ҵ���ȫ�ش��˳�
                return tmp.t;
            if(tmp.t>=map[tmp.x][tmp.y])//����ĵ��ʱ����ڵ��ڱ��ٻ���ʱ�䶼����
                continue;
            map[tmp.x][tmp.y]=tmp.t;//�����ߵ��ĵ�Ķ�ʱ��
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
        memset(map,-1,sizeof(map));  //��ʼ��Ϊ-1
        while(m--){
            cin>>x>>y>>t;  //�����
            int tmpx,tmpy;
            for(int i=0;i<5;i++)
			{//������ͼ
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
