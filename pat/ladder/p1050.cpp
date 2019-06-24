#include<iostream>
#include<algorithm>
using namespace std;
int a[7];
int main(){
    int s=1;
    for (int i=1;i<=6;i++){
        s*=26;
        a[i]=s;
    }
    int l,n;
    cin>>l>>n;
    int ind=a[l]-n+1;
    cout<<ind<<"\n";
    return 0;
}
