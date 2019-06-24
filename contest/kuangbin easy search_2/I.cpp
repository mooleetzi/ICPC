#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int dy[]={0,1,0,-1};
const int dz[]={1,0,-1,0};
char ma[2][12][12];
int m,n,t;
struct node{
    int x,y,z,w;
    node(){}
    node(int x,int y,int z,int w){
        this->x=x;
        this->y=y;
        this->z=z;
        this->w=w;
    }
};
int check(int x,int y,int z){
    if (y>=m||y<0||z>=n||z<0||ma[x][y][z]=='*')
        return 0;
    return 1;
}
void bfs(){
    queue<node> que;
    que.push(node(0,0,0,0));
    ma[0][0][0]='*';
    while(!que.empty()){
        node now=que.front();
        que.pop();
        if (now.w>=t){
            printf("NO\n");
            return;
        }
        for (int i=0;i<4;i++){
            int x=now.x;
            int y=now.y+dy[i];
            int z=now.z+dz[i];
            if (!check(x,y,z))
                continue;
            if (ma[x][y][z]=='#'){
                if (ma[!x][y][z]=='#'||ma[!x][y][z]=='*'){
                    ma[x][y][z]='*';
                    ma[!x][y][z]='*';
                }
                else{
                    if (ma[!x][y][z]=='P'){
                        printf("YES\n");
                        return;
                    }
                    ma[x][y][z]='*';
                    ma[!x][y][z]='*';
                    que.push(node(!x,y,z,now.w+1));
                }
            }
            else{
                if (ma[x][y][z]=='P'){
                    printf("YES\n");
                    return;
                }
                ma[x][y][z]='*';
                que.push(node(x,y,z,now.w+1));
            }
        }
    }
    printf("NO\n");
}
int main(){
    int T;
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        cin>>m>>n>>t;
        for (int i=0;i<2;i++)
            for (int j=0;j<m;j++)
                cin>>ma[i][j];
        bfs();
    }
    return 0;
}
