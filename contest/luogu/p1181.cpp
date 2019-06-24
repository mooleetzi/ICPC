#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
    x=0;
    register int f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    x*=f;
}
int main(){
    int n,m,ans=1,tmp=0;
    read(n);read(m);
    for (int i=0;i<n;i++){
        int x;
        read(x);
        if (tmp+x<=m)
            tmp+=x;
        else{
            tmp=x;
            ++ans;
        }
    }
    printf("%d",ans);
    return 0;
}
