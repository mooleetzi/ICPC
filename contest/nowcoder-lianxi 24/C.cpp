#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int B[maxn],R[maxn];
int tb,tr;
int main(){
    char ch;
    int n,m,q;
    tb=0,tr=0;
    scanf("%d%d",&n,&m);
    memset(B,-1,sizeof B);
    memset(R,-1,sizeof R);
    getchar();
    for (int i=1;i<=n;i++){
        ch=getchar();
        if (ch=='R'){
            tr++;
            R[tr]=i;
        }
        else if (ch=='B'){
            tb++;
            B[tb]=i;
        }
    }
//    cout<<tb<<" "<<tr<<"\n";
//    for (int i=1;i<=tr;i++)
//        cout<<R[i]<<" ";
//    cout<<"\n";
//    for (int i=1;i<=tb;i++)
//        cout<<B[i]<<" ";
//    cout<<"\n";
    getchar();
    for (int i=1;i<=m;i++){
        ch=getchar();
        scanf("%d",&q);
        if (ch=='B')
            printf("%d\n",B[q]);
        else
            printf("%d\n",R[q]);
        getchar();
    }
    return 0;
}
