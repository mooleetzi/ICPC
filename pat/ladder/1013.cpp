#include<iostream>
using namespace std;
int main(){
    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    int sum=1,pre=1;
    for (int i=2;i<=n;i++){
        sum+=pre*i;
        pre*=i;
    }
    cout<<sum;
    return 0;
}
