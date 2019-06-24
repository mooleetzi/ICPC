#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[11];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        a[i]=i;
    do{
        int t=n-1;
        int b[11];
        for (int i=1;i<=n;i++)
            b[i]=a[i];
        while(t){
            for (int i=1;i<=t;i++)
                b[i]=b[i]+b[i+1];
            t--;
        }
        if (b[1]==m){
            for (int i=1;i<n;i++)
                cout<<a[i]<<" ";
            cout<<a[n]<<"\n";
            break;
        }
    }while(next_permutation(a+1,a+n+1));
    return 0;
}
