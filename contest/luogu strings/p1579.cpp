#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
int p[3000];
int prime(int);
int main(){
    int n;
    scanf("%d",&n);
    int f1=1;
    for (int i=2;i<20000;i++)
        if (prime(i)&&f1)
            for (int j=i;j<20000;j++)
    if (prime(j)&&(n-i-j>0)&&prime(n-i-j)){
        cout<<i<<" "<<j<<" "<<n-i-j<<"\n";
        f1=0;
        break;
    }
    return 0;
}
int prime(int x){
    int m=sqrt(x);
    for (int i=2;i<=m;i++)
        if (x%i==0)
            return 0;
    return 1;
}
