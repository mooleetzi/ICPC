#include<iostream>
using namespace std;
int a[10];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    a[0]=1;
    for (int i=1;i<=6;i++){
        a[i]=a[i-1]*26;
    }

}
