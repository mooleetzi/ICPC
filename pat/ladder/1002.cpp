#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a[100];
int main(){
    ios::sync_with_stdio(false);
    int n=1,tot=1;
    a[1]=1;
    while(a[tot]<=1000){
        ++tot;
        ++n;
        a[tot]=a[tot-1]+4*n-2;
    }
    char p;
    cin>>n>>p;
    if (n<7){
        cout<<p<<"\n";
        cout<<n-1;
        return 0;
    }
    int num;
    for (int i=2;i<=tot;i++)
        if (a[i]>n&&a[i-1]<=n){
            num=i-1;
            break;
        }
    for (int i=0;i<num;i++){
        for (int j=0;j<i;j++)
            cout<<" ";
        for (int j=0;j<2*(num-i)-1;j++)
            cout<<p;
        cout<<"\n";
    }
    for (int i=1;i<num;i++){
        for (int j=0;j<num-i-1;j++)
            cout<<" ";
        for (int j=0;j<2*i+1;j++)
            cout<<p;
        cout<<"\n";
    }
    cout<<n-a[num];
    return 0;
}
