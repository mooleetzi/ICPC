#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
struct node{
    int h,y;
    node(){}
    node(int a,int b):h(a),y(b){}
    bool operator<(const node &a)const{
        return y<a.y;
    }
}info[5050];
int main(){
    int n,s,a,b;
    scanf("%d%d",&n,&s);
    scanf("%d%d",&a,&b);
    b+=a;
    for (int i=0;i<n;i++)
        scanf("%d%d",&info[i].h,&info[i].y);
    sort(info,info+n);
    int ans=0;
    for (int i=0;i<n;i++)
    if (s>=info[i].y&&b>=info[i].h){
        s-=info[i].y;
        ans++;
    }
    cout<<ans;
}
