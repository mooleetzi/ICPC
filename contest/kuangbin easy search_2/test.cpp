#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    freopen("test.in","r",stdin);
    freopen("test.txt","w",stdout);
    int a[4][7];
    for (int i=0;i<4;i++)
        for (int j=0;j<7;j++)
            cin>>a[i][j];
    for (int i=0;i<4;i++)
        for (int j=0;j<7;j++)
            printf("%d%c",a[i][j],j==6?'\n':',');
}
